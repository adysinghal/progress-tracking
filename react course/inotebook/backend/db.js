const mongoose = require('mongoose');
// const mongoURI  = "mongodb://localhost:27017";
const mongoURI = "mongodb://0.0.0.0:27017/inotebook";
// const mongoURI = "mongodb://localhost:27017/?readPreference=primary&appname=MongoDB%20Compass&directConnection=true&ssl=false"


const connectToMongo = () => {
    mongoose.connect(mongoURI,()=>{
        console.log("Connected to Mongo successfully");
    } )
    // mongoose.connect(mongoURI, {
    //     useCreateIndex: true
    // })
}

module.exports = connectToMongo;