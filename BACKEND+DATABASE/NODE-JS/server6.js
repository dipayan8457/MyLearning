const http = require('http'); //import module using require which is present in global space
const fs=require('fs'); //import file module

const server=http.createServer((request,response)=>{ //request listener function which is executed when a request reaches a server

    const url=request.url;
    const method=request.method;
    if(url==="/"){
        response.setHeader("Content-Type","text/html");
  response.write("<html>");
  response.write("<head><title>My First Webpage</title></head>");
  response.write('<body><form action="/file" method="POST"><input type="text" name="msg"><button type="submit">Submit</button></form></body>');
  //action adds url,input name stores the key for the input,button type specifies the type of button
  response.write("</html>");
  return response.end(); //return is necessary to come out of the function 
    }
    if(url==="/file" && method==="POST"){
        const body=[];
        request.on("data",(chunk)=>{    //whenever "data" is passed this function is executed
            console.log(chunk);
            body.push(chunk);
        })
        request.on("end",()=>{
            const parsedBody=Buffer.concat(body).toString();   //Buffer concatenates the streamed data,converts into string and passes it to "parsedBody"
            console.log(parsedBody);
        })
        fs.writeFileSync("NewFile.txt","Hellooooooooo Brother"); //creates a file named NewFile with some content
        response.statusCode=302; //statusCode 302 signifies you are redirected
        response.setHeader("Location","/redirected"); //signifies the redirected location
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