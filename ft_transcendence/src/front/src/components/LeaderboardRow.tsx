import React from 'react';
import { useNavigate } from 'react-router-dom';

interface TmpUser {
  id: string;
  avatar: string;
  username: string;
  wins: number;
  losses: number;
  points: number;
}

interface Props {
  user: TmpUser;
  pos: number;
}

export default function LeaderboardRow({ user, pos }: Props) {
  const navigate = useNavigate();
  return (
    <tr
      className={`table-row ${
        pos === 0 ? 'first' : pos === 1 ? 'second' : pos === 2 ? 'third' : ''
      }`}
      onClick={() =>
        navigate('/users/' + user.username, { state: { userId: user.id } })
      }
    >
      <td>{pos + 1}</td>
      <td>
        <div className="d-flex align-items-center">
          <img
            src={user.avatar}
            alt="user avatar"
            className="me-3 rounded-circle"
            style={{ width: '40px', height: '40px' }}
          />
          <p>{user.username}</p>
        </div>
      </td>
      <td>{user.points}</td>
      <td
        className={`${
          user.wins > user.losses
            ? 'text-success'
            : user.losses > user.wins
            ? 'text-danger'
            : ''
        }`}
      >{`${user.wins}-${user.losses}`}</td>
    </tr>
  );
}
