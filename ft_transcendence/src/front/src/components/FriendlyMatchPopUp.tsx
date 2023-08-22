import { useNavigate } from 'react-router-dom';
import { User } from '../models/User.interface';
import { useEffect, useRef } from 'react';
import { Toast } from 'primereact/toast';

import { Button } from 'primereact/button';

interface Friend {
  id: number;
  username: string;
}

export default function FriendlyMatchPopUp({
  friend,
  onClose,
  user,
}: {
  friend: Friend | undefined;
  onClose: () => void;
  user: User | undefined;
}) {
  const navigate = useNavigate();
  const toastBC = useRef<Toast>(null);

  const acceptMatch = () => {
    navigate('/game', {
      state: {
        id: user?.id,
        username: user?.username,
        avatar: user?.avatar,
        requesting: false,
        idRequesting: friend?.id,
      },
    });
  };

  useEffect(() => {
    if (friend) showConfirm();
  }, []);

  const showConfirm = () => {
    if (toastBC.current) {
      toastBC.current.show({
        severity: 'warn',
        sticky: true,
        content: (
          <div className="flex flex-column" style={{ flex: '1' }}>
            <div className="text-center">
              <i
                className="pi pi-exclamation-triangle"
                style={{ fontSize: '3rem' }}
              ></i>
              <h1>{friend?.username}</h1>
              <h4>Invited you to a friendly match</h4>
            </div>
            <div
              className="p-fluid"
              style={{ display: 'flex', flexDirection: 'row' }}
            >
              <div className="col-6">
                <Button
                  type="button"
                  label="Let's Pong"
                  className="p-button-success"
                  onClick={acceptMatch}
                />
              </div>
              <div className="col-6">
                <Button
                  onClick={onClose}
                  type="button"
                  label="Not Now"
                  className="p-button-secondary"
                />
              </div>
            </div>
          </div>
        ),
      });
    }
  };

  return (
    <Toast ref={toastBC} position="bottom-center" />

    /*     <div
      style={{
        visibility: 'visible', //typeof friend !== 'undefined' ? 'visible' : 'hidden',
        opacity: 1, //typeof friend !== 'undefined' ? '1' : '0',
        display: 'grid',
        placeItems: 'center',
      }}
      className="overlay"
    >

      
      <div className="friendly-match-popup" style={{ color: 'white' }}>
        <h1>{friend?.username}</h1>
        <h3>invited you to a friendly match</h3>
        <div
          className="friendly-buttons"
          style={{ display: 'flex', justifyContent: 'center', gap: '1rem' }}
        >
          <button className="game-popup-btn btn-play" onClick={acceptMatch}>
            LET'S PONG
          </button>
          <button
            className="game-popup-btn btn-home"
            onClick={() => {
              onClose();
            }}
          >
            NOT NOW
          </button>
        </div>
      </div>
    </div> */
  );
}
