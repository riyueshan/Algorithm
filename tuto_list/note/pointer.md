
## Pointer and Functions

### As Parameter

Since in C, every parameter is passed by value, if we want to modify the value of a variable in a function, the change will not be reflected back to the caller. However, when we use a pointer, though the change to pointer itself stay unchanged outside the function, **the value it points** to can be changed, as the address is the same.


```c
#include <stdio.h>

void ChangePointer_False(int *p_a) {
    printf("Address of p_a in function %p\n", *p_a);
    p_a = NULL;
}

void ChangePointer_True(int **p_a) {
    printf("Address of p_a in function %p\n", *p_a);
    *p_a = NULL;
}

void ChangeValue(int *a) {
    *a = 10;
}

int main() {
    int a = 5;
    int *p_a = &a;

    printf("Address of p_a in main %p\n", p_a);
    ChangePointer_False(p_a);
    printf("Address of p_a in main after \"change\" directly %p\n", p_a);
    ChangePointer_True(&p_a);
    printf("Address of p_a in main after change with address of itself %p\n", p_a);

    printf("The value of a before change %d\n", a);
    ChangeValue(&a);
    printf("The value of a after change %d\n", a);
    return 0;
}
```

The output of the code above is:

```bash
Address of p_a in main 0x7fffbf7b3bfc
Address of p_a in function 0x7fffbf7b3bfc
Address of p_a in main after "change" 0x7fffbf7b3bfc

The value of a before change 5
The value of a after change 10
```

Pass **the address of a parameter** to a function is a useful way to change the value of itself, without returning an additional value. This also applies especially when we want to change the value of a pointer, like for a list or an array.

### As Return Value

When we want to return a pointer from a function, we have to be careful, as the memory allocated inside the function will be deallocated when the function ends. This means that the pointer will point to an invalid memory address.

To avoid this, we can use `malloc` to allocate memory in the heap, and return the pointer. This way, the memory will be deallocated only when we call `free` on the pointer.

```c
#include <stdio.h>
#include <stdlib.h>

int* ReturnPointer_False() {
    int a = 5;
    return &a;
}

int* ReturnPointer_True() {
    int *p_a = (int *)malloc(sizeof(int));
    *p_a = 5;
    return p_a;
}

int main() {
    int *p_a = ReturnPointer_False();
    printf("The value of p_a without malloc %d\n", *p_a);

    int *p_a = ReturnPointer_True();
    printf("The value of p_a with malloc%d\n", *p_a);
    free(p_a);
    return 0;
}
```

The output of the code above is:

```bash
The value of p_a without malloc 32767
The value of p_a with malloc 5
```
