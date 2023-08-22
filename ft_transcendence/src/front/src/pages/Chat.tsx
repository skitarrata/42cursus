import { useState, useEffect, useContext } from 'react';
import { Socket } from 'socket.io-client';
import { Sender } from '../components/chat/Sender';
import MessageBox from '../components/chat/MessageBox';
import Wrapper from '../components/Wrapper';
import { MessagePkg } from '../models/Chat.interface';
import { UserList } from '../components/chat/UserList';
import '../styles/Chat.css';
import { ChannelList } from '../components/chat/ChannelList';
import MessageHeader from '../components/chat/MessageHeader';
import { ChatInfo } from '../models/Chat.interface';
import { context, Context } from '../App';
import { Dialog } from 'primereact/dialog';

export function Chat() {
  const cont: context = useContext(Context);
  const [pkg, setPkg] = useState<MessagePkg>();
  const [socket, setSocket] = useState<Socket>();
  const [room, setRoom] = useState('');
  const [chatInfo, setChatInfo] = useState<ChatInfo>();

  function getUser() {
    fetch(`/api/user`, {
      credentials: 'include',
    })
      .then((response) => response.json())
      .then((result) => {
        setPkg({
          id: 0,
          data: '',
          userId: {
            id: result.id,
            username: result.username,
          },
          room: '',
          sendDate: new Date(),
        });
      });
  }

  //-----------PKG OR SOCKET UPDATE
  useEffect(() => {
    if (pkg === undefined) getUser();
    if (socket === undefined && cont.socket !== undefined)
      setSocket(cont.socket);
    // eslint-disable-next-line react-hooks/exhaustive-deps
  }, [pkg, socket, room]);

  //-----------VIEW LISTENER
  useEffect(() => {
    socket?.on('viewedRoom', (roomView: string) => {
      if (room !== roomView) setRoom(roomView);
      if (roomView === '' && chatInfo !== undefined) {
        const preInfo = chatInfo;
        preInfo.roomId = '';
        setChatInfo(undefined);
      }
    });

    return () => {
      socket?.removeListener('viewedRoom');
    };
    // eslint-disable-next-line react-hooks/exhaustive-deps
  }, [pkg, socket, chatInfo]);

  useEffect(() => {
    if (socket !== undefined) {
      socket.on('createRoom', (newRoom: string) => {
        if (room !== newRoom) setRoom(newRoom);
      });
    }
    return () => {
      socket?.removeListener('createRoom');
    };
    // eslint-disable-next-line react-hooks/exhaustive-deps
  }, [socket]);

  const footerDialog = (
    <>{pkg === undefined ? null : <Sender room={room} packet={pkg} />}</>
  );

  return cont.socket === undefined ? null : (
    <>
      <div id="parent" className="container-fluid">
        <div className="d-flex flex-column">
          {chatInfo === undefined ||
          chatInfo.roomId === '' ||
          room === '' ? null : (
            <div>
              <Dialog
                header={chatInfo?.username}
                visible={chatInfo !== undefined}
                onHide={() => {
                  if (chatInfo !== undefined) {
                    setChatInfo(undefined);
                  }
                }}
                modal={false}
                resizable
                footer={footerDialog}
                maximizable
                style={{ width: '50vw' }}
                breakpoints={{ '960px': '75vw' }}
              >
                <div>
                  <MessageHeader chatInfo={chatInfo} />
                  <MessageBox room={room} />
                </div>
              </Dialog>
              {/* {pkg === undefined || room === undefined ? null : (
                    +
                  )} */}
            </div>
          )}
          {pkg === undefined ? null : <UserList />}
          {pkg === undefined ? null : (
            <ChannelList room={room} setChatInfo={setChatInfo} />
          )}
        </div>
      </div>
    </>
  );
}

export default Chat;
