#!/usr/bin/node
/*
* Star Wars API project
*/
const request = require('request');
const id = process.argv[2];
const BaseUrl = 'https://swapi-api.hbtn.io/api/films/';
const url = BaseUrl + id;
/** console.log(id);
console.log(url); */

request(url, function (error, response, body) {
  if (error) {
    console.error('error:', error);
  }
  /** console.log('statusCode:', response.json); */
  const films = JSON.parse(body);
  /** console.log(films); */
  /** console.log('body:', body); // Print the HTML for the Google homepage. */
  const characters = films.characters;

  /** console.log(characters) */
  let c;
  for (c in characters) {
    /** console.log(characters[c]); */
    request(characters[c], function (error, response, body) {
      if (error) {
        console.error('error:', error);
      }
      const name = JSON.parse(body);
      /** console.log("----") */
      console.log(name.name);
    });
  }
});
