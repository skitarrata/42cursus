import { useState, useEffect, ChangeEvent } from 'react';
import { Navigate, useLocation, useNavigate } from 'react-router';
import '../styles/TwoFaAuth.css';
import axios from 'axios';
import memoji from '../assets/image.png';

export default function TwoFaAuth() {
  const [code, setCode] = useState('');
  const [invalidCode, setInvalidCode] = useState(false);
  const [authed, setAuthed] = useState(false);

  const location = useLocation();
  const from: any = location.state;
  const navigate = useNavigate();

  useEffect(() => {
    async function getAuth() {
      const res = await fetch(`/api/user`, { credentials: 'include' });
      const data = await res.json();
      if (!data.two_fa) {
        navigate(-1);
      } else {
        setAuthed(false);
      }
    }
    getAuth();
    // eslint-disable-next-line react-hooks/exhaustive-deps
  }, []);

  async function handleSubmit() {
    try {
      const res = await axios.post(
        `/api/auth2fa`,
        {
          twoFaAuthCode: code,
        },
        { withCredentials: true }
      );
      setAuthed(res.data);
      setInvalidCode(!res.data);
    } catch (error) {
      console.log(error);
      setAuthed(false);
      setInvalidCode(true);
    }
  }

  function updateCode(e: ChangeEvent<HTMLInputElement>) {
    const { value } = e.target;
    const re = /^[0-9\b]{0,6}$/;
    if (re.test(value)) {
      setCode(value);
      setInvalidCode(false);
    }
  }

  return (
    <>
      {authed && <Navigate to={from.from.pathname} />}
      {!authed && (
        <div className="container-fluid vh-100 d-flex align-items-center justify-content-center">
          <div className="row">
            <div className="col-12" style={{ maxWidth: '400px' }}>
              <div className="card border-0 shadow" style={{ height: 'auto' }}>
                <div
                  className="card-body"
                  style={{
                    padding: '2rem',
                    alignContent: 'center',
                    alignItems: 'center',
                  }}
                >
                  <div className="d-flex justify-content-center">
                    <div
                      className="bg-white rounded-circle p-3 "
                      style={{ width: '150px', height: '150px' }}
                    >
                      <img
                        src={memoji}
                        alt="memoji"
                        className="w-100 h-100 object-fit-cover"
                        style={{ borderRadius: '50%' }}
                      />
                    </div>
                  </div>
                  <p className="auth--title1">
                    YOU HAVE 2 FACTOR AUTHENTICATION ENABLED
                  </p>
                  <p className="auth--title2">
                    INSERT CODE FROM GOOGLE AUTHENTICATOR
                  </p>
                  <hr />
                  <div className="form-group">
                    <input
                      type="text"
                      placeholder="000000"
                      className={`form-control code--input ${
                        invalidCode ? 'is-invalid' : ''
                      }`}
                      onChange={updateCode}
                      value={code}
                    />
                    <div className="invalid-feedback">
                      {invalidCode ? 'Wrong code' : ''}
                    </div>
                  </div>
                  <div className="text-center">
                    <button
                      className="btn btn-secondary"
                      onClick={handleSubmit}
                      disabled={code.length !== 6}
                    >
                      Authenticate
                    </button>
                  </div>
                </div>
              </div>
            </div>
          </div>
        </div>
      )}
    </>
  );
}
