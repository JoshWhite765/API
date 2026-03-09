# API
Built an application using data from a public API - Harry Potter public API: [Harry Potter API:](https://potterdb.com/)

Brief: 

# S2. Data Driven App

For this assignment you are tasked with developing an application that makes use of data retrieved from an API. Your application should aim to demonstrate a range of programming techniques introduced over the course of CodeLab I and CodeLab II, including use of functions and where appropriate object oriented programming. 

The final application should be delivered via a functioning interactive GUI built using openFrameworks. This GUI should allow the user to interact via mouse and/or keyboard input.

For the assessment you are required to use one of the APIs listed below:

* [The Movie DB:](https://developer.themoviedb.org/)
* [Discogs:](https://www.discogs.com/developers)
* [Rest Countries:](https://restcountries.com/)
* [Currency API:](https://freecurrencyapi.com/)
* [Open Trivia:](https://opentdb.com/)
* [Pokemon API:](https://pokeapi.co/)
* [Harry Potter API:](https://potterdb.com/)

Reflection

Overall I’m pleased with the harry potter review application as it allows users to write their own opinion and provide a thumb rating on their favourite or less favourite subject. The program handles button clicks, text wrapping and the navigation between pages. Some functions specifically the setMediaFile function could be reused to call for of new content types. Although many of my design choices changed due to having a somewhat overambitious view on what could be achieved in the timeframe. This current version of my app serves as good place to read and write opinions. Furthermore sanitising user inputs to prevent users writing harmful words or csv injections

In terms of performance the algorithm successfully loads the text data into memory on start up and only loads images when required. To improve performance in the future I could get the size of the image and only load images that are small enough. 
