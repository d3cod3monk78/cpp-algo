# Pointers

> Computers deal with memory. Memory is everything to a computer. If i had to name a single most important thing in programming, it would probably be memory. When you write and application and you execute it that entire application gets loaded into the memory. All the instructions that tell the computer what to do in code that you've written all that gets loaded into memory.
> Pointers are extremely important for managing and manipulating that memory. </br>
> __A pointer is an integer a number which stores a memory address__
> </br>In other words a __pointer__ is just an address

## Purest of pointers - Void pointer

> __Void__ means completely type less. It means a _void pointer_ is just an address or just an integer which holds an address in memory.

```c++
 void* ptr = 0;
```

> In here __0(zero)__ is not actually a valid memory address. Because 0 is invalid. It means `ptr` pointer is not a valid pointer. </br> In other words 0 means _null_. Therefore we can write,

```c++
 void* ptr = NULL;
 //or
 void* ptr = nullptr; //-std=c++11
```

-sample code

```c++
#include <bits/stdc++.h>

#define LOG(x) std::cout << x << std::endl

int main(int argc, char const *argv[]) {

 int var = 10;
 void* ptr = nullptr;

 ptr = &var;

 LOG(ptr);

 return 0;
}
```

```bash
 output: 0x7ffff994286c
```

---

## Allocating and deleting pointers

```c++
#include <bits/stdc++.h>

#define LOG(x) std::cout << x << std::endl

int main(int argc, char const *argv[]) {
 char* buffer = new char[8];
 memset(buffer , 0 , sizeof(buffer)); 
 delete [] buffer; 
 return 0;
}
```
