import './App.css';
import About from './components/About';
import Navbar from './components/Navbar';
import Textform from './components/Textform';
import React, {useState} from 'react'

function App() {
  
  const [mode, setMode] = useState('light');

  const toggleMode = ()=>{
    if(mode === 'light'){
      setMode('dark');
      document.body.style.backgroundColor = '#122e41e6';
    }else{
      setMode('light');
      document.body.style.backgroundColor = 'white';
    }
  }
  
  return (
    <>
    <Navbar title="TextUtils" button1="Home" button2="About" mode={mode} toggleMode={toggleMode}/>
    <div className="container my-3">
      <Textform heading="Enter the text to analyze." mode={mode} />
      {/* <About className="my-3"/> */}


    </div>
    </>
  );
}

export default App;