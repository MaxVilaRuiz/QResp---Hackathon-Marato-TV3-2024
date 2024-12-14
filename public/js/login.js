function login() {
    let email = document.getElementById('email');
    let password = document.getElementById('password');
    // window.location.href = "/Frontend/html/userpage.html";

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
        if(data.success) {
            alert(data.message);
        } else {
            alert(data.message);
        }
    })
    .catch(error => console.error('Error: ', error));

    console.log(email.value);
    console.log(password.value);
}