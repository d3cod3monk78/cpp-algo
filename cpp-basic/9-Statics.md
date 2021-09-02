# Statics

The _static_ key word in c++ has two meaning depending on what the context is. One of those applies to when use the _static_ keyword

- Outside of a class or struct
- Inside a class or struct

## Static use in outside of a class or struct

Static outside of a class or struct means that the linkage of that symbol that you declared to be static is going to be internal meaning. It's only going to visible to that translation unit that you've defined it.

## Static in side a class or struct

A static variable in side a class or struct means that variable is actually going to share memory with all of the instances of the class meaning that basically across all instances that you create of that class or struct, there's only going to be one instance of that _static_ variable. And similar thing applied to static methods in a class.

```cpp
// This variable is only going to be linked internally
// inside this translation unit
static int s_variable = 10;

// If remove the static keyword it will give a linking error
// int s_variable = 10;
```

## Static in a class or struct

```cpp
#include <iostream>

struct Entity {
 static int x , y;

 void print() {
  std::cout << x << " , " << y << std::endl;
 }
};

int Entity::x;
int Entity::y;

int main(int argc, char const *argv[]) {
 Entity a;

 Entity::x = 10;
 Entity::y = 20

 Entity b;
 b.x = 5;
 b.y = 10;


 a.print();
 b.print();

 return 0;
}
```

## Static methods inside a class

A static method does not have a class instance.

```cpp
#include <iostream>

struct Entity {
 int x , y; 
 static void print() {
  std::cout << x << " , " << y << std::endl;
 }
};

int Entity::x;
int Entity::y;

int main(int argc, char const *argv[]) {
 Entity a; 
 a::x = 10;
 b::y = 20 
 Entity b;
 b.x = 5;
 b.y = 10; 
 a.print();
 b.print(); 
 return 0;
}
```

```bash
 Output: This will give an error
```
