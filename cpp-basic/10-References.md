# References

> __Reference__ a really just an extension of _pointers_.
</br>
</br>
> __Pointers__ and __References__ are pretty much the same thing as far as what the computer will actually do with them.
</br>
</br>
> __Reference is a syntax sugar on top of pointers to make it a little bit easier to read and little bit easier to follow.__

## A __Reference__ is a way to reference an existing variable

Unlike a pointer where you could create a new pointer variable and then set it equal to _nullptr_ or something like that, you can't do something like that with reference.
__Because _reference_ has to reference an already existing variable. References are themselves are not new variables.__
</br>
__Reference are do not occupy memory.__

---

```cpp
#include <iostream>

int main(int argc, char const *argv[]) {
 int a = 10;
 int& ref = a; //reference
 std::cout << ref << std::endl;
 return 0;
}
```

---

```cpp
#include <iostream>

void incrementPointer(int* value) {
 (*value)++;
}

void incrementReference(int& value) {
 value++;
}

void increment(int value) {
 value++;
}

int main(int argc, char const *argv[]) {
 int a = 10;
 int& ref = a; 
 increment(a);
 std::cout << a << std::endl; 
 incrementPointer(&a);
 std::cout << a << std::endl; 
 incrementReference(ref);
 std::cout << a << std::endl; 
 return 0;
}
```

```bash
 Output: 
  10
  11
  12
```
