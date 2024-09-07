const express=require("express");
const app=express();

const users=[{
    name:"vaibhav",
    kidneys:[{
        healthy:false
    }]
}];

app.use(express.json());
//query paramter= "?n=3"
app.get("/",function(req,res){
    const johnkidneys=users[0].kidneys;
    const numberOfKidneys=johnkidneys.length;
    let numberOfHealthyKidneys=0;
    for(let i=0;i<johnkidneys.length;i++)
    {
        if(johnkidneys[i].healthy)
        {
            numberOfHealthyKidneys+=1;
        }
    }
    const numberOfUnhealthyKidneys=numberOfKidneys-numberOfHealthyKidneys;
    res.json({
        numberOfKidneys,
        numberOfHealthyKidneys,
        numberOfUnhealthyKidneys
    })
})
//popular
app.post("/",function(req,res){
    const isHealthy=req.body.isHealthy;
    users[0].kidneys.push({
        healthy: isHealthy
    })

    res.json({
        msg:"Done!"
        //just posting the data dont necessarilyn need respond
    })
})

app.put("/",function(req,res){
    for(let i=0;i<users[0].kidneys.length;i++)
    {
        users[0].kidneys[i].healthy=true;
    }
    res.json({});
})


app.delete("/",function(req,res){
    
    
})

app.listen(3001);