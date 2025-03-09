const prieres = document.querySelectorAll("li");
// prieres.forEach(element => {
//     console.log(element.innerText);
// });
const tableau = ["Fajr", "Dhuhr", "Asr", "Maghrib", "Isha"];
let timings = []
const link = "https://api.aladhan.com/v1/timings/27-02-2025?latitude=51.5194682&longitude=-0.1360365"
function display(){
    let i = 0;
    prieres.forEach(priere => {
        priere.innerText += " : " + timings[tableau[i]];
        i++;       
    })
}

function load(callback){
    const xhr = new XMLHttpRequest();
    xhr.open("GET", link)
    xhr.onload = function(){
        if (xhr.status === 200) {
            const response = JSON.parse(xhr.response);
            console.log(response);
            timings = response.data.timings
            console.log(timings)
            callback()
        }
    }
    xhr.onerror = function (){
        console.log("erreur loading")
    }

    xhr.send();
}

load(display);