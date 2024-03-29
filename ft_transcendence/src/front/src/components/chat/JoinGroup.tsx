import { Avatar, Stack } from '@mui/material';
import { Dialog } from 'primereact/dialog';
import { useState, useEffect, useContext } from 'react';
import { JoinChannelPkg, ShortChannel } from '../../models/Chat.interface';
import CheckPass from './CheckPass';
import { Context } from '../../App';
import groupIcon from '../../assets/group_icon.jpeg';
import { useNavigate } from 'react-router-dom';

interface Prop {
  isVisible: string;
  setVisibility: Function;
}

export function JoinGroup({ isVisible = 'hidden', setVisibility }: Prop) {
  const userId = useContext(Context).userId;
  const socket = useContext(Context).socket;
  const [channels, setChannels] = useState<ShortChannel[]>([]);
  const [passVisibility, setPassVisibility] = useState('hidden');
  const [errorVisibility, setErrorVisibility] = useState('hidden');
  const [banVisibility, setBanVisibility] = useState('hidden');
  const [groupName, setGroupName] = useState('');
  const [selectedChan, setSelectedChan] = useState<ShortChannel>();
  const [joinReq, setReq] = useState<JoinChannelPkg>({
    idUser: userId,
    room: '',
    key: '',
  });

  const navigate = useNavigate();

  const nameSubmit = (str: string) => {
    if (str) {
      (async () => {
        const response = await fetch(`/api/chat/ChannelByName/${str}`, {
          credentials: 'include',
        });
        if (response.status !== 200) {
          setChannels([]);
          navigate('/signin');
          return;
        }

        const result = response.json();
        result.then((res) => {
          setChannels(res);
        });
      })();
    } else {
      setChannels([]);
    }
  };

  function selectChannel(e: any, chan: ShortChannel) {
    setSelectedChan(chan);
    const req = joinReq;
    req.room = '' + chan.id;
    setReq(req);
    setErrorVisibility('hidden');

    if (chan.mode === 'PRO') return setPassVisibility('visible');
    setPassVisibility('hidden');
    socket?.emit('joinRoom', req);
  }

  function handleKeyDown(e: any) {
    if (e.key === 'Escape') {
      setVisibility('hidden');
    }
  }

  useEffect(() => {
    socket?.on('joinedStatus', (status) => {
      if (status === 1) {
        setPassVisibility('hidden');
        setErrorVisibility('hidden');
        setVisibility('hidden');
      } else if (status === 0) {
        setPassVisibility('visible');
        setErrorVisibility('visible');
        setBanVisibility('hidden');
      } else if (status === -1) {
        setPassVisibility('visible');
        setErrorVisibility('hidden');
        setBanVisibility('visible');
      }
    });
    return () => {
      socket?.removeListener('joinedStatus');
    };
    // eslint-disable-next-line react-hooks/exhaustive-deps
  }, [joinReq]);

  return (
    <div
      style={{
        visibility: isVisible === 'hidden' ? 'hidden' : 'visible',
        opacity: '1',
      }}
      tabIndex={1}
      onKeyDown={(e) => handleKeyDown(e)}
      className=""
    >
      <div className="col-ms-10">
        <div className="">
          <div className="card-header">
            <div className="input-group">
              <input
                type="text"
                placeholder="Search..."
                name=""
                className="form-control search"
                onChange={(e) => {
                  if (/^[a-zA-Z0-9-_]{0,20}$/.test(e.target.value)) {
                    setGroupName(e.target.value);
                    nameSubmit(e.target.value);
                  }
                }}
                value={groupName}
              />
              <div className="input-group-prepend">
                <span className="input-group-text search_btn">
                  <i className="fas fa-search"></i>
                </span>
                <span className="input-group-text close_btn">
                  <i
                    className="fas fa-times fa-lg"
                    onClick={(e) => setVisibility('hidden')}
                  ></i>
                </span>
              </div>
            </div>
          </div>
          <div className="contacts_body card-body scrollable-searchGroup">
            {channels.map((chan: ShortChannel, i) => {
              return (
                <div
                  className="d-flex bd-highlight group-search-box justify-content-center"
                  onClick={(e) => selectChannel(e, chan)}
                  style={{ cursor: 'pointer', marginBottom: '10px', flex: '1' }}
                  key={i}
                >
                  <div className="img_cont" style={{ marginTop: '20px' }}>
                    <Stack direction="row" spacing={2}>
                      <Avatar alt="Img" src={groupIcon} />
                    </Stack>
                  </div>
                  <div className="user_info">
                    <span>{chan.name}</span>
                    <p>ID: {chan.id}</p>
                  </div>
                  {chan.mode === 'PRO' ? (
                    <div
                      className="fas fa-lock icon-container"
                      style={{ marginRight: '10px', marginTop: '30px' }}
                    ></div>
                  ) : (
                    <div
                      className="fas fa-lock-open icon-container"
                      style={{ marginRight: '10px', marginTop: '30px' }}
                    ></div>
                  )}
                </div>
              );
            })}
          </div>
        </div>
      </div>
      <Dialog
        visible={passVisibility === 'visible' ? true : false}
        onHide={() => setPassVisibility('hidden')}
        modal={false}
        resizable
        maximizable
        style={{ width: '50vw', height: '50vh' }}
        breakpoints={{ '960px': '75vw' }}
      >
        <CheckPass
          isVisible={passVisibility}
          setVisibility={setPassVisibility}
          errorVisibility={errorVisibility}
          setErrorVisibility={setErrorVisibility}
          request={joinReq}
          banVisibility={banVisibility}
          setBanVisibility={setBanVisibility}
          chan={selectedChan}
        />
      </Dialog>
    </div>
  );
}
