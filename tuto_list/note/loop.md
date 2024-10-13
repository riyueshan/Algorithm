
## For Loop

The order to implement the loop is as follows:
1. Initialize the loop variable
2. Judge the condition for the loop
3. Implement the loop body
4. Update the loop variable

```c
for (int i=0;i<n;i++){
    //other expression
}
```

The order should be
1. i=0;
2. judge i<n;
3. implement the expression;
4. i++;
5. continue the loop until i=n.
6. i<n is false, so the loop ends.

So the i finally is **n**, while the i inside loop is **n-1**. 