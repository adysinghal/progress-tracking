const express = require('express');
const router = express.Router();
const Note = require('../models/Note');
var fetchuser = require('../middleware/fetchuser');
const { body, validationResult } = require('express-validator');



// ROUTE 1: Get all the notes using: GET "/api/notes/fetchallnotes". Login requried
router.get('/fetchallnotes', fetchuser, async (req, res) => {
    try {
        const notes = await Note.find({ user: req.user.id });
        res.json(notes);

    } catch (error) {
        console.error(error.message);
        res.status(500).send("Internal Server Error.");
    }
})


// ROUTE 2: Add a new Note: POST "/api/notes/addnote". Login requried
router.post('/addnote', fetchuser, [
    body('title', 'Enter a valid title.').isLength({ min: 3 }),
    body('description', 'Description must be atleast 5 characters.').isLength({ min: 5 }),
], async (req, res) => {

    try {
        const { title, description, tag } = req.body;
        const errors = validationResult(req);
        if (!errors.isEmpty()) {
            return res.status(400).json({ errors: errors.array() });
        }

        const note = new Note({
            title, description, tag, user: req.user.id
        })
        const savedNote = await note.save();

        res.json(savedNote);
    } catch (error) {
        console.error(error.message);
        res.status(500).send("Internal Server Error.");
    }

})


// ROUTE 3: Update an existing note: PUT "/api/notes/updatenote". Login requried
router.put('/updatenote/:id', fetchuser, async (req, res) => {
    const { title, description, tag } = req.body;

    try {
        const newNote = {};
        if (title) { newNote.title = title };
        if (description) { newNote.description = description };
        if (tag) { newNote.tag = tag };

        // find the note to be updated and update it 
        let note = await Note.findById(req.params.id);

        // noteId not found
        if (!note) { return res.status(404).send("Not found.") }

        // unauthorized user trying to access the string
        if (note.user.toString() != req.user.id) { return res.status(401).send("Not allowed.") }

        note = await Note.findByIdAndUpdate(req.params.id, { $set: newNote }, { new: true });
        res.json({ note });
    } catch (error) {
        console.error(error.message);
        res.status(500).send("Internal Server Error.");
    }
    // create a new note object

})

// ROUTE 4: Delete an existing note: DELETE "/api/notes/deletenote". Login requried
router.delete('/deletenote/:id', fetchuser, async (req, res) => {

    try {
        // find the note to be deleted and delete it 
        let note = await Note.findById(req.params.id);

        // noteId not found
        if (!note) { return res.status(404).send("Not found.") }

        // prevent unauthorized user trying to access the string
        if (note.user.toString() != req.user.id) { return res.status(401).send("Not allowed.") }

        note = await Note.findByIdAndDelete(req.params.id);
        res.json({ "Success": "Note has been deleted", note: note });
    } catch (error) {
        console.error(error.message);
        res.status(500).send("Internal Server Error.");
    }


})



module.exports = router