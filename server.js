const express = require('express');
const mongoose = require('mongoose');
const path = require('path');
const bcrypt = require('bcryptjs');
const jwt = require('jsonwebtoken');

const app = express();
const PORT = 3000;

mongoose.connect('mongodb://127.0.0.1:27017/auth')
  .then(() => console.log('Conectado a MongoDB'))
  .catch((error) => console.error('Error al conectar a MongoDB', error));

// --USER SIGNUP LOGIN--

const userSchema = new mongoose.Schema({
  username: String,
  password: String
});
  
const User = mongoose.model('User', userSchema);
  
app.use(express.json());
app.use(express.static('public'));
app.use((req, res, next) => {
  if(req.path.endsWith('.js'))
  {
    res.setHeader('Content-Type', 'application/javascript');
  }
  next();
});

const verifyToken = (req, res, next) => {
  const token = req.headers['authorization'];
  if(!token)
  {
    console.log(token);
    return res.status(401).json({ error: 'Unauthorized' });
  }
  
  jwt.verify(token, 'secret', (err, decoded) => {
    if(err)
    {
      return res.status(401).json({ error: err.mes });
    }
      req.user = decoded;
      next();
  });
};

// REGISTER
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
    res.status(500).json({ error: toString(error) });
  }
});

// LOGIN
app.post('/', async (req, res) => {
  try {
    const user = await User.findOne({ username: req.body.username });
    if(!user)
    {
      return res.status(401).json({ success: false, message: 'Estas fora!' });
    }

    const passwordMatch = await bcrypt.compare(req.body.password, user.password);
    if(!passwordMatch)
    {
      return res.status(401).json({ success: false, message: 'Contrassenya mal!' });
    }
    
    const id = user._id;
    //const token = jwt.sign({ username: user.username }, 'secret');
    return res.status(200).json({ success: true, redirectUrl: `/api/user/${id}`});
    //res.status(200).json({ token });
  } catch (error){
    res.status(500).json({ success: false, message: 'MAL!' });
  }
});

//GET USER DETAILS
app.get('/api/user/:id', async (req, res) => {
  const userId = req.params.id;
  res.sendFile(path.join(__dirname, 'public', ''));
  try {
    const user = await User.findById(userId); 
    if(!user) {
      return res.status(404).json({ error: 'User not found' });
    }
    res.status(200).json({ username: user.username });
  } catch {
    res.status(500).json({ error: 'Internal server error' });
  }
});

app.listen(PORT, () => {
    console.log(`Server is running on port ${PORT}`);
});