const http = require('http'); //import module using require which is present in global space
const fs=require('fs'); //import file module

const server=http.createServer((request,response)=>{ //request listener function which is executed when a request reaches a server

    const url=request.url;
    if(url==="/"){
        response.setHeader("Content-Type","text/html");
  response.write("<html>");
  response.write("<head><title>My First Webpage</title></head>");
  response.write("<body><h1>My First Webpage</h1></body>");
  response.write("</html>");
  return response.end(); //return is necessary to come out of the function 
    }
    if(url==="/file"){
        fs.writeFileSync("NewFile.txt","Hellooooooooo Brother"); //creates a file named NewFile with some content
        response.statusCode=302; //statusCode 302 signifies you are redirected
        response.setHeader("Location","/"); //signifies the redirected location
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