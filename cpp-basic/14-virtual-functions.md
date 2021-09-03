# Virtual functions

Virtual functions allow us to override methods inside the subclasses.

```cpp
#include <iostream>
#include <string>

class Entity {
public:
 std::string getName() {
    return "Entity";
 }
};

class Player : public Entity {
private:
  std::string m_Name;

public:
 Player(const std::string& name) : m_Name(name) { 
 } 
 std::string getName() { return this->m_Name; }
};

int main(int argc, char const *argv[]) {  
  Entity* e = new Entity();
  std::cout << e->getName() << std::endl;  
  Player* p = new Player("d3cod3monk");
  std::cout << p->getName() << std::endl;  
  return 0;
}
```

```bash
Output:
  Entity
  d3cod3monk
```

If we decide to use concept of polymorphism which means if i start referring to the `Player` class as if it was an `Entity` that we are run into a problem

```cpp
#include <iostream>
#include <string>

class Entity {
public:
 std::string getName() {
    return "Entity";
 }
};

class Player : public Entity {
private:
  std::string m_Name;

public:
 Player(const std::string& name) : m_Name(name) { 
 } 
 std::string getName() { return this->m_Name; }
};

int main(int argc, char const *argv[]) {  
  Entity* e = new Entity();
  std::cout << e->getName() << std::endl;  
  Player* p = new Player("d3cod3monk");
  std::cout << p->getName() << std::endl;  
  
  // Adding polymorphism
  Entity* ptr = new Player("d3cod3monk");
  std::cout << ptr->getName() << std::endl;
  return 0;
}
```

```bash
Output:
  Entity
  d3cod3monk
  Entity
```

```cpp
#include <iostream>
#include <string>

class Entity {
public:
  std::string getName() {
    return "Entity";
  }
};

class Player : public Entity {
private:
  std::string m_Name;

public:
  Player(const std::string& name) : m_Name(name) {  
  }  
  std::string getName() { return this->m_Name; }
};

void printName(Entity* ptr) {
   std::cout << ptr->getName() << std::endl;
}

int main(int argc, char const *argv[]) {
  Entity* e = new Entity();
  printName(e);  
  Player* p = new Player("d3cod3monk");
  printName(p);  
  return 0;
}
```

```bash
Output:
  Entity
  Entity
```

That is why virtual functions come in.

> Virtual functions that reduce something called dynamic dispatch which compiles typically implemented by __V table__.
</br>
</br>
> __V table__ is basically a table which contains a mapping for all the virtual functions but our base class so that we can map them to the correct overwritten methods at runtime.

---

> All you basically need to know is that if you want to override a function, you have to mark the base function in the base class as `virtual`.

---

```cpp
#include <iostream>
#include <string>

class Entity {
public:
  virtual std::string getName() {
    return "Entity";
  }
};

class Player : public Entity {
private:
  std::string m_Name;

public:
  Player(const std::string& name) : m_Name(name) {  
  }  
  std::string getName() override { return this->m_Name; }
};

void printName(Entity* ptr) {
   std::cout << ptr->getName() << std::endl;
}

int main(int argc, char const *argv[]) {
  Entity* e = new Entity();
  printName(e);  
  Player* p = new Player("d3cod3monk");
  printName(p);  
  return 0;
}
```

```bash
Output:
  Entity
  d3cod3monk
```
