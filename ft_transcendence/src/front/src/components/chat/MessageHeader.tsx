import { Avatar } from '@mui/material';
import { useContext, useEffect, useRef, useState } from 'react';
import { NavLink, useNavigate } from 'react-router-dom';
import { Context } from '../../App';
import {
  channelRequestPkj,
  ChatInfo,
  OpenRoomPkg,
  Partecipant,
} from '../../models/Chat.interface';
import StyledBadge from '../../styles/StyleBage';
import GroupInfo from './GroupInfo';
import GroupSettings from './GroupSettings';
import groupIcon from '../../assets/group_icon.jpeg';
import { Dialog } from 'primereact/dialog';
import { Dropdown } from 'primereact/dropdown';
import { Menu } from 'primereact/menu';
import { Button } from 'primereact/button';

interface Prop {
  chatInfo: ChatInfo | undefined;
}

export default function MessageHeader({ chatInfo }: Prop) {
  const onlines = useContext(Context).online;
  const socket = useContext(Context).socket;
  const userId = useContext(Context).userId;
  const [on, setOn] = useState<number>();
  const [infoVisibility, setInfoVisibility] = useState(false);
  const [settingsVisibility, setSettingsVisibility] = useState(false);
  const [click, setClick] = useState(false);
  const [partecipantInfo, setPartecipantInfo] = useState<Partecipant>();
  const [otherPartecipant, setOtherPartecipant] = useState<Partecipant>();
  const [noUpdate, setNoUpdate] = useState(false);

  const navigate = useNavigate();

  async function getPartecipantInfo() {
    await fetch(
      `/api/chat/GetPartecipantByUserAndChan/${chatInfo?.roomId}/${userId}`,
      { credentials: 'include' }
    )
      .then((response) => response.json())
      .then((result) => {
        setPartecipantInfo(result);
      })
      .catch(() => {});
    if (chatInfo?.userId !== undefined) {
      await fetch(
        `/api/chat/GetPartecipantByUserAndChan/${chatInfo?.roomId}/${chatInfo?.userId}`,
        { credentials: 'include' }
      )
        .then((response) => response.json())
        .then((result) => {
          setOtherPartecipant(result);
        })
        .catch(() => {});
    }
  }

  function blockUser() {
    if (
      chatInfo !== undefined &&
      chatInfo.userId !== undefined &&
      otherPartecipant !== undefined
    ) {
      const req: channelRequestPkj = {
        sender: userId,
        reciver: chatInfo.userId,
        channelId: +chatInfo.roomId,
        type: otherPartecipant.mod === 'm' ? 'Block' : 'Unblock',
        reciverName: chatInfo.username,
        time: 0,
      };
      socket?.emit('BlockUser', req);
      const ot = otherPartecipant;

      ot.mod = req.type === 'Block' ? 'b' : 'm';
      setOtherPartecipant((prev) => ({
        ...prev!,
        mod: req.type === 'Block' ? 'b' : 'm',
      }));
    }
  }

  function userLeave() {
    const leavePkg: OpenRoomPkg = {
      idUser: userId,
      room: chatInfo!.roomId,
    };
    socket?.emit('leaveRoom', leavePkg);
  }

  useEffect(() => {
    if (noUpdate) return;
    if (chatInfo?.userId !== undefined) {
      setOn(
        onlines.find((el) => chatInfo.userId === el || chatInfo.userId === -el)
      );
    }
  }, [chatInfo, onlines]);

  useEffect(() => {
    //--------click event listener---------
    document.getElementById('parent')?.addEventListener('click', clicker);
    return () => {
      setNoUpdate(true);
      document.getElementById('parent')?.removeEventListener('click', clicker);
    };
    // eslint-disable-next-line react-hooks/exhaustive-deps
  }, [click]);

  function clicker(e: any) {
    if (document.getElementById('prova') === e.target) {
      setClick(!click);
    } else if (click) {
      setClick(false);
    }
  }

  useEffect(() => {
    if (noUpdate) return;
    getPartecipantInfo();
    return () => {
      setNoUpdate(true);
    };
    // eslint-disable-next-line react-hooks/exhaustive-deps
  }, [chatInfo]);

  let dropdownGroup = [
    {
      label: 'Group Info',
      icon: 'pi pi-fw pi-info-circle',
      command: () => setInfoVisibility(true),
    },
    {
      label: 'Leave group',
      icon: 'pi pi-fw pi-sign-out',
      command: () => userLeave(),
    },
    {
      label: 'Settings',
      icon: 'pi pi-fw pi-cog',
      command: () => setSettingsVisibility(true),
    },
  ];

  let dropdownUser = [
    {
      label: 'User Profile',
      icon: 'pi pi-fw pi-user',
      command: () => navigate('/users/' + chatInfo?.username),
    },
    {
      label:
        otherPartecipant !== undefined && otherPartecipant.mod !== 'b'
          ? 'Block'
          : 'Unblock',
      icon: 'pi pi-fw pi-ban',
      command: () => blockUser(),
    },
  ];

  const menu = useRef<any>(null);

  return (
    <>
      <div className="card-header msg_head">
        <div
          className="d-flex bd-highlight"
          style={{ alignItems: 'center', gap: '4px' }}
        >
          <NavLink
            to={
              chatInfo?.avatar === undefined
                ? ''
                : '/users/' + chatInfo?.username
            }
          >
            <StyledBadge
              overlap="circular"
              color={
                on !== undefined ? (on > 0 ? 'success' : 'warning') : 'error'
              }
              invisible={chatInfo?.avatar === undefined}
              anchorOrigin={{
                vertical: 'bottom',
                horizontal: 'right',
              }}
              variant="dot"
            >
              <Avatar
                alt="Img"
                src={
                  chatInfo?.avatar === undefined ? groupIcon : chatInfo?.avatar
                }
              />
            </StyledBadge>
          </NavLink>

          <div
            style={{
              display: 'flex',
              width: '100%',
              alignItems: 'center',
              justifyContent: 'center',
              flexDirection: 'column',
            }}
          >
            <div
              style={{
                display: 'flex',
                alignItems: 'center',
                width: '100%',
                justifyContent: 'space-between',
              }}
            >
              <span>{chatInfo?.username}</span>
              <Button
                icon="pi pi-bars"
                onClick={(event) => menu.current && menu.current.toggle(event)}
                aria-controls="popup_menu"
                aria-haspopup
                className="text-white"
                style={{ backgroundColor: 'transparent', border: 'none' }}
              />
            </div>
            <Menu
              model={
                chatInfo?.avatar === undefined ? dropdownGroup : dropdownUser
              }
              popup={true}
              ref={menu}
              id="popup_menu"
            />
            {/* {chatInfo?.avatar === undefined && click === true ? (
              <Dropdown
                model={dropdownGroup}
                className="action_menu"
                style={{ zIndex: 1 }}
              />
            ) : click === true ? (
              <Dropdown
                model={dropdownUser}
                className="action_menu"
                style={{ zIndex: 1 }}
              />
            ) : null} */}
          </div>
        </div>
      </div>
      <Dialog
        header="Group Info"
        visible={infoVisibility}
        onHide={() => setInfoVisibility(false)}
        modal={true}
        resizable
        maximizable
        breakpoints={{ '960px': '105vw' }}
      >
        <div className="p-4">
          {chatInfo === undefined || chatInfo.roomId === '' ? null : (
            <GroupInfo
              isVisible={infoVisibility}
              chatInfo={chatInfo}
              setVisibility={(value: boolean) => setInfoVisibility(value)}
            />
          )}
        </div>
      </Dialog>
      {settingsVisibility === false &&
      partecipantInfo?.mod !== 'o' &&
      partecipantInfo?.mod !== 'a' ? null : chatInfo === undefined ||
        chatInfo.roomId === '' ? null : (
        <Dialog
          header="Group Settings"
          visible={settingsVisibility}
          onHide={() => setSettingsVisibility(false)}
          modal={false}
          resizable
          maximizable
          breakpoints={{ '960px': '75vw' }}
        >
          <div className="p-4">
            <GroupSettings
              isVisible={settingsVisibility}
              chatInfo={chatInfo}
              setVisibility={(value: boolean) => setSettingsVisibility(value)}
            />
          </div>
        </Dialog>
      )}
    </>
  );
}
