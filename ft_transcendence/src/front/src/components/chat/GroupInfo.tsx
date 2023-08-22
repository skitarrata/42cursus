import { useState, useEffect, useContext } from 'react';
import { Context } from '../../App';
import {
  channelRequestPkj,
  ChatInfo,
  FullPartecipant,
  Partecipant,
} from '../../models/Chat.interface';
import UserGroup from './UserGroup';
import groupIcon from '../../assets/group_icon.jpeg';

interface Prop {
  isVisible: boolean;
  setVisibility: Function;
  chatInfo: ChatInfo | undefined;
}

export default function GroupInfo(Prop: Prop) {
  const userId = useContext(Context).userId;
  const socket = useContext(Context).socket;
  const onlines = useContext(Context).online;

  const [request, setRequest] = useState<channelRequestPkj | undefined>(
    undefined
  );
  const [partecipants, setPartecipants] = useState<FullPartecipant[]>([]);
  const [partecipantInfo, setPartecipantInfo] = useState<Partecipant>();
  const [msgCounter, setMsgCounter] = useState(0);

  async function getUsersInChan() {
    await fetch(`/api/chat/getFullPartInfoNyChan/${Prop.chatInfo?.roomId}`, {
      credentials: 'include',
    })
      .then((response) => response.json())
      .then((result) => setPartecipants(result));
  }

  async function getPartecipantInfo() {
    await fetch(
      `/api/chat/GetPartecipantByUserAndChan/${Prop.chatInfo?.roomId}/${userId}`,
      { credentials: 'include' }
    )
      .then((response) => response.json())
      .then((result) => {
        setPartecipantInfo(result);
      });
  }

  async function getMessageNumber() {
    await fetch(`/api/chat/GetMessageCounter/${Prop.chatInfo?.roomId}`, {
      credentials: 'include',
    })
      .then((response) => response.json())
      .then((result) => {
        setMsgCounter(result);
      });
  }

  function handleKeyDown(e: any) {
    if (e.key === 'Escape') {
      Prop.setVisibility(false);
    }
  }

  useEffect(() => {
    getPartecipantInfo();
    getMessageNumber();
    if (partecipants.length < 1) getUsersInChan();
    // eslint-disable-next-line react-hooks/exhaustive-deps
  }, [Prop]);

  useEffect(() => {
    socket?.on('ChannelRequest', () => {
      getUsersInChan();
    });
    return () => {
      socket?.removeListener('ChannelRequest');
    };
    // eslint-disable-next-line react-hooks/exhaustive-deps
  }, []);

  return (
    <div
      style={{
        visibility: Prop.isVisible === true ? 'visible' : 'hidden',
        opacity: '1',
      }}
      className="justify-content-center"
      tabIndex={1}
      onKeyDown={(e) => handleKeyDown(e)}
    >
      <div
        className="card-body contacts_body row scrollable"
        style={{ gap: '4px', display: 'flex' }}
      >
        <div className="group-info-box">
          <div className="info-username-image">
            <img
              alt="profile"
              src={groupIcon}
              className="profile-info-img"
              style={{ marginTop: '10px' }}
            />
            <div
              className="profile-info-text username"
              style={{ display: 'flex' }}
            >
              {Prop.chatInfo?.username}
            </div>
            <p className="profile-info-text">
              MODE:{' '}
              {Prop.chatInfo?.mode === 'PUB'
                ? ' Public'
                : Prop.chatInfo?.mode === 'PRI'
                ? ' Private'
                : ' Protected'}
            </p>
            <p className="profile-info-text">Messages: {msgCounter}</p>
            <p className="profile-info-text">Users: {partecipants.length}</p>
          </div>
        </div>
        <div
          className="group-info-box" /* style={{maxWidth:'fit-content', minWidth: 'fit-content'}} */
        >
          <div className="info-username-image">
            <p className="profile-info-text username">Partecipants</p>
            <div className="card-body contacts_body">
              <ul className="contacts scrollable-info-partecipants">
                {partecipants === undefined || partecipantInfo === undefined
                  ? null
                  : partecipants.map((part: FullPartecipant) => {
                      const on = onlines.find(
                        (el) => part.userId.id === el || part.userId.id === -el
                      );
                      return partecipantInfo === undefined ? null : (
                        <li key={part.userId.id}>
                          <UserGroup
                            part={part}
                            on={on}
                            myInfo={partecipantInfo!}
                            request={request}
                            setRequest={setRequest}
                          />
                        </li>
                      );
                    })}
              </ul>
            </div>
          </div>
        </div>
      </div>
      {/* {request === undefined ? null : (
        <ConfirmRequest req={request} setReq={setRequest} />
      )} */}
    </div>
  );
}
