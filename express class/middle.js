const express=require('express');

const app=express();

//function that returns a booleann if the age of the person if mroe than 12
function isOldEnough(age)
{
    if(age>=14){
        next();
    }else{
        res.json({
            msg:"sorry you are not of age yet.."
        })
    }
}
function isOldEnoughMiddleware(req,res,next)
{
    const age=req.query.age;
    if(age>=14){
        next();
    }else{
        res.json({
            msg:"sorry you are not of age yet!!"
        })
    }
}

app.get("/ride1",isOldEnoughMiddleware,function(req,res){
    
    res.json({
        msg:"you have succesfuuly riden ride1...",
    });
    }
);



app.listen(3000);