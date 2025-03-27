let LATITUDE;
let LONGITUDE;
let API_URL;

// Wait for the Cordova deviceready event before starting the app
document.addEventListener('deviceready', onDeviceReady, false);

function onDeviceReady() {
    console.log('Device is ready. Starting weather app...');
    getLocation();
}

// Geolocation
function getLocation() {
    console.log('Requesting location...');
    if (navigator.geolocation) {
        // Add timeout and error handling options for Cordova
        const geoOptions = {
            timeout: 10000,
            enableHighAccuracy: true
        };

        navigator.geolocation.getCurrentPosition(
            setPosition,
            handleLocationError,
            geoOptions
        );
    } else {
        console.log("Geolocation not available, using default coordinates");
        LATITUDE = 34.68;
        LONGITUDE = 1.91;
        buildApiUrlAndFetchData();
    }
}

function handleLocationError(error) {
    console.log("Geolocation error. Code: " + error.code + ". Message: " + error.message);
    // Fall back to default coordinates
    LATITUDE = 34.68;
    LONGITUDE = 1.91;
    buildApiUrlAndFetchData();
}

function setPosition(position) {
    console.log('Location acquired:', position.coords.latitude, position.coords.longitude);
    LATITUDE = position.coords.latitude;
    LONGITUDE = position.coords.longitude;
    buildApiUrlAndFetchData();
}

function buildApiUrlAndFetchData() {
    city_API_URL = `https://api.openweathermap.org/geo/1.0/reverse?lat=${LATITUDE}&lon=${LONGITUDE}&limit=100&appid=a673d17e0347827fa36aa13324e8a92d`
    API_URL = `https://api.open-meteo.com/v1/forecast?latitude=${LATITUDE}&longitude=${LONGITUDE}&daily=weather_code,temperature_2m_max,temperature_2m_min,rain_sum,sunrise,sunset&hourly=temperature_2m,precipitation_probability,weather_code&current=temperature_2m,apparent_temperature,is_day&timezone=auto`;
    console.log(`API URL: ${API_URL}`);
    getMeteo(display);
    getCity(displayCity);
}

//time to date
function time2date(dateArg) {
    let date = new Date(dateArg);
    const result = date.toLocaleTimeString('en-US', {
        hour: '2-digit',
        minute: '2-digit',
        hour12: false
    });
    return result;
}

//icons
function getWeatherIcon(code, isDay = true) {
    // WMO Weather interpretation codes (https://open-meteo.com/en/docs)

    // Clear sky
    if (code === 0) return isDay ? "fa-solid fa-sun" : "fa-solid fa-moon";

    // Mainly clear
    if (code === 1) return isDay ? "fa-solid fa-sun" : "fa-solid fa-moon";

    // Partly cloudy
    if (code === 2) return isDay ? "fa-solid fa-cloud-sun" : "fa-solid fa-cloud-moon";

    // Overcast
    if (code === 3) return "fa-solid fa-cloud";

    // Fog
    if (code >= 45 && code <= 48) return "fa-solid fa-smog";

    // Drizzle
    if (code >= 51 && code <= 55) return "fa-solid fa-cloud-rain";

    // Freezing Drizzle
    if (code >= 56 && code <= 57) return "fa-solid fa-snowflake";

    // Rain
    if (code >= 61 && code <= 65) return "fa-solid fa-cloud-showers-heavy";

    // Freezing Rain
    if (code >= 66 && code <= 67) return "fa-solid fa-snowflake";

    // Snow
    if (code >= 71 && code <= 77) return "fa-solid fa-snowflake";

    // Rain showers
    if (code >= 80 && code <= 82) return "fa-solid fa-cloud-showers-heavy";

    // Snow showers
    if (code >= 85 && code <= 86) return "fa-solid fa-snowflake";

    // Thunderstorm
    if (code >= 95 && code <= 99) return "fa-solid fa-cloud-bolt";

    // Default based on time of day
    return isDay ? "fa-solid fa-sun" : "fa-solid fa-moon";
}

