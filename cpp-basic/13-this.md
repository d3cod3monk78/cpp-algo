# __‘this’__ pointer in C++

To understand ‘this’ pointer, it is important to know how objects look at functions and data members of a class.

- Each object gets its own copy of the data member.
- All-access the same function definition as present in the code segment.

</br>
Meaning each object gets its <mark style="background-color: #E3E6E8" >own copy of data members</mark> and all objects <mark style="background-color: #E3E6E8" >share a single copy of member functions</mark>.
</br>
</br>

Then now question is that if only one copy of each member function exists and is used by multiple objects, how are the proper data members are accessed and updated?
</br>
</br>
The compiler supplies an implicit pointer along with the names of the functions as ‘this’.
The ‘this’ pointer is passed as a hidden argument to all non-static member function calls and is available as a local variable within the body of all non-static functions. ‘this’ pointer is not available in static member functions as static member functions can be called without any object (with class name).

---

## The situations where ‘this’ pointer is used

- __When local variable’s name is same as member’s name__

```cpp
#include<iostream>
using namespace std;

/* local variable is same as a member's name */
class Test
  {
  private:
  int x;
  public:
  void setX (int x)
  {
     // The 'this' pointer is used to retrieve the   object's   x
     // hidden by the local variable 'x'
     this->x = x;
  }
  void print() { cout << "x = " << x << endl; }
};

int main()
{
   Test obj;
   int x = 20;
   obj.setX(x);
   obj.print();
   return 0;
}

```

- __To return reference to the calling object__

```cpp
/* Reference to the calling object can be returned */
Test& Test::func ()
{
   // Some processing
   return *this;
}

```
