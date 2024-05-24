import React, { useState } from 'react'

function Form(props) {

    const [text, setText] = useState("");

    const handleOnChange = (event) => {
        setText(event.target.value)
    }

    const handleUppercase = (event) => {
        let tempText = text.toUpperCase();
        setText(tempText);
        props.showAlert("Converted to uppercase",  "success");
    }
    
    const handleLowercase = () => {
        let tempText = text.toLowerCase();
        setText(tempText);
        props.showAlert("Converted to lowercase",  "success");
    }

    const handleClearText = () => {
        setText("");
        props.showAlert("Cleared the text",  "danger");
    }

    return (
        <>
            <div className="container">
                <div className="mb-3 my-5">
                    <h2>
                        <label for="exampleFormControlInput1" className="form-label">Enter text</label>
                    </h2>
                    <input type="text" className="form-control" id="exampleFormControlInput1" onChange={handleOnChange} />
                    <a className="btn btn-primary mx-1 my-2" href="#" role="button" onClick={handleUppercase}>UpperCase</a>
                    <button className="btn btn-primary mx-1" type="submit" onClick={handleLowercase}>LowerCase</button>
                    <button className="btn btn-primary mx-1" type="submit" onClick={handleClearText}>Clear Text</button>
                </div>
                <div className="mb-3">
                    <h2>
                        <label for="exampleFormControlTextarea1" className="form-label" >Entered text.</label>
                    </h2>
                    <p style={{fontSize:20}}>{text}</p>
                    <p style={{color:'grey'}}>
                        {
                            text.length === 0 ? 'No text' :
                            `${text.split(" ").length} words & ${text.length} characters`
                        }
                    </p>

                </div>
            </div>
        </>
    )
}

export default Form