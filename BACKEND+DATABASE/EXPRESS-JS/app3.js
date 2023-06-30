const http=require("http");
const express=require("express");
const bodyParser=require("body-parser");

const app=express();
app.use(bodyParser.urlencoded({extended:false}));
app.use("/course",(request,response,next)=>{
   console.log("Miiddleware 1");
   response.send('<form action="/abc" method="POST"><input type="text" name="data"><button type="submit">Submit</button></form>');
});
app.use("/abc",(request,response,next)=>{
    console.log(request.body); //undefined without installing body-parser(production dependency)
    console.log("Middleware 2");
    response.redirect("/");
 });
 app.use("/",(request,response,next)=>{
    console.log("Middleware 3");
    response.send("<h1>Your response is recorded</h1>")
 });
app.listen(3000);
//instead of .use use .get/.post for get and post methods
//for app.get("/",..) it will run only for "/" url
//same url will be executed separately for app.get and app.post