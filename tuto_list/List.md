
# List

List is a data structure that stores a collection of elements. The elements in list are linked using pointers. Thus, each element owns generally two fields: one for the data and one for the pointer, and this is called a **node**.

And to access to the list we need a pointer that points to the element of the list. This pointer is called the head of the list, **head pointer**.

To simplify the manipulation of the list, here are several tricks like the **dummy node**,**sentinel node**,**rear pointer**.

**Key**
1. [ ] [structure of list](note/list__node.md#key)
2. [ ] [special node](note/list__node.md#虚拟节点dummy-node)
3. [ ] [special pointer]



## Definition

```c
typedef struct Data{
    int id;
    int value;
}Data;

typedef struct Node{
    Data data;
    struct Node *next;
}Node;

typedef Node* NodePtr;
```

> **Note**
> [list or node](note/list__node)


## Basic Operations

to be continue...

## List

Normally, a basic list just has a head pointer to access to the list. But in some cases, we need to can add a dummy node to simplify the manipulation of the list.