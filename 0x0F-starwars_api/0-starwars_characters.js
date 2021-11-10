#!/usr/bin/node
const movieId = process.argv[2];
const request = require('request');
const swapiUrl = 'https://swapi-api.hbtn.io/api/';
const swapiEndpoint = 'films/';
const url = swapiUrl + swapiEndpoint + movieId;

request(url, async function (error, response, body) {
  if (error) {
    console.log(error);
    process.exit(1);
  }

  if (response.statusCode !== 200) {
    process.exit(1);
  }

  const movieResponseBody = JSON.parse(body);
  for (const url of movieResponseBody.characters) {
    const name = await new Promise((resolve, reject) => {
      request(url, (error, response, body) => {
        if (error) {
          reject(error);
        }

        if (response.statusCode !== 200) {
          reject(error);
        }

        resolve(JSON.parse(body).name);
      });
    });
    console.log(name);
  }
});
