import Alert from './components/Alert';
import './App.css';
import About from './components/About';
import Navbar from './components/Navbar';
import Textform from './components/Textform';
import React, { useState } from 'react'

function App() {

  const [mode, setMode] = useState('light');
  const [alert, setAlert] = useState(null);
  const [color, setColor] = useState(null);

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

  const colorMode = (color) => {
    if(color === 'blue'){
      setColor('blue');
      document.body.style.backgroundColor = 'blue';
    }
    else if(color == 'grey'){
      setColor('grey');
      document.body.style.backgroundColor = 'grey';
    }
    else if(color == 'green'){
      setColor('green');
      document.body.style.backgroundColor = 'green';
    }
    else if(color == 'red'){
      setColor('red');
      document.body.style.backgroundColor = 'red';
    }
    else if(color == 'light'){
      setColor('light');
      document.body.style.backgroundColor = 'white';
    }
    if(color == 'dark'){
      setColor('dark');
      document.body.style.backgroundColor = 'black';
    }
  }

  return (
    <>
    <Navbar title="TextUtils" button1="Home" button2="About" mode={mode} toggleMode={toggleMode} colorMode={colorMode}/>
    <Alert alert={alert}/>
    <div className="container my-3">
    <Textform showAlert={showAlert} heading="Enter the text to analyze." mode={mode} />
    
    </div>
    </>
  );
}

export default App;