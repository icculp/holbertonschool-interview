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

const getBody = async function (url) {
  const options = {
    url: url,
    method: 'GET'
  };

  // Return new promise
  return new Promise(function (resolve, reject) {
    // Do async job
    request.get(options, function (err, resp, body) {
      if (err) {
        reject(err);
      } else {
        resolve(body);
      }
    });
  });
};

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
  // for (c in characters) {
  /** console.log(characters[c]); */
  /** request(characters[c], function (error, response, body) {
      if (error) {
        console.error('error:', error);
      }
      /** console.log("----") */

  /** const b = await getBody(characters[c]);
        const name = JSON.parse(b);
        console.log(name.name); */

  (async function () {
    // const options = { url: characters[c], method: 'GET' }
    for (c in characters) {
      const response = await getBody(characters[c]);
      const name = JSON.parse(response);
      // console.log(name);

      console.log(name.name);
    }
  })();
// };
  // };
});
