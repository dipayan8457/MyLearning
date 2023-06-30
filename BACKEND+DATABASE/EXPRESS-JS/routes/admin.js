const express=require("express");
const path=require("path");
const router=express.Router();// mini version of app

router.get("/add-course",(request,response,next)=>{
    console.log("Middleware 1");
    response.sendFile(path.join(__dirname,"../","files","admin.html"));
})
//in form action we have to mention the entire url
router.post("/add-course",(request,response,next)=>{
     console.log(request.body); 
     console.log("Middleware 2");
     response.redirect("/");
});

module.exports=router;