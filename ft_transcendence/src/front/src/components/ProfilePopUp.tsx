import axios from 'axios';
import { ChangeEvent, createRef, FormEvent, useEffect, useState } from 'react';
import { useNavigate } from 'react-router-dom';
import { User } from '../models/User.interface';
import '../styles/ProfilePopUp.css';

interface Props {
  show: boolean;
  user: User;
  onClose: () => void;
  updateState: (user: User) => void;
}

interface UpdateUser {
  id: number;
  avatar: string;
  username: string;
  two_fa_auth: boolean;
  file: React.RefObject<HTMLInputElement>;
  auth_code: string;
}

export default function ProfilePopUp({
  onClose,
  show,
  user,
  updateState,
}: Props) {
  const [valid, setValid] = useState({
    username: true,
    auth_code: true,
  });
  const [qrCode, setQrCode] = useState<string>('');
  const [editUsername, setEditUsername] = useState(false);
  const [updatedUser, setUpdatedUser] = useState<UpdateUser>({
    id: 0,
    avatar: '',
    username: '',
    two_fa_auth: false,
    file: createRef(),
    auth_code: '',
  });
  const navigate = useNavigate();

  const closeHandler = () => {
    updatedUser.file.current!.value = '';
    setUpdatedUser({
      ...user,
      file: createRef(),
      auth_code: '',
    });
    setEditUsername(false);
    setQrCode('');
    onClose();
  };

  function onSelectFile(e: ChangeEvent<HTMLInputElement>) {
    if (!e.target.files || e.target.files.length === 0) return;
    const url = URL.createObjectURL(e.target.files[0]);
    setUpdatedUser((prevUser) => ({
      ...prevUser,
      avatar: url,
    }));
  }

  async function updateSwitch(e: ChangeEvent<HTMLInputElement>) {
    const { checked } = e.target;
    if (checked && !user.two_fa_auth) {
      const res = await axios.post(
        `/api/generate`,
        {
          id: updatedUser.id,
          avatar: updatedUser.avatar,
          username: updatedUser.username,
          two_fa_auth: updatedUser.two_fa_auth,
        },
        { responseType: 'blob' }
      );
      const url = URL.createObjectURL(res.data);
      setQrCode(url);
      setUpdatedUser((prevUser) => ({
        ...prevUser,
        auth_code: '',
      }));
    }
    if (!checked) setQrCode('');
    setUpdatedUser((prevUser) => ({
      ...prevUser,
      two_fa_auth: checked,
    }));
  }

  useEffect(() => {
    setUpdatedUser((prevUser) => ({
      ...prevUser,
      ...user,
    }));
  }, [user]);

  async function validateInput(): Promise<boolean> {
    if (updatedUser.username !== user.username) {
      const { data } = await axios
        .get(`/api/users/username/${updatedUser.username}`)
        .catch(() => {
          return { data: null };
        });
      if (!data) {
        navigate('/signin');
        return false;
      }
      if (data.id) {
        setValid((prevValid) => ({
          ...prevValid,
          username: false,
        }));
        setEditUsername(true);
        return false;
      }
    }
    if (updatedUser.two_fa_auth && !user.two_fa_auth) {
      try {
        axios.post(
          `/api/turn2fa`,
          { twoFaAuthCode: updatedUser.auth_code },
          { withCredentials: true }
        );
      } catch (error) {
        setValid((prevValid) => ({
          ...prevValid,
          auth_code: false,
        }));
        return false;
      }
    }
    return true;
  }

  async function applyChanges(e: FormEvent<HTMLFormElement>) {
    e.preventDefault();

    if (!(await validateInput())) return;
    let upload_url;
    if (updatedUser.file.current!.files!.length > 0) {
      const formData = new FormData();
      formData.append('to_upload', updatedUser.file.current!.files![0]);
      upload_url = await axios.post(`/api/users/image`, formData, {
        withCredentials: true,
      });
    }
    updateState({
      id: updatedUser.id,
      avatar: upload_url ? upload_url.data.url : updatedUser.avatar,
      username: updatedUser.username,
      two_fa_auth: updatedUser.two_fa_auth,
    });
    updatedUser.file.current!.value = '';
    setQrCode('');
    onClose();
  }

  function inputChecker(e: ChangeEvent<HTMLInputElement>) {
    const { name, value } = e.target;

    if (name === 'auth_code') {
      if (!valid.auth_code)
        setValid((prevValid) => ({
          ...prevValid,
          auth_code: true,
        }));
      const re = /^[0-9\b]+$/;
      if (value === '' || re.test(value))
        setUpdatedUser((prevUser) => ({
          ...prevUser,
          auth_code: value,
        }));
    }
    if (name === 'username') {
      if (!valid.username)
        setValid((prevValid) => ({
          ...prevValid,
          username: true,
        }));
      const re = /^[a-zA-Z0-9-_]{0,20}$/;
      if (re.test(value))
        setUpdatedUser((prevUser) => ({
          ...prevUser,
          username: value,
        }));
    }
  }

  const isChanged = (): boolean | undefined => {
    return !(
      updatedUser?.avatar !== user?.avatar ||
      updatedUser?.two_fa_auth !== user?.two_fa_auth ||
      updatedUser?.username !== user?.username
    );
  };

  return (
    <div className="popup">
      <div className="content">
        <div
          className="popup--image--container"
          style={{
            position: 'relative',
            height: '150px',
            width: '150px',
            display: 'flex',
          }}
        >
          <div
            className="image-upload"
            style={{
              position: 'absolute',
              width: '100%',
              height: '100%',
              zIndex: 1,
              backgroundColor: 'rgba(255,255,255,0.5)',
              borderRadius: '50%',
              alignItems: 'center',
              justifyContent: 'center',
            }}
          >
            <label htmlFor="file-input">
              <i className="bi bi-cloud-arrow-up popup--icon" />
            </label>
            <input
              id="file-input"
              type="file"
              accept="image/*"
              ref={updatedUser.file}
              onChange={onSelectFile}
            />
          </div>
          <img
            src={updatedUser?.avatar}
            className="popup--image"
            style={{ position: 'absolute' }}
            alt="user avatar"
          />
        </div>

        <form className="container" onSubmit={applyChanges}>
          <div
            className="column justify-content-center"
            style={{ width: '100%' }}
          >
            {editUsername ? (
              <div
                style={{
                  display: 'flex',
                  width: '100%',
                  flexWrap: 'nowrap',
                  alignItems: 'center',
                  justifyContent: 'center',
                  gap: '1rem',
                }}
              >
                <div className="col-4">
                  <div className="input-group has-validation">
                    <input
                      id="username"
                      name="username"
                      type="text"
                      className={`form-control ${
                        !valid.username ? 'is-invalid' : ''
                      }`}
                      style={{}}
                      onChange={(e) => inputChecker(e)}
                      value={updatedUser?.username}
                      required
                    />
                    <div
                      style={{ fontSize: '1rem' }}
                      className="invalid-feedback"
                    >
                      this username was taken
                    </div>
                  </div>
                </div>
                <div className="col-2">
                  {/^.{3,}$/.test(updatedUser?.username) && valid.username && (
                    <i
                      className="bi bi-check popup--form--icon"
                      style={{ fontSize: '2rem' }}
                      onClick={() => setEditUsername(false)}
                    />
                  )}
                </div>
              </div>
            ) : (
              <>
                <div
                  style={{
                    display: 'flex',
                    width: '100%',
                    flexWrap: 'nowrap',
                    alignItems: 'center',
                    justifyContent: 'center',
                    gap: '1rem',
                  }}
                >
                  <span className="form-text" style={{ color: 'white' }}>
                    {updatedUser?.username}
                  </span>
                  <i
                    className="bi bi-pencil popup--form--icon"
                    onClick={() => setEditUsername(true)}
                  />
                </div>
              </>
            )}
          </div>
          <div
            className="row justify-content-center"
            style={{
              marginTop: '10px',
              marginBottom: '10px',
              alignItems: 'center',
              justifyContent: 'center',
            }}
          >
            <div>
              <span className="form-label">2FA </span>
              <div className="form-check form-switch form-check-inline">
                <input
                  name="two_fa_auth"
                  className="form-check-input"
                  type="checkbox"
                  onChange={(e) => updateSwitch(e)}
                  checked={updatedUser!.two_fa_auth}
                />
              </div>
            </div>
          </div>
          {qrCode && (
            <>
              <div className="row">
                <div className="col">
                  <img src={qrCode} alt="qr code" />
                </div>
              </div>
              <div className="row" style={{ justifyContent: 'center' }}>
                <div className="col-5">
                  <input
                    name="auth_code"
                    placeholder="000000"
                    style={{ textAlign: 'center' }}
                    className={`form-control ${
                      !valid.auth_code ? 'is-invalid' : ''
                    }`}
                    type="text"
                    onChange={(e) => inputChecker(e)}
                    value={updatedUser?.auth_code}
                  />
                  <div
                    style={{ fontSize: '1rem' }}
                    className="invalid-feedback"
                  >
                    wrong code
                  </div>
                </div>
              </div>
            </>
          )}
          <div className="row">
            <div className="col">
              <button
                className="btn btn-outline-success"
                disabled={
                  isChanged() ||
                  editUsername ||
                  (updatedUser?.auth_code === '' && qrCode !== '') ||
                  !valid.auth_code
                }
              >
                Apply
              </button>
            </div>
            <div className="col">
              <button
                type="button"
                className="btn btn-outline-danger"
                onClick={closeHandler}
              >
                Cancel
              </button>
            </div>
          </div>
        </form>
      </div>
    </div>
  );
}
