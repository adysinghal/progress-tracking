import NoteContext from "./noteContext";
import { useState } from "react";

const NoteState = (props) => {
    const notesInitial = [
        {
            "_id": "6612711246cc70129710fb4c",
            "user": "66112eaad7e580c0ac4fb88f",
            "title": "Test1",
            "description": "Badboy ady",
            "tag": "Personal",
            "date": "2024-04-07T10:10:26.935Z",
            "__v": 0
        },
        {
            "_id": "6612711b46cc70129710fb4e",
            "user": "66112eaad7e580c0ac4fb88f",
            "title": "Test1",
            "description": "Badboy ady",
            "tag": "Personal",
            "date": "2024-04-07T10:10:35.571Z",
            "__v": 0
        }
    ]
    const [notes, setNotes] = useState(notesInitial)

    return (
        <NoteContext.Provider value={{notes, setNotes}}>
            {props.children}
        </NoteContext.Provider>
    )
}

export default NoteState;