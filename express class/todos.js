const express=require('express');
const { todo } = require('node:test');

const app=express();

app.use(express.json());

let todos=[];

app.post('/',function(req,res){
    const id=Math.floor(Math.random()*100);
    const title=req.body.title;

    todos.push({
        id,
        title
    });

    res.status(201).json({
        message: 'to-do created successfully',
        todo:{id,title}
    });


});

app.get('/',function(req,res)
{
    res.json({
        todos
    });
});


app.delete('/',function(req,res)
{
    const {id}=req.body;
    const index=todos.findIndex(todo=>todo.id===id);
    if(index!=-1)
    {
        const removedTodo=todos.splice(index,1);


        res.json({
            message:'todo deleted :',
            todo:removedTodo
        });
    }
})

app.listen(3001);