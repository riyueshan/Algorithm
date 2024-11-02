## pop and push

Different ordinary list, list stack can only pop and push node from one side,
so it is convenient to insert node from tail.

## typedef stack

Since we just need to modify the stack from one side, and considering inserting node from tail,
we can combine the rear pointer with length of nodes, that is

```c
typedef struct Stack{
NodePtr rear;
int len;
}Stack;
```

And that is similar for sequential stack

```c
typedef struct SqStack{
ElemPtr base;
int top;
int capacity;
int len;
}SqStack;
```

```