const express = require('express');
const mongoose = require('mongoose');
const path = require('path');
const bcrypt = require('bcryptjs');
const jwt = require('jsonwebtoken');
const axios = require('axios');
const xml2js = require('xml2js');

const app = express();
const PORT = 3000;

mongoose.connect('mongodb://127.0.0.1:27017/auth')
  .then(() => console.log('Conectado a MongoDB'))
  .catch((error) => console.error('Error al conectar a MongoDB', error));
// --USER SIGNUP LOGIN--

const userSchema = new mongoose.Schema({
  username: String,
  password: String,
  disease: String,
  random: String
});

const Disease = mongoose.model('Malalties', new mongoose.Schema({
  _id: String,
  name: String,
  diagnostic: String,
  recommendation: String
}));

const Symptom = mongoose.model('Simptomes', new mongoose.Schema({
  name: String
}));

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

// REGISTER
app.post('/api/register', async (req, res) => {
  try {
    const existingUser = await User.findOne({ username: req.body.username });
    if(existingUser)
    {
      console.log('MAL');
      return res.status(400).json({ success: false, message: 'El usuari ja existeix!'});  
    }

    const hashedPassword = await bcrypt.hash(req.body.password, 10);

    const newUser = new User({
      username: req.body.username,
      password: hashedPassword,
    });

    await newUser.save();
    const id = newUser._id;
    res.status(201).json({ success: true, message: 'Usuari registrat!', 
      redirectUrl: `/api/user/${id}`});
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
      return res.status(401).json({ success: false, message: 'Les credencials son incorrectes.' });
    }

    const passwordMatch = await bcrypt.compare(req.body.password, user.password);
    if(!passwordMatch)
    {
      return res.status(401).json({ success: false, message: 'La contrassenya es incorrecte.' });
    }
    
    const id = user._id;
    //const token = jwt.sign({ username: user.username }, 'secret');
    return res.status(200).json({ success: true, redirectUrl: `/api/user/${id}`});
    //res.status(200).json({ token });
  } catch (error){
    res.status(500).json({ success: false, message: 'Error al servidor.' });
  }
});

