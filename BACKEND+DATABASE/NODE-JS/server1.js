const http = require('http'); //import module using require which is present in global space

const server=http.createServer((request,response)=>{ //request listener function which is executed when a request reaches a server
  console.log("Hello World");
})
server.listen(3000); //switch on the listening state of the server