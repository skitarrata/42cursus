import { Avatar, Stack } from '@mui/material';
import { useState, useEffect, useContext } from 'react';
import { CreationChannelPkg } from '../../models/Chat.interface';
import { User } from '../../models/User.interface';
import StyledBadge from '../../styles/StyleBage';
import { Context } from '../../App';
import { AutoComplete } from 'primereact/autocomplete';

export function UserList() {
  const onlines = useContext(Context).online;
  const socket = useContext(Context).socket;
  const userId = useContext(Context).userId;
  const [users, setUsers] = useState<User[]>([]);
  const [ch, setCreationChannel] = useState<CreationChannelPkg>();
  const [searchName, setSearchName] = useState('');

  const nameSubmit = (name: string) => {
    if (name) {
      (async () => {
        const data = await fetch(`/api/users/likeusername/${name}`, {
          credentials: 'include',
        });
        const result = data.json();
        result.then((res) => {
          setUsers(
            res.sort((a: User, b: User) => a.username.localeCompare(b.username))
          );
        });
      })();
    } else {
      setUsers([]);
    }
  };

  function selectUser(e: any, otherId: number) {
    setCreationChannel({
      idUser: userId,
      otherUser: otherId,
      pass: '',
      name: '',
      mode: 'PRI',
      invites: [],
    });
  }

  useEffect(() => {
    if (ch !== undefined && ch?.otherUser !== userId)
      socket?.emit('createRoom', ch);
    // eslint-disable-next-line react-hooks/exhaustive-deps
  }, [ch]);

  const itemTemplate = (user: User) => {
    const on = onlines.find((el) => user.id === el || user.id === -el);

    return (
      <div
        className="row align-items-center"
        style={{ color: 'black', cursor: 'pointer' }}
        onClick={(e) => selectUser(e, user.id)}
      >
        <div className="col-2">
          <Stack direction="row" spacing={2}>
            <StyledBadge
              color={
                on !== undefined ? (on > 0 ? 'success' : 'warning') : 'error'
              }
              overlap="circular"
              invisible={false}
              anchorOrigin={{
                vertical: 'bottom',
                horizontal: 'right',
              }}
              variant="dot"
            >
              <Avatar alt="Img" src={user.avatar} />
            </StyledBadge>
          </Stack>
        </div>
        <div className="col">
          <div
            className="user_info"
            style={{ color: 'black', marginLeft: '15px' }}
          >
            <span style={{ color: 'black' }}>{user.username}</span>
            <p
              style={{
                color: on !== undefined ? (on > 0 ? 'green' : 'yellow') : 'red',
              }}
            >
              {user.username}{' '}
              {on !== undefined
                ? on > 0
                  ? ' is online'
                  : 'is in game'
                : 'is offline'}
            </p>
          </div>
        </div>
      </div>
    );
  };

  return (
    <div className="row chat">
      <div className="card-header">
        <div className="input-group">
          <AutoComplete
            value={searchName}
            suggestions={users}
            completeMethod={(e) => nameSubmit(e.query)}
            field="username"
            onChange={(e) => setSearchName(e.value)}
            placeholder="Search..."
            itemTemplate={itemTemplate}
            style={{ backgroundColor: 'transparent' }}
          />
          <div className="input-group-append">
            <span className="input-group-text search_btn">
              <i className="fas fa-search"></i>
            </span>
          </div>
        </div>
      </div>
    </div>
  );
}
