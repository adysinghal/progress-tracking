import React, { useState } from 'react'

export default function Textform(props) {
    const[text, setText] = useState('Enter text here.');
    
    const handleUpClick = () =>{
        // console.log("Uppercase button was clicked.");A
        let newText = text.toUpperCase();
        setText(newText);
    }
    
    const handleLoClick = () =>{
        // console.log("Uppercase button was clicked.");
        let newText = text.toLowerCase();
        setText(newText);
    }

    const handleClearText = () =>{
        setText('');
    }
    
    const handleOnChange = (event) =>{
        // console.log("Text was changed.");
        setText(event.target.value);
    }

    
  return (
    <>
    
    <div className='container' style={{color: props.mode === 'light' ? '#122e41e6' : 'white'}}>
        <h1>{props.heading}</h1>
        <div className="mb-3">
        <textarea className="form-control" value={text} style={{backgroundColor: props.mode === 'light' ? 'white' : '#ffffffc4'}} onChange={handleOnChange} id="myBox" rows="8"></textarea>
        </div>
        <button className="btn btn-primary mx-1" onClick={handleUpClick}>Convert to Uppercase</button>
        <button className="btn btn-primary mx-1" onClick={handleLoClick}>Convert to Lowercase</button>
        <button className="btn btn-primary mx-1"onClick={handleClearText}>Clear Text</button>
    </div>

    <div className='container my-3' style={{color: props.mode === 'light' ? '#122e41e6' : 'white'}}>
        <h1>Your Text Summary</h1>
        <p>
            {text.length === 0
            ? 'No text.'
            : `${text.split(" ").length} words & ${text.length} characters.`
            }
        </p>

        <h2>Preview</h2>
        <p>{text.length>0 ? text : "Enter text."}</p>
    </div>

    </>
  )
}
