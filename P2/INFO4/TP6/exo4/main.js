
const form = document.getElementById("f");

form.addEventListener("submit",e => {
    e.preventDefault();
    const data = new FormData(e.target);
    fetch('traitement.php', {
        method: 'POST',
        body:data
    
    })
    .then(response => response.text())
    .then(result => {
        document.getElementById('f').innerHTML = result;
    })    
})
