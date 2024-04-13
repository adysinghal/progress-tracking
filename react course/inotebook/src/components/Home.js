import React from 'react'
import Notes from './Notes';
import AddNote from './AddNote';


export const Home = (props) => {
  const {showAlert} = props;
  return (
    <>
      <Notes showAlert={showAlert}/>
    </>
  )
}

export default Home