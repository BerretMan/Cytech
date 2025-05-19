document.addEventListener("DOMContentLoaded",() => {
    let form = document.getElementById("form1");
    let select = document.getElementById("mySelect");
    
    form[2].addEventListener("click",() => {
        if (form.elements[0].value!="") {
            select.size+=1;
            let texte = form.elements[0].value;
            document.getElementById("resultat").innerHTML = texte;
            let node = document.createElement("option");
            node.appendChild(document.createTextNode(texte));
            select.appendChild(node);

        } if (form.elements[1].value!="") {
            for (let i=0;i<select.length;i++) {
                if (select[i].innerText==form.elements[1].value) {
                    select[i].remove();
                }
            }

        }

    })
})
