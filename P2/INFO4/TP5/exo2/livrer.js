url=window.location.search.slice(1,window.location.search.length);
const data = new URLSearchParams(window.location.search);

document.addEventListener("DOMContentLoaded",() => {
    p=document.querySelector("p");
    p.innerHTML=String(data).replace(/&/g,"<br>");
    console.log(p);
});
