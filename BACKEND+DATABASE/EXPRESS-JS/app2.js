//request->middleware-next()/-response.send()->response
//middleware:(request,response,next)=>{....}

const http=require("http");
const express=require("express");//imported as a function(request handler)

const app=express();
//use is a method
app.use("/abc",(request,response,next)=>{//next is a function used to call next middleware 
   console.log("Middleware 1");
   next();
})
//" " as first argument checks if url is same
//in case of "/",it is always true(present in url by default)
//sometimes few middlewares can run as browser passes a /favicon.ico request to them
app.use((request,response,next)=>{
    console.log("Middleware 2");
    response.send("<h1>Hey it's me</h1>");//no need to write/setHeader
 });
 //express reads from top to bottom and doesn't send response by default
app.listen(3000);