
const dvd = document.getElementById("dvd");


dvd.addEventListener("mouseover", () => {
    dvd.src="new.jpg"
})

dvd.addEventListener("mouseleave", () => {
    dvd.src="dvd.png"
})


dvd.addEventListener("click",() => {
    window.alert(`The name is ${dvd.src} \n taille: ${dvd.naturalHeight}x${dvd.naturalWidth}`);
})


function change(n) {
    return Math.floor(Math.random()*n);
}

