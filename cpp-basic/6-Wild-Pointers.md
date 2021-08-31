# Wild Pointers

A pointer which has not been initialized to anything (not even NULL) is known as wild pointer. The pointer may be initialized to a non-NULL garbage value that may not be a valid address.

```cpp
 int main()
{
    int *p;  /* wild pointer */
  
    int x = 10;
  
    // p is not a wild pointer now
    p = &x;
  
    return 0;
}
```
