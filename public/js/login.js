
function login() {
    const email = document.getElementById('email').value;
    const password = document.getElementById('password').value;
    // window.location.href = "/Frontend/html/userpage.html";

    console.log(email);

    const credentials = {
        username: email,
        password: password
    };

    fetch('/', { 
        method: 'POST',
        headers: {
            'Content-Type':  'application/json'
        },
        body: JSON.stringify(credentials)
    })
    .then(response => response.json())
    .then(data => {
        if(data.success)
        {
            window.location.href = data.redirectUrl;
        }
        else
        {
            console.log('error login');
            alert(data.message);
        }
    })  
    .catch(error => console.error('Error: ', error));
}