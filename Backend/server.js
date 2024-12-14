const express = require('express');
const mongoose = require('mongoose');
const bcrypt = require('bcryptjs');
const jwt = require('jsonwebtoken');

const app = express();
const PORT = 3000;

mongoose.connect('mongodb://127.0.0.1:27017/concesionario')
  .then(() => console.log('Conectado a MongoDB'))
  .catch((error) => console.error('Error al conectar a MongoDB', error));

// --USER SIGNUP LOGIN--

const userSchema = new mongoose.Schema({
  username: String,
  password: String
});
  
const User = mongoose.model('User', userSchema);
  
app.use(express.json());
  
const verifyToken = (req, res, next) => {
  const token = req.headers['authoritzation'];
  if(!token)
  {
    return res.status(401).json({ error: 'Unauthorized' });
  }
  
  jwt.verify(token, 'secret', (err, decoded) => {
  if(err)
  {
    return res.status(401).json({ error: 'Unauthorized' });
  }
    req.user = decoded;
    next();
  });
};

app.post('/api/register', async (req, res) => {
  try {
    const existingUser = await User.findOne({ username: req.body.username });
    if(existingUser)
    {
      return res.status(400).json({ error: 'Username already exists.' });
    }

    const hashedPassword = await bcrypt.hash(req.body.password, 10);

    const newUser = new User({
      username: req.body.username,
      password: hashedPassword,
    });

    await newUser.save();
    res.status(201).json({ message: 'User registered successfully' });
  } catch (error){
    res.status(500).json({ error: 'Internal server error' });
  }
});

app.get('/', (req, res) => {
    res.send('Hello world!');
});

app.get('/api/register', (req, res) => {
  res.send('REGISTER!!!');
});

app.listen(PORT, () => {
    console.log(`Server is running on port ${PORT}`);
});