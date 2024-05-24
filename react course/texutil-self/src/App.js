import logo from './logo.svg';
import './App.css';
import Navbar from './components/Navbar';
import Form from './components/Form';
import Alert from './components/Alert';
import { useState } from 'react';
import { Route, Routes } from 'react-router';


function App() {
  const [alert, setAlert] = useState(null)

  const showAlert = (message, type) => {
    setAlert({
      msg: message,
      type: type
    })

    setTimeout(() => {
      setAlert(null);
    }, 2000);
  }


  return (
    <>
      <Routes>
        <Navbar heading="TextApp" text1="Home" text2="About" />
        <Route path="/" element={
          <>
            <Alert alert={alert} />
            <Form showAlert={showAlert} />
          </>
        } />

        <Route path="about" element={<About/>}/>
/
      </Routes>
    </>

  );
}

export default App;
