import React, { useState } from 'react'

export default function Textform(props) {
    const[text, setText] = useState('Enter text here.');
    
    const handleUpClick = () =>{
        // console.log("Uppercase button was clicked.");
        let newText = text.toUpperCase();
        setText(newText);
    }
    
    const handleLoClick = () =>{
        // console.log("Uppercase button was clicked.");
        let newText = text.toLowerCase();
        setText(newText);
    }
    
    const handleOnChange = (event) =>{
        // console.log("Text was changed.");
        setText(event.target.value);
    }

  return (
    <>
    <div className='container'>
        <h1>{props.heading}</h1>
        <div className="mb-3">
        <textarea className="form-control" value={text} onChange={handleOnChange} id="myBox" rows="8"></textarea>
        </div>
        <button className="btn btn-primary mx-1" onClick={handleUpClick}>Convert to Uppercase</button>
        <button className="btn btn-primary mx-1" onClick={handleLoClick}>Convert to Lowercase</button>
    </div>

    <div className="container my-3">
        <h1>Your Text Summary</h1>
        <p>{text.split(" ").length} words & {text.length} character.</p>

        <h2>Preview</h2>
        <p>{text}</p>
    </div>

    </>
  )
}
