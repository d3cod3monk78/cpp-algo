# Null Pointers

NULL Pointer is a pointer which is pointing to nothing. In case, if we don’t have address to be assigned to a pointer, then we can simply use _NULL_ or _nullptr_

```cpp
 #include <stdio.h>
int main()
{
    // Null Pointer
    int *ptr = NULL;
      
    printf("The value of ptr is %p", ptr);
    return 0;
}
```

## Important Points

- __NULL vs Uninitialized pointer –__ An uninitialized pointer stores an undefined value. A null pointer stores a defined value, but one that is defined by the environment to not be a valid address for any member or object.
- __NULL vs Void Pointer -__ Null pointer is a value, while void pointer is a type
