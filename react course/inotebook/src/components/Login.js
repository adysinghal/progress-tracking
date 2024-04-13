import React, { useState } from 'react'
import { useNavigate } from 'react-router';


const Login = (props) => {

    const [credentials, setCredentials] = useState({email:"", password:""});
    let navigate = useNavigate();

    const handleSubmit = async (e) => {
        e.preventDefault();
        const response = await fetch("http://localhost:5000/api/auth/login", {
            method: 'POST',
            headers: {
                
                'Content-Type': 'application/json'
            },
            body: JSON.stringify({email: credentials.email, password:credentials.password})
        });
        const json = await response.json();
        console.log(json);

        if(json.success){
            // redirect
            // save Auth token and redirect
            localStorage.setItem('token', json.authToken);
            props.showAlert("Logged in successfully", "success")
            navigate("/");
        }else{
            alert("Invalid credentials.")
            props.showAlert("Invalid details", "danger")
        }
    }

    const onChange = (e) => {
        setCredentials({ ...credentials, [e.target.name]: e.target.value })
    }


    return (
        <div className='mt-3'>
            <h2>Login to access iNotebook</h2>
            <form onSubmit={handleSubmit}>
                <div className="my-1 form-group">
                    <label htmlFor="email">Email address</label>
                    <input type="email" className="my-1 form-control" onChange={onChange} value={credentials.email} id="email" name='email' aria-describedby="emailHelp" placeholder="Enter email" />
                    <small id="emailHelp" className="my-1 form-text text-muted">We'll never share your email with anyone else.</small>
                </div>
                <div className="my-1 form-group">
                    <label htmlFor="password">Password</label>
                    <input type="password" className="my-1 form-control" onChange={onChange} value={credentials.password} id="password" name='password' placeholder="Password" />
                </div>

                <button type="submit" className="my-1 btn btn-primary">Submit</button>
            </form>
        </div>
    )
}

export default Login