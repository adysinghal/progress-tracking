import React from 'react'
import PropTypes from 'prop-types'

export default function Navbar(props) {
    return (

        <nav className={`navbar navbar-expand-lg navbar-${props.mode} bg-${props.mode}`}>

            <div className="container-fluid">
                <a className="navbar-brand" href="/">{props.title}</a>
                <button className="navbar-toggler" type="button" data-bs-toggle="collapse" data-bs-target="#navbarSupportedContent" aria-controls="navbarSupportedContent" aria-expanded="false" aria-label="Toggle navigation">
                    <span className="navbar-toggler-icon"></span>
                </button>
                <div className="collapse navbar-collapse" id="navbarSupportedContent">
                    <ul className="navbar-nav me-auto mb-2 mb-lg-0">
                        <li className="nav-item">
                            <a className="nav-link active" aria-current="page" href="/">{props.button1}</a>
                        </li>
                        <li className="nav-item">
                            <a className="nav-link" href="/">{props.button2}</a>
                        </li>
                    </ul>
                    {/* <div className={`form-check form-switch mx-3 text-${props.mode==='light'?'dark':'light'}`}>
                        <input className="form-check-input" type="checkbox" role="switch" onClick={props.toggleMode} id="flexSwitchCheckDefault"/>
                            <label className="form-check-label" htmlFor="flexSwitchCheckDefault">Enable Dark Mode</label>
                    </div> */}
                    <button type="button" className="btn btn-primary mx-1" onClick={props.colorMode('blue')}>Blue</button>
                    <button type="button" className="btn btn-secondary mx-1" onClick={props.colorMode('grey')}>Grey</button>
                    <button type="button" className="btn btn-success mx-1" onClick={props.colorMode('green')}>Green</button>
                    <button type="button" className="btn btn-danger mx-1" onClick={props.colorMode('red')}>Red</button>
                    <button type="button" className="btn btn-light mx-1" onClick={props.colorMode('light')}>Light</button>
                    <button type="button" className="btn btn-dark mx-1" onClick={props.colorMode('dark')}>Dark</button>
                </div>
            </div>
        </nav>
    )
}

Navbar.propTypes = {
    title: PropTypes.string.isRequired,     // isRequired ensures that it gives error if props are not sent
    button1: PropTypes.string,
    button2: PropTypes.string
}

// default props (if they are not sent)
Navbar.defaultProps = {
    title: "Set title",
    button1: "Configure button1",
    button2: "Configure button2"
}