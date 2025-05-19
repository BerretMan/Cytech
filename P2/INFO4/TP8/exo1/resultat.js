const form = document.getElementById("calcul")

form.addEventListener("submit", e => {
    e.preventDefault();
    const data = new FormData(e.target);
    fetch("calcul.php", {
        method: 'POST',
        body:data
    })
    .then(response => response.text())
    .then(result => {
    document.getElementById('res').textContent = result;
    });
})

