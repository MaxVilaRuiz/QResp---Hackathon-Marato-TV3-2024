const express = require('express');
const app = express();
const mongoose = require('mongoose');

//mongoose.connect('mongodb://localhost:27017')

app.get('/', (req, res) => {
    res.send('<hl>Hello, Express.js Server! 8==========D</h1>');
});

const port = process.env.PORT || 27017;

app.listen(port, () => {
    console.log(`Server is running on port ${port}`);
});


