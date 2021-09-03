# Difference between __pointer to a reference__ and __reference to a pointer__

## Pointer to a pointer

A __pointer__ in C++ is just a value which stores a memory location (generally as a 32-bit value).
</br>
Let's say you had an user input integer value (<mark style="background-color: #E3E6E8" >78</mark> == <mark style="background-color: #E3E6E8" >0x4E</mark> in hex).
</br>
It would be stored in memory in a similar way to this (I'm purposely simplifying things for this example):

|Memory address|Value     |
|--------------|----------|
|0x12345678    |0x0000004E|

If you wanted to create a "pointer" to this value, it would look like this in memory:

|Memory address|Value     |
|--------------|----------|
|0x22334455    |0x12345678|

At memory address <mark style="background-color: #B7E1FF" >0x22334455</mark> you now have a "pointer" whose value is <mark style="background-color: #B7E1FF" >0x12345678</mark>, or the memory address of where the user input integer value (<mark style="background-color: #E3E6E8" >0x4E</mark>) is stored.
</br>
Let's say you wanted to create a "pointer" to this pointer value. It would look like this:

|Memory address|Value     |
|--------------|----------|
|0x11335577    |0x22334455|

You now have a new "pointer" value in memory which is storing the memory address of the previously-defined pointer value.

> Pointers can be created like this indefinitely - the key is remembering that a pointer is just another value that the compiler interprets as a memory location (and it provides various access semantics such as * and -> which are special to "pointer" types).

---

## Reference to a pointer

A reference can be thought of as a view, or alias, on to another real object. When you create a reference to a pointer called `myReference`, you are simply defining a new name called `myReference` which can be used to access the pointer which you have previous defined in memory.

Internally, references are implemented using pointers, but this is beyond the scope of your question.

References have restrictions over other types in C++ - for example, you must always initialize a reference to "refer" to a real object when you create it, while a pointer may point to memory which is invalid, or uninitialized.

---

## Pointer to a reference

This doesn't exist. As stated earlier, a reference is merely an alias to another object. You can't "point" to a reference, because it isn't an object in itself but merely another name for a real object.

Of course, you can have a pointer to the object that a reference is referring to. But now we are back in vanilla pointer territory.

```cpp
int x = 10;
int& rx = x; // from now on, rx is just like x.
// Unlike pointers, refs are not real objects in memory.
int* p = &x; // Ok
int* pr = &rx; // OK! but remember that rx is just x!
// i.e. rx is not something that exists alone, it has to refer to something else.
if( p == pr ) // true!
{ ... }
```

---

## __Note about parameters__

When you pass a parameter __by value__ to a method or routine, you are essentially passing a "copy" of the object to the method. Any changes you make to the value within the routine will be lost when the routine returns, because the parameter will be treated as a local variable in the context of the routine.

If you want to modify a parameter which is passed in so the client (calling) code can access the change, you must pass the parameter __by pointer__ or __by reference__.

```cpp
void myMethod(int myValue)
{
    // NOTE: This change will be lost to the caller!
    myValue = 5;
}

void myMethod2(int* myValue)
{
    // Correct way of modifying pointer parameter value
    *myValue = 5;
}

void myMethod3(int& myValue)
{
    // Correct way of modifying reference parameter value
    myValue = 5;
}
```

Let's now say that your method wants to allocate memory for a pointer. You could be tempted to do this:

```cpp
void myMethod4(int* myValue)
{
    // Warning: You will lose the address of the allocated
    // memory when you return!
    myValue = new int[5];
}
```

> But remember, you are modifying the copy of the pointer value here, not the real pointer value. Since you are wanting to modify the pointer in this routine, and not the value that the pointer "points" to, you need to pass it in as a "pointer to a pointer" or a "reference to a pointer":

```cpp
void myMethod5(int** myValue)
{
    // Correct way of allocating memory in a method
    // via pointer-to-pointer
    *myValue = new int[5];
}

void myMethod6(int*& myValue)
{
    // Correct way of allocating memory in a method
    // via reference-to-pointer
    myValue = new int[5];
}
```

## Resources

- [What is the Difference Between a Pointer and a Reference C++](https://www.youtube.com/watch?v=sxHng1iufQE "What is the Difference Between a Pointer and a Reference C++")
</br>
- [What is the Difference Between Pass By Pointer and Pass By Pointer Reference (int * and int * &) C++](https://www.youtube.com/watch?v=7HmCb343xR8 "What is the Difference Between Pass By Pointer and Pass By Pointer Reference")