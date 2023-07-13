//node.js is a framework that helps us run JavaScript on our machine
//npm(node package manager) is a repository from where you can use 
//and install third party modules(node modules)
//The npm init command is used to create a Node. js project. The npm init command will create a
//package where the project files will be stored. 
//All the modules you download will be stored in the package
//in node to run use node filename

const http=require("http");

const server=http.createServer((request,response)=>{
    console.log("Hello there");
});

server.listen(3000);
//npm install nodemon --save-dev(only --save for production dependency)
//nodemon over nodejs-any changes in code will automatically restart the application
//npm:development dependency(nodemon-used for testing) and production dependency(express-used for deploying)
//for own scripts use npm run script_name
//ctrl c + y to terminate
//to install nodemon globally use npm install -g nodemon
//package.json-all dependencies present in the file will be installed with npm install(in case any file is deleted)
//package-lock.json-locks the version of the dependency used so that your project is not effected by any update of the dependency