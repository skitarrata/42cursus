import { useState, useEffect, useContext } from 'react';
import { Context } from '../../App';
import { JoinChannelPkg, ShortChannel } from '../../models/Chat.interface';
import { Password } from 'primereact/password';
import { Button } from 'primereact/button';

interface Prop {
  setVisibility: Function;
  isVisible: string;
  errorVisibility: string;
  request: JoinChannelPkg;
  banVisibility: string;
  setBanVisibility: Function;
  setErrorVisibility: Function;
  chan: ShortChannel | undefined;
}

export default function CheckPass({
  isVisible,
  setVisibility,
  errorVisibility,
  request,
  banVisibility,
  setBanVisibility,
  setErrorVisibility,
  chan,
}: Prop) {
  const [pass, setPass] = useState('');
  const socket = useContext(Context).socket;

  function enterSubmit(e: any) {
    if (e.code === 'Enter') {
      request.key = pass;
      socket?.emit('joinRoom', request);
    }
  }

  useEffect(() => {}, [banVisibility]);

  return (
    <div
      className={`container ${isVisible}`}
      style={{
        zIndex: 100,
      }}
    >
      <div className="mb-sm-3 contacts_card" onKeyDown={enterSubmit}>
        <div className="contacts_body card-body scrollable-searchGroup">
          {chan?.mode === 'PRO' && (
            <>
              <div className="glow">Insert password</div>
              <div className="input-group">
                <Password
                  value={pass}
                  onChange={(e) => setPass(e.target.value)}
                  toggleMask
                  feedback={false}
                  className="form-control search"
                  placeholder="Password..."
                />
                <div className="input-group-prepend">
                  <Button
                    icon="pi pi-check"
                    onClick={() => {
                      request.key = pass;
                      socket?.emit('joinRoom', request);
                    }}
                    className="p-button-rounded p-button-success"
                  />
                </div>
              </div>
            </>
          )}
          {banVisibility === 'visible' && errorVisibility === 'hidden' ? (
            <div className="glow text-danger">YOU ARE BANNED</div>
          ) : banVisibility === 'hidden' && errorVisibility === 'visible' ? (
            <div className="glow text-danger">Wrong Password</div>
          ) : null}
        </div>
      </div>
    </div>
  );
}
