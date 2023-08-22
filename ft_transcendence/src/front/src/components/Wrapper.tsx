import Nav from './Nav';
import 'primereact/resources/themes/lara-light-indigo/theme.css'; //theme
import 'primereact/resources/primereact.min.css'; //core css
import 'primeicons/primeicons.css'; //icons
import { Menubar } from 'primereact/menubar';
import React, { useContext, useEffect, useRef, useState } from 'react';
import { Dialog } from 'primereact/dialog';
import { DisplayUser, User } from '../models/User.interface';
import axios from 'axios';
import { Toast } from 'primereact/toast';
import { Context } from '../App';
import { useNavigate } from 'react-router-dom';
import '../MacOS.css';
import FriendlyMatchPopUp from './FriendlyMatchPopUp';
import { Sidebar } from 'primereact/sidebar';
import { UserList } from './chat/UserList';
import Chat from '../pages/Chat';
import MessageBox from '../components/chat/MessageBox';
import { Menu } from 'primereact/menu';

interface Props {
  children: JSX.Element | JSX.Element[];
  noImage?: boolean;
}

interface Friend {
  id: number;
  username: string;
}

export default function Wrapper({ children, noImage }: Props) {
  const [displayAppleInfo, setDisplayAppleInfo] = useState<boolean>(false);
  const [displayChat, setDisplayChat] = useState<boolean>(false);
  const [displayTrascendenceInfo, setDisplayTrascendenceInfo] =
    useState<boolean>(false);

  const navigate = useNavigate();

  const [friend, setFriend] = useState<Friend>();
  const [displayProfile, setDisplayProfile] = useState<boolean>(false);

  const [user, setUser] = useState<User>();
  const socket = useContext(Context).socket;

  const currentDate = new Date();
  const formattedDate = `${currentDate.toLocaleDateString()} ${currentDate.toLocaleTimeString()}`;

  const [isCtrlKeyPressed, setIsCtrlKeyPressed] = useState(false);
  const [isCmdKeyPressed, setIsCmdKeyPressed] = useState(false);

  const [isSearchBarVisible, setIsSearchBarVisible] = useState(false);

  const [ytVideoDialog, setYtVideoDialog] = useState(false);

  useEffect(() => {
    function handleKeyDown(event: any) {
      if (
        event.key === 'k' &&
        (event.ctrlKey || event.metaKey) &&
        !isSearchBarVisible
      ) {
        setIsSearchBarVisible(true);
      } else if (
        isSearchBarVisible &&
        event.key === 'k' &&
        (event.ctrlKey || event.metaKey)
      ) {
        setIsSearchBarVisible(false);
      }
    }

    function handleKeyUp(event: any) {
      if (event.key === 'Control') {
        setIsCtrlKeyPressed(false);
      }
      if (event.key === 'Meta') {
        setIsCmdKeyPressed(false);
      }
    }

    function handleKeyPress(event: any) {
      if (event.key === 'Control') {
        setIsCtrlKeyPressed(true);
      }
      if (event.key === 'Meta') {
        setIsCmdKeyPressed(true);
      }
    }

    //document.addEventListener('keydown', handleKeyDown);
    //document.addEventListener('keyup', handleKeyUp);
    //document.addEventListener('keydown', handleKeyPress);
    /*     {
      {
      }
    } */
    /*     return () => {
      document.removeEventListener('keydown', handleKeyDown);
      document.removeEventListener('keyup', handleKeyUp);
      document.removeEventListener('keydown', handleKeyPress);
    }; */
  }, [isSearchBarVisible]);

  useEffect(() => {
    function handleKeyPress(event: any) {
      if (event.key === 'Control') {
        setIsCtrlKeyPressed(true);
      }
      if (event.key === 'Meta') {
        setIsCmdKeyPressed(true);
      }
    }

    document.addEventListener('keydown', handleKeyPress);

    return () => {
      document.removeEventListener('keydown', handleKeyPress);
    };
  }, []);

  async function signOutUser() {
    await fetch(`/api/logout`, {
      credentials: 'include',
    });
    window.location.reload();
  }

  const start = (
    <i
      className="pi pi-apple"
      style={{
        cursor: 'pointer',
      }}
      onClick={() => setDisplayAppleInfo(true)}
    />
  );

  const wifiList = [
    {
      label: 'Martin Router King',
      icon: 'pi pi-fw pi-wifi',
    },
    {
      label: 'Antenna 5G',
      icon: 'pi pi-fw pi-wifi',
    },
    {
      label: 'Il merda Wi-Fi',
      icon: 'pi pi-fw pi-wifi',
    },
    {
      label: 'Questo non è un wifi',
      icon: 'pi pi-fw pi-wifi',
    },
    {
      label: 'La cantina dei bambini',
      icon: 'pi pi-fw pi-wifi',
    },
    {
      label: 'Casa di Franco',
      icon: 'pi pi-fw pi-wifi',
    },
    {
      label: 'Orfanotrofio di Re Bibbia',
      icon: 'pi pi-fw pi-wifi',
    },
    {
      label: 'Albanese Mobile',
      icon: 'pi pi-fw pi-wifi',
    },
    {
      label: 'Skokkapattino',
      icon: 'pi pi-fw pi-wifi',
    },
    {
      label: 'Archeo BLE',
      icon: 'pi pi-fw pi-wifi',
    },
    {
      label: 'Alfred 2G',
      icon: 'pi pi-fw pi-wifi',
    },
    {
      label: 'KKKK',
      icon: 'pi pi-fw pi-wifi',
    },
    {
      label: 'MerdEmily',
      icon: 'pi pi-fw pi-wifi',
    },
    {
      label: 'Giulia Wi-Fi',
      icon: 'pi pi-fw pi-wifi',
    },
  ];

  const menu = useRef<any>(null);
  const toast = useRef<Toast>(null);
  const showSuccess = () => {
    if (toast.current)
      toast.current.show({
        severity: 'error',
        summary: 'No bro, sei troppo brutto per fare un videochiamata',
        life: 3000,
      });
  };
  const end = (
    <React.Fragment>
      <i className="pi pi-video" onClick={showSuccess} />
      <i
        className="pi pi-wifi"
        id="wifilist"
        onClick={(event) => {
          if (menu.current) menu.current.toggle(event);
        }}
      />
      <Menu model={wifiList} popup ref={menu} id="popup_menu" />
      <i className="pi pi-volume-up" />
      <span onClick={() => setDisplayChat(true)}>{formattedDate}</span>
    </React.Fragment>
  );

  useEffect(() => {
    (async () => {
      const { data } = await axios.get(`/api/user`, {
        withCredentials: true,
      });
      setUser(data);
    })();
    socket?.on('friendlyMatch', handleFriendlyMatch);

    return () => {
      socket?.removeListener('friendlyMatch');
    };
  }, [socket, noImage]);

  useEffect(() => {
    (async () => {
      const { data } = await axios.get(`/api/user`, { withCredentials: true });
      setUser(data);
    })();
    socket?.on('friendlyMatch', handleFriendlyMatch);

    return () => {
      socket?.removeListener('friendlyMatch');
    };
  }, [socket, noImage]);

  const handleFriendlyMatch = (friend: { id: number; username: string }) => {
    setFriend({
      ...friend,
    });
  };
  const menubarItems = [
    {
      label: 'Trascendence',
      items: [
        {
          label: 'About',
          icon: 'pi pi-fw pi-info-circle',
          command: () => setDisplayTrascendenceInfo(true),
        },
        {
          label: 'Return to home',
          icon: 'pi pi-fw pi-home',
          command: () => navigate('/'),
        },
        {
          label: 'Sign Out',
          icon: 'pi pi-fw pi-sign-out',
          command: () => signOutUser(),
        },
      ],
    },
  ];

  return (
    <>
      {/* <Nav noImage={noImage} /> */}
      <main style={{ height: '100%' }}>
        <Toast ref={toast} />

        <Menubar model={menubarItems} start={start} end={end} />

        <div className="dock-window dock-advanced">{children}</div>
        {friend && (
          <FriendlyMatchPopUp
            friend={friend}
            user={user}
            onClose={() => setFriend(undefined)}
          />
        )}
        <Dialog
          header="About this Mac"
          visible={displayAppleInfo}
          onHide={() => setDisplayAppleInfo(false)}
          modal={false}
          resizable
          maximizable
          breakpoints={{ '960px': '75vw' }}
        >
          <div style={{ padding: '20px' }}>
            <p>
              <b>macOS</b>
              <br />
              Version 11.2.3
            </p>
            <p>
              <b>Mac Pro (13-inch, 2050, Two Thunderbolt 18 ports)</b>
              <br />
              Processor 2.3 GHz Dual-Core Intel Core i5
              <br />
              Memory 8 GB 2133 MHz LPDDR3
              <br />
              Graphics Intel Iris Plus Graphics 640 1536 MB
            </p>
            <p>
              <b>Serial Number</b>
              <br />
              C02ZV0JNHV2N
            </p>
          </div>
        </Dialog>
        <Dialog
          header="Trascendence"
          visible={displayTrascendenceInfo}
          onHide={() => setDisplayTrascendenceInfo(false)}
          modal={false}
          resizable={true}
          maximizable
          breakpoints={{ '960px': '15vw' }}
        >
          <div className="p-4">
            <p>
              <b>Trascendence</b>
              <br />
            </p>
            <p>
              <b> Designed by apple in california (forse no)</b>
              <br />
            </p>
          </div>
        </Dialog>

        <Dialog
          visible={displayChat}
          onHide={() => setDisplayChat(false)}
          position="right"
          modal={false}
          style={{ backgroundColor: 'transparent' }}
          className="chat-dialog"
        >
          <Chat />
        </Dialog>
        <Dialog
          visible={isSearchBarVisible}
          onHide={() => setIsSearchBarVisible(false)}
          position="center"
          id="search-dialog"
          style={{
            backgroundColor: 'transparent',
            boxShadow: 'none',
            width: '90vh',
          }}
          className="search-dialog"
          modal={false}
        >
          <UserList />
          <div style={{ display: 'none' }}>
            <Chat />
          </div>
        </Dialog>
      </main>
    </>
  );
}
