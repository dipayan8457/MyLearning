const http = require('http'); //import module using require which is present in global space

const server=http.createServer((request,response)=>{ //request listener function which is executed when a request reaches a server

    const url=request.url;
    if(url==="/"){
        response.setHeader("Content-Type","text/html");
  response.write("<html>");
  response.write("<head><title>My First Webpage</title></head>");
  response.write("<body><h1>My First Webpage</h1></body>");
  response.write("</html>");
  return response.end(); 
    }
  response.setHeader("Content-Type","text/html");
  response.write("<html>");
  response.write("<head><title>My Second Webpage</title></head>");
  response.write("<body><h1>My Second Webpage</h1></body>");
  response.write("</html>");
  response.end();
});
server.listen(3000); //switch on the listening state of the server