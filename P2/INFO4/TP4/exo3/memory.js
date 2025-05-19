const table = document.getElementById("game");
const l_case = document.querySelectorAll("th");

const image = [
    "https://cdn.jsdelivr.net/gh/devicons/devicon@latest/icons/python/python-original.svg",
    "https://cdn.jsdelivr.net/gh/devicons/devicon@latest/icons/c/c-original.svg",
    "https://cdn.jsdelivr.net/gh/devicons/devicon@latest/icons/cplusplus/cplusplus-original.svg",
    "https://cdn.jsdelivr.net/gh/devicons/devicon@latest/icons/java/java-original.svg",
    "https://cdn.jsdelivr.net/gh/devicons/devicon@latest/icons/javascript/javascript-original.svg",
    "https://cdn.jsdelivr.net/gh/devicons/devicon@latest/icons/dart/dart-original.svg",
    "https://cdn.jsdelivr.net/gh/devicons/devicon@latest/icons/svelte/svelte-original.svg",
    "https://cdn.jsdelivr.net/gh/devicons/devicon@latest/icons/bash/bash-original.svg",
    "https://cdn.jsdelivr.net/gh/devicons/devicon@latest/icons/azuresqldatabase/azuresqldatabase-original.svg",
    "https://cdn.jsdelivr.net/gh/devicons/devicon@latest/icons/php/php-original.svg",
    "https://cdn.jsdelivr.net/gh/devicons/devicon@latest/icons/python/python-original.svg",
    "https://cdn.jsdelivr.net/gh/devicons/devicon@latest/icons/c/c-original.svg",
    "https://cdn.jsdelivr.net/gh/devicons/devicon@latest/icons/cplusplus/cplusplus-original.svg",
    "https://cdn.jsdelivr.net/gh/devicons/devicon@latest/icons/java/java-original.svg",
    "https://cdn.jsdelivr.net/gh/devicons/devicon@latest/icons/javascript/javascript-original.svg",
    "https://cdn.jsdelivr.net/gh/devicons/devicon@latest/icons/dart/dart-original.svg",
    "https://cdn.jsdelivr.net/gh/devicons/devicon@latest/icons/svelte/svelte-original.svg",
    "https://cdn.jsdelivr.net/gh/devicons/devicon@latest/icons/bash/bash-original.svg",
    "https://cdn.jsdelivr.net/gh/devicons/devicon@latest/icons/azuresqldatabase/azuresqldatabase-original.svg",
    "https://cdn.jsdelivr.net/gh/devicons/devicon@latest/icons/php/php-original.svg"

]
let cases = [];
let images = [...image]; 

l_case.forEach(element => {
    let index = Math.floor(Math.random() * images.length);
    element.firstChild.src = images[index];
    images.splice(index, 1);

    element.addEventListener("click", () => {
        if (element.classList.contains("flipped") || cases.length >= 2) return;

        element.classList.add("flipped");
        element.firstChild.style.visibility = 'visible';

        cases.push(element);

        if (cases.length === 2) {
            if (cases[0].firstChild.src === cases[1].firstChild.src) {
                cases = [];
            } else {
                setTimeout(() => {
                    cases.forEach(el => {
                        el.firstChild.style.visibility = 'hidden';
                        el.classList.remove("flipped");
                    });
                    cases = [];
                }, 700);
            }
        }
    });
    element.firstChild.style.visibility = 'hidden';
});