function display(data) {
    //maj current deg
    const max = document.getElementById("max");
    const min = document.getElementById("min");
    const current = document.getElementById("topDeg") ;
    const currentIcon = document.getElementById("topIcon");
    current.innerText = Math.round(data.current.temperature_2m) + "°";
    max.innerText = Math.round(data.daily.temperature_2m_max[0]);
    min.innerText = Math.round(data.daily.temperature_2m_min[0]);
    currentIcon.innerHTML = `<i class="${getWeatherIcon(data.current.weather_code,data.current.is_day)}"></i>`;

    //feels like
    const feelsLiketext = document.getElementById("feelsLike");
    feelsLiketext.innerText = Math.round(data.current.apparent_temperature) + "°";

    //date
    const dateDisplay = document.getElementById("date")
    let date = new Date(data.current.time)
    const formatted = new Intl.DateTimeFormat('en-US', {
        weekday: 'short',
        hour: '2-digit',
        minute: '2-digit',
        hour12: false
      }).format(date).replace(',', '');
    dateDisplay.innerText = formatted;

    //hourly
    const now = new Date();
    const currentHour = now.getHours();
    const hourlyList = document.getElementById("HourlyList");
    hourlyList.innerHTML = "";
    let hourlyContent = "<ul>"
    for (let i = 0; i < 24; i++) {
        const dataIndex = currentHour + i;
        hourlyContent+=`
                    <li>
                        <div class="hour">${time2date(data.hourly.time[dataIndex])}</div>
                        <div class="hour-icon">
                            <i class="${getWeatherIcon(data.hourly.weather_code[dataIndex])}"></i>
                        </div>
                        <div class="hour-deg">${Math.round(data.hourly.temperature_2m[dataIndex])}°</div>
                        <div class="precipitation">
                            <i class="fa-solid fa-droplet"></i>
                            <span>${data.hourly.precipitation_probability[dataIndex]} %</span>
                        </div>
                    </li>`;
        }
        hourlyContent+="</ul>";
        hourlyList.innerHTML = hourlyContent;

    //daily
    const dailyList = document.getElementById("dailyList");
    dailyList.innerHTML = "";


    for (let i = 0; i < 7; i++) {
        let date = new Date(data.daily.time[i]);
        const fullDayName = date.toLocaleDateString('en-US', { weekday: 'long' });
        dailyList.innerHTML+=`
                <li>
                    <span class="day">${i != 0? fullDayName:"Today"}</span>
                    <div class="m-prep">
                        <i class="fa-solid fa-droplet"></i>
                        <span>${Math.round(data.daily.rain_sum[i])} %</span>
                    </div>
                    <div class="m-icon">
                        <i class="${getWeatherIcon(data.daily.weather_code[i])}"></i>
                        <i class="fa-solid fa-moon"></i>
                    </div>
                    <div class="m-deg">
                        <span>${Math.round(data.daily.temperature_2m_max[i])}°</span>
                        <span>${Math.round(data.daily.temperature_2m_min[i])}°</span>
                    </div>

                </li>
        `;

    }

    //sunrise sunset
    const sunrise = document.getElementById("sunriseTime");
    const sunset = document.getElementById("sunsetTime");
    sunrise.innerText = time2date(data.daily.sunrise[0]);
    sunset.innerText = time2date(data.daily.sunset[0]);
}

//api

function getMeteo(callback) {
    const xhr = new XMLHttpRequest();
    xhr.open("GET", API_URL);
    xhr.onload = function() {
        if (xhr.status == 200) {
            let response = JSON.parse(xhr.response);
            console.log("API response received successfully");
            callback(response);
        } else {
            console.log("Error: " + xhr.status);
        }
    }
    xhr.onerror = function() {
        console.log("Network error occurred");
    }
    xhr.send();
}

function displayCity(data){
    const city = document.getElementById("city");
    city.innerText = data;
}

function getCity(callback){
    const xhr= new XMLHttpRequest();
    xhr.open("GET", city_API_URL);
    xhr.onload = function (){
        if (xhr.status == 200){
            let response = JSON.parse(xhr.response)
            console.log(response[0].name)
            callback(response[0].name);
        }
    }
    xhr.onerror = function(){
        console.log("error")
    }
    xhr.send()

}

// In case you're manually testing outside of Cordova
if (typeof cordova === 'undefined') {
    console.log('Running in browser mode - Cordova not detected');
    // Give the DOM time to load
    window.addEventListener('DOMContentLoaded', () => {
        console.log('DOM loaded, starting app in browser mode');
        getLocation();
    });
}