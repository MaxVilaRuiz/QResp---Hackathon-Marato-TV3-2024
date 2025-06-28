# QResp – BitsxLaMarató 2024

**QResp** – Smart self-diagnosis for respiratory diseases.
Built during [BitsxLaMarató 2024](https://www.ccma.cat/tv3/marato/) in collaboration with **La Marató de TV3**, this web application empowers users to get a preliminary diagnosis based on input symptoms using a simple and fast interface. It aids healthcare professionals in triaging patients and offers users peace of mind with instant feedback from anywhere.


## Tech Stack

<table>
        <tr>
          <td><strong>Frontend:</strong></td>
          <td align="center">
            <img src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/javascript/javascript-original.svg" width="35" title="JavaScript"/>&nbsp;
            <img src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/html5/html5-original.svg" width="35" title="HTML5"/>&nbsp;
            <img src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/css3/css3-original.svg" width="35" title="CSS3"/>&nbsp;
          </td>
        </tr>
<tr>
            <td><strong>Backend:</strong></td>
            <td>
                <img src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/nodejs/nodejs-original.svg" width="35" title="Node.js"/>&nbsp;
                <img src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/javascript/javascript-original.svg" width="35" title="JavaScript"/>&nbsp;
            </td>
        </tr>
<tr>
            <td><strong>Database & Storage:</strong></td>
            <td>
                <img src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/nodejs/nodejs-original.svg" width="35" title="Node.js"/>&nbsp;
                <img src="https://raw.githubusercontent.com/github/explore/main/topics/json/json.png" width="35" title="JSON"/>&nbsp;
            </td>
        </tr>
      </table>


## Project Structure

```
QResp/
├── README.md                     # Project documentation
├── package.json                  # Node.js project metadata
├── package-lock.json             # Dependency lockfile
├── server.js                     # Entry point for backend logic
├── node_modules/                   # Auto-generated directory for installed dependencies

├── Algoritmes/                   # Diagnosis algorithm logic (C++ and compiled)
│   ├── a.cc
│   ├── a.x
│   ├── algorisme_1.cc
│   └── algorisme_1.x

├── DB/                           # JSON database with disease and symptom information
│   ├── malalties.json
│   └── simptomes.json

├── public/                       # Frontend assets
│   ├── index.html                # Main entry point
│   ├── css/                      # Stylesheets
│   │   ├── global.css
│   │   ├── index.css
│   │   ├── register.css
│   │   └── userpage.css
│   ├── html/                     # Page templates
│   │   ├── register.html
│   │   └── userpage.html
│   └── js/                       # Client-side logic
│       ├── login.js
│       ├── register.js
│       └── userpage.js
```


## Team & Credits

- [Max Vilà Ruiz](https://github.com/MaxVilaRuiz)
- [Pau Martínez Franch](https://github.com/taopaipau)
- [Aarón Quintanilla](https://github.com/aaronqintanilla)
- Max Gimeno Giro


## License

This project is licensed under the [MIT License](https://choosealicense.com/licenses/mit/) © License.