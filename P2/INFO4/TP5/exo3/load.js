const l_img = localStorage.getItem("images");
l_img= JSON.parse(l_img)
const p = document.querySelector("p");
p.innerHTML=l_img
console.log(l_img)