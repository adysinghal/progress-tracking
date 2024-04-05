import React, { PureComponent } from 'react'
import loading from "../spinner.gif"

const Spinner = () => {

    return (
      <div>
        <div className="text-center">
        <img className='my-3' height="30px" src={loading} alt="loading" />
        </div>
      </div>
    )
}

export default Spinner