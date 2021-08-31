# Void Pointers

Void pointer is a specific pointer type – void * – a pointer that points to some data location in storage, which doesn’t have any specific type. Void refers to the type. Basically the type of data that it points to is can be any. If we assign address of char data type to void pointer it will become char Pointer, if int data type then int pointer and so on. Any pointer type is convertible to a void pointer hence it can point to any value.

## Important Points

- void pointers __cannot be dereferenced__. It can however be done using typecasting the void pointer
- Pointer arithmetic is not possible on pointers of void due to lack of concrete value and thus size.

```cpp
 #include<stdlib.h>
  
int main()
{
    int x = 4;
    float y = 5.5;
      
    //A void pointer
    void *ptr;
    ptr = &x;
  
    // (int*)ptr - does type casting of void 
    // *((int*)ptr) dereferences the typecasted 
    // void pointer variable.
    printf("Integer variable is = %d", *( (int*) ptr) );
  
    // void pointer is now float
    ptr = &y; 
    printf("\nFloat variable is= %f", *( (float*) ptr) );
  
    return 0;
}
```
