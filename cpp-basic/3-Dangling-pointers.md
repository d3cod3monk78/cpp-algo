# Dangling Pointers

Dangling pointer is a situation where you have valid pointers int the stack, but it is pointing to invalid memory. You might end up in this situation when you de-allocate the heap memory before the pointers in stack de-allocated.

> A pointer pointing to a memory location that has been deleted (or freed) is called dangling pointer.

There are __Three__ different ways where pointer acts as a dangling pointer.

- __De-allocation of memory__

```c++
 // Deallocating a memory pointed by ptr causes
// dangling pointer
#include <stdlib.h>
#include <stdio.h>
int main()
{
    int *ptr = (int *)malloc(sizeof(int));
  
    // After below free call, ptr becomes a 
    // dangling pointer
    free(ptr); 
      
    // No more a dangling pointer
    ptr = NULL;
}
```

- __Function Call__

```cpp
 // The pointer pointing to local variable becomes
// dangling when local variable is not static.
#include<stdio.h>
  
int *fun()
{
    // x is local variable and goes out of
    // scope after an execution of fun() is
    // over.
    int x = 5;
  
    return &x;
}
  
// Driver Code
int main()
{
    int *p = fun();
    fflush(stdin);
  
    // p points to something which is not
    // valid anymore
    printf("%d", *p);
    return 0;
    // The above problem doesn’t appear (or p doesn’t become dangling) if x is a static variable.


}
```

```bash
 Output: A garbage address
```

- __Variable goes out of scope__

```cpp
 void main()
{
   int *ptr;
   .....
   .....
   {
       int ch;
       ptr = &ch;
   } 
   .....   
   // Here ptr is dangling pointer
}
```

---

## Understanding the case of Dangling Pointers

This is a security issue. Because when you deallocate a memory, we are informing Operating System, that we no longer need this section of memory. So OS will mark that piece of memory as ready to allocate and allocate to other applications when they request for memory.

![dangling](https://i.stack.imgur.com/XXRNA.png)

Usually, in C++, memory allocated and deallocated through a general pattern. Constructor in a class gets invoked when a class initialised and this is the right place to allocate memory in heap.Destructor will be invoked when the class instance goes out of scope, and this is the right place to deallocate memory from heap. Assume we already created a class that does allocation and deallocation of memory in constructor and destructor respectively.

```cpp
 int main() {
  SomeClass pointer1 = SomeClass();
  SomeClass pointer2 = pointer1;
}

```

In the above example code, there are two variables declared but both holding the same value. When the constructor invoked, it allocates a heap memory. Then we are declaring one more variable and assigning the same value. In C++ usually, when you assign a value of complex type, it does a shallow copy (unless you explicitly implemented copy constructor) instead of deep copy. That means the only pointer gets copied in Stack, but not the heap memory. Actually it is not recommended to copy heap memory for performance reasons. Now the final memory layout looks like that we have two pointers pointing to the same heap memory.

![shallow-copy](https://i.stack.imgur.com/01Wcw.png)

Now when the function is done with execution, local variables goes out of scope and it invokes destructor. First, pointer2 invokes destructor that deallocates the heap memory. At this point, pointer1 becomes dangling pointer. It points to a memory that is already deallocated.

![err](https://i.stack.imgur.com/xY8WC.png)

> __The primary cause of dangling pointer is having multiple owners for the same resource. Because when one pointer deallocates memory other pointers became dangling pointers.__
