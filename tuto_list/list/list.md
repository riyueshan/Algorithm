## how to ensure index

Set the usual loop we use as an example:

```c
for (int i=0;i<n;i++){
    //other expression
}
```

In this loop, the final value of `i` will be **n**, while the `i` inside loop will be **n-1**,
since when i=n, the `i<n` is false, so computer will not implement the body of the loop. [Learn more](../note/loop.md#for-loop)

Thus, we can use this to traverse `ElemType* array[n]`, which cover from `array[0]` to `array[n-1]`:

```c
for (int i=0;i<n;i++){
    //other expression **for array[i]**
}
```

Similarly, when it comes to the "index" of a list, where we can regard each node as `list[i]` like an array,
we can finally get address of `list[n]` and perform expression to `list[n-1]`

```c
~~for(int i=0,Node* p= list;i<n;i++,p=p->next)~~{
}

Node* p=list; // can't initialize different types of varibles in for loop
for(int i=0;i<n;i++,p=p->next){

    ....//operation for list[i]
}

// p finally point to list[n]
```

## when to stop p

for a list with n nodes

| Type   | `while(p)`         | `while(p->next)`          |
| ------ | ------------------ | ------------------------- |
| stop   | when `p` is NULL   | when `p` is the last node |
| inside | `p` is `list[n-1]` | `p` is `list[n-2]`        |
| final  | `p` is `list[n]`   | `p` is `list[n-1]`        |
| usage  | insert list[n]     | traverse to tail of list  |

>  - ⟹ **edge**
> 
>   if we define the conception of edge, this can expand to other kinds of list:
 `while(p!=edge)` and `while(p->next!=edge)`
>    - for normal list, the **edge=NULL**, 
>    - for double linked list, the **edge=head** or **edge=tail**, 
>    - for circular linked list, the **edge=head** or **edge=tail**.
