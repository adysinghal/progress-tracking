import './App.css';
import Navbar from './components/Navbar';
import Textform from './components/Textform';

function App() {
  return (
    <>
    <Navbar title="TextUtils" button1="Home" button2="About" />
    <div className="container my-3">
      <Textform heading="Enter the text to analyze." />
    </div>
    </>
  );
}

export default App;