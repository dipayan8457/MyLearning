const express=require("express");
const path=require("path");
const router=express.Router(); //mini version of app

router.get("/",(request,response,next)=>{
    console.log("Middleware 3");
    //response.sendFile("./files/course.html")->This path is seen from OS level and not on root folder level
    response.sendFile(path.join(__dirname,"../","files","course.html"));
    //__dirname is a global variable used to point to current folder
    //"../"means coming out of routes folder  
 });

 module.exports=router;