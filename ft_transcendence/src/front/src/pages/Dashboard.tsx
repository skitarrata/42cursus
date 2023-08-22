import Wrapper from '../components/Wrapper';
import '../styles/neon_button.css';
import { NavLink, useNavigate } from 'react-router-dom';
import { useContext, useEffect, useState } from 'react';
import { Context } from '../App';
import { useRef } from 'react';
import finder from '../assets/paderi/finder.svg';
import photos from '../assets/paderi/launchpad.webp';
import pong from '../assets/paderi/pong.webp';
import chat from '../assets/paderi/chat.png'; //TODO change image
import LeaderboardRow from '../components/LeaderboardRow';
import trash from '../assets/paderi/trash.png';
import { Dock } from 'primereact/dock';
import axios from 'axios';
import { Dialog } from 'primereact/dialog';
import { DisplayUser, User } from '../models/User.interface';
import Chat from '../pages/Chat';

export default function Dashboard() {
  const onlines = useContext(Context).online;

  const [displayTrash, setDisplayTrash] = useState<boolean>(false);
  const [displayPong, setDisplayPong] = useState<boolean>(false);
  const [displayProfile, setDisplayProfile] = useState<boolean>(false);
  const [displayChat, setDisplayChat] = useState<boolean>(false);
  const navigate = useNavigate();
  const [users, setUsers] = useState<DisplayUser[]>([]);
  const [displayLeaderboard, setDisplayLeaderboard] = useState<boolean>(false);

  const [user, setUser] = useState<User>();

  const imgErrorPath =
    'https://www.primefaces.org/wp-content/uploads/2020/05/placeholder.png';

  const items = [
    {
      label: 'Finder',
      icon: () => <img alt="Finder" src={finder} width="100%" />,
      command: () => setDisplayProfile(true),
    },
    {
      label: 'Leaderboard',
      icon: () => <img alt="Leaderboard" src={photos} width="100%" />,
      command: () => setDisplayLeaderboard(true),
    },
    {
      label: 'Pong',
      icon: () => <img alt="Pong" src={pong} width="100%" />,
      command: () => setDisplayPong(true),
	},
	{
		label: 'Chat',
		icon: () => <img alt="Chat" src={chat} width="100%" />,
		command: () => setDisplayChat(true),
	},
    /* {
      label: 'Settings',
      icon: 'pi pi-cog',
      command: () => {
        window.location.href = '/settings';
      },
    }, */
    {
      label: 'Trash',
      icon: () => <img alt="trash" src={trash} width="100%" />,
      command: () => setDisplayTrash(true),
    },
  ];

  useEffect(() => {
    (async () => {
      const { data } = await axios.get(`/api/user`, {
        withCredentials: true,
      });
      setUser(data);
    })();
  }, []);

  useEffect(() => {
    (async () => {
      const { data } = await axios.get(`/api/user`, { withCredentials: true });
      setUser(data);
    })();
  }, []);

  useEffect(() => {
    async function getter() {
      let res = await fetch(`/api/users/leader`);
      let users = await res.json();
      setUsers(users);
    }

    getter();
  }, []);

  return (
    <Wrapper>
      <Dock model={items} />
      <Dialog
        header="Profile"
        visible={displayProfile}
        onHide={() => setDisplayProfile(false)}
        modal={false}
        resizable={true}
        maximizable
        breakpoints={{ '960px': '75vw' }}
      >
        <div className="header--photo_name h-full p-4">
          <div
            className="flex flex-row h-full gap-4"
            style={{
              padding: '10px',
              justifyContent: 'center',
              alignItems: 'center',
              height: '100%',
            }}
          >
            <img
              alt="profile"
              src={user?.avatar}
              style={{
                borderRadius: '100%',
                border: '5px solid white',
                height: '15em',
                width: '15em',
                objectFit: 'cover',
              }}
            />

            <div className="header--text">
              <h1>{user?.username}</h1>
              <p>Vittorie: {user?.wins}</p>
              <p>Sconfitte: {user?.losses}</p>
              <p>Punti: {user?.points}</p>
              <button
                className=" bg-transparent"
                style={{
                  borderRadius: '10px',
                  border: '2px solid white',
                  padding: '5px 10px',
                  color: 'white',
                }}
                onClick={() => navigate('/users/' + user?.username)}
              >
                Vai al profilo
              </button>
            </div>
          </div>
        </div>
      </Dialog>
      <Dialog
        header="Leaderboard"
        visible={displayLeaderboard}
        onHide={() => setDisplayLeaderboard(false)}
        modal={false}
        resizable={true}
        maximizable
        style={{ width: '50vw' }}
        breakpoints={{ '960px': '75vw' }}
      >
        <div
          className="leaderboard table-responsive"
          style={{
            padding: '20px',
          }}
        >
          <table className="table table-hover">
            <thead>
              <tr className="table-header">
                <th className="board-col-1">POS</th>
                <th className="board-col-2">USER</th>
                <th className="board-col-3">POINTS</th>
                <th className="board-col-4">WINS-LOSSES</th>
              </tr>
            </thead>
            <tbody>
              {users.map((user: DisplayUser, pos: number) => (
                <LeaderboardRow key={user.id} user={user} pos={pos} />
              ))}
            </tbody>
          </table>
        </div>
      </Dialog>
      <Dialog
        visible={displayTrash}
        style={{ width: '50vw' }}
        onHide={() => setDisplayTrash(false)}
        dismissableMask={true}
        resizable
        maximizable
      >
        <img
          src={user?.avatar}
          onError={(e) => (e.currentTarget.src = imgErrorPath)}
          alt="Trash"
          width="100%"
        />
      </Dialog>
      <Dialog
        visible={displayPong}
        onHide={() => setDisplayPong(false)}
        maximizable={true}
        style={{ width: '95vw', overflow: 'hidden' }}
        resizable={true}
        blockScroll={true}
      >
        <div className="center" style={{ overflow: 'hidden' }}>
          <div className="d-flex flex-column align-items-center justify-content-center">
            <h1 className="white-text">Macintosh Pong</h1>
            <NavLink to={'/game'}>
              <div className="neon-button">Classic</div>
            </NavLink>
            <NavLink to={'/game/inverted'}>
              <div className="neon-button" style={{ marginTop: '1rem' }}>
                Inverted
              </div>
            </NavLink>
            <div
              className="flex-row sp-even"
              style={{ width: '25%', marginTop: '1rem' }}
            >
              <p>Online Players: {onlines.filter((online) => online).length}</p>
              <p>In Game: {onlines.filter((online) => online < 0).length}</p>
            </div>
          </div>
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
    </Wrapper>
  );
}
