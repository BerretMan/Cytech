const l_button= document.querySelectorAll("button");

console.log(l_button);
l_button.forEach(button => {
    button.addEventListener("click", () => {
        button.disabled = true;
        button.style.backgroundColor="black";
        const data = new FormData();
        data.append("id", button.id);

        fetch("traitement.php", {
            method: 'POST',
            body: data
        })
        .then(response => response.text()) 
        .then(result => {
            document.getElementById("result").innerHTML = result;
        })
    });
});


dict={'a': 0, 'z': 1, 'e': 2, 'r': 3, 't': 4, 'y': 5, 'u': 6, 'i': 7,'o': 8, 'p': 9, 'q': 10, 's': 11, 'd': 12, 'f': 13, 'g': 14, 'h': 15,'j': 16, 'k': 17, 'l': 18, 'm': 19, 'w': 20, 'x': 21, 'c': 22, 'v': 23,'b': 24, 'n': 25}


//ajouter le support du clavier
addEventListener("keypress",(e) => {
    l_button[dict[e.key]].click()
});