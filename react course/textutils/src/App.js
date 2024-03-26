import Alert from './components/Alert';
import './App.css';
import About from './components/About';
import Navbar from './components/Navbar';
import Textform from './components/Textform';
import React, { useState } from 'react'

function App() {

  const [mode, setMode] = useState('light');
  const [alert, setAlert] = useState(null);

  const showAlert = (message, type) => {
    setAlert({
      msg : message,
      type : type,
    })

    setTimeout(() => {
      setAlert(null);
    }, 1500);
  }

  const toggleMode = () => {
    if (mode === 'light') {
      setMode('dark');
      document.body.style.backgroundColor = '#122e41e6';
      showAlert("Dark mode has been set", "success");
    } else {
      setMode('light');
      document.body.style.backgroundColor = 'white';
      showAlert("Light mode has been set", "success");
    }
  }

  return (
    <>
    <Navbar title="TextUtils" button1="Home" button2="About" mode={mode} toggleMode={toggleMode} />
    <Alert alert={alert}/>
    <div className="container my-3">
    <Textform showAlert={showAlert} heading="Enter the text to analyze." mode={mode} />
    
    </div>
    </>
  );
}

export default App;