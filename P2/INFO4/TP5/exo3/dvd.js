const img = document.querySelectorAll("img");
const achat = document.getElementById("achat");
const button= document.getElementById("b");

const l_img=[];
img.forEach(e => {
    e.addEventListener("click", () => {
        const image = document.createElement("img");
        image.src=e.src;
        achat.appendChild(image)
        
    });
});

button.addEventListener("click",() => {
    for( e of achat.childNodes) {
        if(e.src) {

            l_img.push(e.src);
        }
    }
    console.log(l_img)

    localStorage.setItem("images",l_img);

    window.location="oui.html";
 
});