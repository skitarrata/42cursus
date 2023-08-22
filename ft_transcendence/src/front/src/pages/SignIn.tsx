import { useLocation, useNavigate } from 'react-router-dom';
import memoji from '../assets/image.png';
import logo42 from '../assets/42_Logo.svg.png';
import { useEffect, useState } from 'react';

export default function SignIn() {
  let location = useLocation();
  const [authed, setAuthed] = useState(false);
  const navigate = useNavigate();

  let from = (location.state as { from: { pathname: string } }) || {
    from: { pathname: '/' },
  };

  if (!from) from = { from: { pathname: '/' } };

  const url =
    'https://api.intra.42.fr/oauth/authorize?client_id=' +
    process.env.REACT_APP_CLIENT_ID +
    '&redirect_uri=' +
    process.env.REACT_APP_REDIRECT_URI +
    '&response_type=code' +
    '&state=' +
    from.from.pathname;

  useEffect(() => {
    async function getAuth() {
      const res = await fetch(`/api/user`, { credentials: 'include' });
      const data = await res.json();
      if (!data.two_fa) {
        // navigate(-1);
      } else {
        setAuthed(false);
      }
    }
    getAuth();
    // eslint-disable-next-line react-hooks/exhaustive-deps
  }, []);

  // if (authed) {
  //   window.location.replace(url);
  // }
  return (
    <div className="d-flex flex-column align-items-center justify-content-center vh-100">
      <div
        className="bg-white rounded-circle overflow-hidden d-flex align-items-center justify-content-center shadow-sm p-3 mb-4"
        style={{ width: '150px', height: '150px' }}
      >
        <img
          src={memoji}
          alt="memoji"
          className="w-100 h-100 object-fit-cover"
          style={{ borderRadius: '50%' }}
        />
      </div>
      <div className="" style={{ maxWidth: '400px' }}>
        <button
          onClick={() => window.location.replace(url)}
          style={{ backgroundColor: 'white', color: 'black' }}
          className="btn btn-block btn-hover-paderi"
        >
          Sign in with{' '}
          <img src={logo42} alt="42 Logo" style={{ width: '20px' }} />{' '}
        </button>
      </div>
    </div>
  );
}
