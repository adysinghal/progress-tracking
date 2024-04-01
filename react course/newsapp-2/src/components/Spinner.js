import React, { PureComponent } from 'react'
import loading from "../spinner.gif"

export class Spinner extends PureComponent {
  render() {
    return (
      <div>
        <div className="text-center">
        <img height="30px" src={loading} alt="loading" />
        </div>
      </div>
    )
  }
}

export default Spinner