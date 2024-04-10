import NoteContext from "./noteContext";
import { useState } from "react";

const NoteState = (props) => {
    const host = "http://localhost:5000";
    const notesInitial = [];
    const [notes, setNotes] = useState(notesInitial)
    
    // Get all Notes
    const getNotes = async () => {
        // Api call
        const response = await fetch(`${host}/api/notes/fetchallnotes`, {
            method: 'GET',
            headers: {
                'auth-token': 'eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJ1c2VyIjp7ImlkIjoiNjYxMTJlYWFkN2U1ODBjMGFjNGZiODhmIn0sImlhdCI6MTcxMjQ4NDYwNH0.eHywLOz58wKIhrf9dL5l04-nCDTonUA2a8pVXbDTpoE',
                'Content-Type': 'application/json'
            }
        });
        const json = await response.json();
        console.log(json);
        setNotes(json);
    }


    // Add a note
    const addNote = async (title, description, tag) => {
        // Api call
        const response = await fetch(`${host}/api/notes/addnote`, {
            method: 'POST',
            headers: {
                'auth-token': 'eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJ1c2VyIjp7ImlkIjoiNjYxMTJlYWFkN2U1ODBjMGFjNGZiODhmIn0sImlhdCI6MTcxMjQ4NDYwNH0.eHywLOz58wKIhrf9dL5l04-nCDTonUA2a8pVXbDTpoE',
                'Content-Type': 'application/json'
            },
            body: JSON.stringify({title, description, tag})
        });
        const json = response.json();



        let note = {
            "_id": "6612711b46cc70129710fb4e12",
            "user": "66112eaad7e580c0ac4fb88f1",
            "title": title,
            "description": description,
            "tag": tag,
            "date": "2024-04-07T10:10:35.571Z",
            "__v": 0
        };
        setNotes(notes.concat(note));
    }

    // Delete a note
    const deleteNote = (id) => {
        // TODO: Api call
        console.log("Deleting note with id " + id);
        const newNotes = notes.filter((note) => { return note._id != id })
        setNotes(newNotes);
    }

    // Edit a note
    const editNote = async (id, title, description, tag) => {
        // Api call
        const response = await fetch(`${host}/api/notes/updatenote/${id}`, {
            method: 'POST',
            headers: {
                "auth-token": "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJ1c2VyIjp7ImlkIjoiNjYxMTJlYWFkN2U1ODBjMGFjNGZiODhmIn0sImlhdCI6MTcxMjQwMjEzOH0.P7sdJ4v9NWPXpWuKGEvYTg1PBPUezc9M1S63kmYIyhY",
                "Content-Type": "application/json"

            },
            body: JSON.stringify({title, description, tag})
        });
        const json = response.json();

        // logic to edit in client
        for (let index = 0; index < notes.length; index++) {
            const element = notes[index];
            if (element._id == id) {
                element.title = title;
                element.description = description;
                element.tag = tag;
            }
        }
    }


    return (
        <NoteContext.Provider value={{ notes, addNote, deleteNote, editNote, getNotes }}>
            {props.children}
        </NoteContext.Provider>
    )
}

export default NoteState;