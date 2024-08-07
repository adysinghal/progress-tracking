import React, { useState } from 'react'
import { useNavigate } from 'react-router';



const Signup = (props) => {

    const [credentials, setCredentials] = useState({name:"", email:"", password:"", cpassword:""});
    let navigate = useNavigate();

    const handleSubmit = async (e) => {
        e.preventDefault();
        const {name, email, password} = credentials;
        const response = await fetch("http://localhost:5000/api/auth/createUser", {
            method: 'POST',
            headers: {
                
                'Content-Type': 'application/json'
            },
            body: JSON.stringify({name, email, password})
        });
        const json = await response.json();
        console.log(json);

        if(json.success){
            // redirect
            // save Auth token and redirect
            localStorage.setItem('token', json.authToken);
            navigate("/");
            props.showAlert("Account created successfully", "success")
        }else{
            props.showAlert("Invalid credentials", "danger")
        }
    }

    const onChange = (e) => {
        setCredentials({ ...credentials, [e.target.name]: e.target.value })
    }
    
    return (
        <div className='container my-3'>
            <h2>Sign-up to access iNotebook</h2>
            <form onSubmit={handleSubmit}>
                <div className="form-group my-3">
                    <label htmlFor="name">Name</label>
                    <input type="name" className="form-control" name="name" id="name" aria-describedby="emailHelp" placeholder="Enter name" onChange={onChange} required minLength={5}/>
                </div>
                <div className="form-group my-3">
                    <label htmlFor="email">Email address</label>
                    <input type="email" className="form-control" name='email' id="email" aria-describedby="emailHelp" placeholder="Enter email" onChange={onChange} required minLength={5}/>
                        <small id="emailHelp" className="form-text text-muted">We'll never share your email with anyone else.</small>
                </div>
                <div className="form-group my-3">
                    <label htmlFor="password">Password</label>
                    <input type="password" className="form-control" name='password' id="password" placeholder="Password" onChange={onChange} required minLength={5}/>
                </div>
                <div className="form-group my-3">
                    <label htmlFor="cpassword">Confirm Password</label>
                    <input type="password" className="form-control" name='cpassword' id="cpassword" placeholder="Password" onChange={onChange} required minLength={5}/>
                </div>
                <button type="submit" className="btn btn-primary my-3">Submit</button>
            </form>
        </div>
    )
}

export default Signup