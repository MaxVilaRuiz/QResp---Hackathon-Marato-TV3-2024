
function register() {
    let name = document.getElementById('name').value;
    let email = document.getElementById('email').value;
    let password = document.getElementById('password').value;
    let password_rep = document.getElementById('repeat-password').value;

    if (password !== password_rep) {
        alert('Les contrassenyes no coincideixen.');
    }
    else
    {
        const credentials = {
            username: email,
            password: password
        }

        fetch('/api/register', {
            method: 'POST',
            headers: {
                'Content-Type': 'application/json'
            },
            body: JSON.stringify(credentials)
        })
        .then(response => response.json())
        .then(data => {
            if(data.success)
            {
                alert(data.message);
                window.location.href = data.redirectUrl;
            }
            else
            {
                alert(data.message);
            }
        })
    }

    console.log(name);
    console.log(email);
    console.log(password);
    console.log(password_rep);
}