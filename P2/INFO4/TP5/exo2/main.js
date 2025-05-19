url=window.location.search.slice(1,window.location.search.length);
console.log(url);
document.addEventListener("DOMContentLoaded",() => {
    p=document.querySelector("p");
    p.innerHTML=url.replace(/&/g,"<br>");
    console.log(p);
});