//GET USER DETAILS
app.get('/api/user/:id', async (req, res) => {
  const userId = req.params.id;
  res.sendFile(path.join(__dirname, 'public', 'html', 'userpage.html'));
  const symptoms = [ 'fatiga', 'bategs' ];
  try {

    const diseases = await Disease.find();
    let diseaseScores = {};

    diseases.forEach(disease => {
      const id = disease._id;
      diseaseScores[id] = 0;
    });

    const ts = false;
    const sd = false;
    const dt = false;
    const toss = false;
    const xr = false;

    symptoms.forEach(symptomId => {
      if(symptomId === 'fatiga')
      {
        diseaseScores['insuficiencia'] += 1;
      }

      if(symptomId === 'bategs')
      {
        diseaseScores['insuficiencia'] += 2;
      }

      if(symptomId === 'inflamacio')
      {
        diseaseScores['insuficiencia'] += 2;
      }

      if(symptomId === 'augment_de_pes')
      {
        diseaseScores['insuficiencia'] += 3;
      }

      if(symptomId === 'mal_pit')
      {
        diseaseScores['trombolisme'] += 1;
      }

      if(symptomId === 'tosir_sang')
      {
        diseaseScores['trombolisme'] += 2;
        ts = true;
      }

      if(symptomId === 'respiracio_accelerada')
      {
        diseaseScores['trombolisme'] += 1;
      }

      if(symptomId === 'febre')
      {
        diseaseScores['trombolisme'] += 1;
      }

      if(symptomId === 'convulsions')
      {
        diseaseScores['trombolisme'] += 2;
      }

      if(symptomId === 'mal_de_cap')
      {
        diseaseScores["toxics"] += 1;
      }

      if(symptomId === 'nausees')
      {
        diseaseScores["toxics"] += 1
        diseaseScores["contusio"] += 1;
      }

      if(symptomId === 'somnolencia')
      {
        diseaseScores["toxics"] += 3;
      }

      if(symptomId === 'tos')
      {
        diseaseScores["toxics"] += 1;
        diseaseScores["exacerbacio"] += 1;
      }

      if(symptomId === 'mal_de_traquea')
      {
        diseaseScores["toxics"] += 2;
      }

      if(symptomId === 'mal_als_pulmons')
      {
        diseaseScores["toxics"] += 2;
      }

      if(symptomId === 'confusio')
      {
        diseaseScores["toxics"] += 1;
      }

      if(symptomId === 'mucosa_irritada')
      {
        diseaseScores["refluxe"] += 3;
      }

      if(symptomId === 'acidesa')
      {
        diseaseScores["refluxe"] += 1;
      }

      if(symptomId === 'sagnat_digestiu')
      {
        diseaseScores["refluxe"] += 2;
        diseaseScores["abdomen"] += 2;
        sd = true;

        if(ts) diseaseScores["abdomen"] += 1;
      }

      if(symptomId === 'vomit_persistent')
      {
        diseaseScores["refluxe"] += 2;
      }

      if(symptomId === 'perdua_de_pes')
      {
        diseaseScores["refluxe"] += 1;
      }

      if(symptomId === 'taquicardia')
      {
        diseaseScores["abdomen"] += 1;
      }

      if(symptomId === 'ictericia')
      {
        diseaseScores["abdomen"] += 2;
      }

      if(symptomId === 'sang_orina')
      {
        diseaseScores["abdomen"] += 3;
        if(ts && sd && diseaseScores['abdomen'] < Disease.findById('abdomen').pt)
        {
          diseaseScores["abdomen"] += 1;
        }
        else if(ts && !sd)
        {
          diseaseScores["abdomen"] += 1;
        }
        else if(!ts && sd)
        {
          diseaseScores["abdomen"] += 1;
        }
      }

      if(symptomId === 'dolor_toracic')
      {
        diseaseScores["pneumotorax"] += 2;
        diseaseScores["contusio"] += 2;
        dt = true;
      }

      if(symptomId === 'falta_aire')
      {
        diseaseScores["pneumotorax"] += 2;
        diseaseScores["contusio"] += 2;
        diseaseScores["exacerbacio"] += 2;

        if(dt && (!toss && !xr))
        {
          diseaseScores["pneumotorax"] += 2;
        }
        else if(dt && (!toss || !xr))
        {
          diseaseScores["pneumotorax"] += 1;
        }
      }

      if(symptomId === 'tos_seca')
      {
        diseaseScores["pneumotorax"] += 2;
        toss = true;
      }

      if(symptomId === 'xiuleig_al_respirar')
      {
        diseaseScores["pneumotorax"] += 1;
        xr = true;
      }

      if(symptomId === 'coloritzacio_blavosa')
      {
        diseaseScores["exacerbacio"] += 3;
      }

      diseaseScores["pneumotorax"] /= Disease.findById('pneumotorax').pt;
      diseaseScores["insuficiencia"] /= Disease.findById('insuficiencia').pt;
      diseaseScores["trombolisme"] /= Disease.findById('trombolisme').pt;
      diseaseScores["toxics"] /= Disease.findById('toxics').pt;
      diseaseScores["refluxe"] /= Disease.findById('refluxe').pt;
      diseaseScores["abdomen"] /= Disease.findById('abdomen').pt;
      diseaseScores["contusio"] /= Disease.findById('contusio').pt;
      diseaseScores["exerbacio"] /= Disease.findById('exerbacio').pt;
      diseaseScores["pneumonia"] /= Disease.findById('pneumonia').pt;

      const results = [];

      diseases.forEach(disease => {
        const result = [ disease.name, diseaseScores[disease.id], disease.diagnostic, disease.recommendation ];
        result.push(result);
      });

    })

  } catch {
    res.status(500).json({ error: 'Error de servidor.' });
  }
});

async function fetchMedicalArticles()
{
  const query = 'respiratory diseases';
  const apiUrl = `https://eutils.ncbi.nlm.nih.gov/entrez/eutils/esearch.fcgi?db=pubmed&term=${query}&retmax=5&retmode=json`;

  try {
    const response = await axios.get(apiUrl);
    const articleIds = response.data.esearchresult.idlist;

    const summaryUrl = `https://eutils.ncbi.nlm.nih.gov/entrez/eutils/esummary.fcgi?db=pubmed&id=${articleIds.join(',')}&retmode=json`;
    const articleSummary = await axios.get(summaryUrl);

    const articles = articleSummary.data.result;
    console.log(articles);
    return articles;
  } catch (error) {
    console.error('Error fetching articles: ' + error);
    return null;
  }
}

async function AnalizeArticle()
{

}

app.listen(PORT, () => {
    console.log(`Server is running on port ${PORT}`);
    //const articles = fetchMedicalArticles();
    //console.log(articles);
});