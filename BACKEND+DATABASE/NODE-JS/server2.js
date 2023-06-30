const http = require('http'); //import module using require which is present in global space

const server=http.createServer((request,response)=>{ //request listener function which is executed when a request reaches a server
  console.log("URL:",request.url,"Method:",request.method,"Header:",request.headers); //url tells about the search made(after /),
  //method tells about the method used,header tells about the host,connection details like platform,browser,etc.
});
server.listen(3000); //switch on the listening state of the server