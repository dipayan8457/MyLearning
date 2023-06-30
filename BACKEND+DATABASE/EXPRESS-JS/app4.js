const http=require("http");
const express=require("express");
const bodyParser=require("body-parser");

const app=express();

app.use(bodyParser.urlencoded({extended:false}));
//app.use(express.static((path.join(__dirname,....))))->to add css file statically i.e. without middleware and router

const adminroutes=require("./routes/admin");
const courseroutes=require("./routes/course");

app.use("/admin",adminroutes);
app.use(courseroutes);
app.use((request,response,next)=>{ //incase both above statements don't execute
    console.log("error");
    response.status(404).send("<h1>Page not found</h1>"); //error 404 is status code for "not found"
});
app.listen(3000);

//routes are imports