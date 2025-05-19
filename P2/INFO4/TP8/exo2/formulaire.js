const form = document.getElementById("leform")

form.addEventListener("submit", e => {
    e.preventDefault();
    const data = new FormData(e.target);
    fetch("addjson.php", {
        method: 'POST',
        body:data
    })
    .then(response => response.text())
    .then(result => {
    window.location.reload()
    });
})