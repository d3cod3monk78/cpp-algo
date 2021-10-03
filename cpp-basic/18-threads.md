# Threads

- In every application, there is a thread called _main thread_. This is the default thread of a program.
- __If want or create a thread it has to be created in the main thread.__
- A thread is also known as a lightweight process. This idea is achieved by parallelism by dividing a process into a multiple threads.

## Ways to create a thread

- By Function pointers
- By Lambda functions
- By function objects
- By member functions
- by static member functions

## Single threaded process

```c++
#include <algorithm>
#include <chrono>
#include <iostream>

typedef unsigned long long ull;

ull oddSum = 0;
ull evenSum = 0;

void findEven(ull start, ull end) {
    for (ull x = start; x < end + 1; x++) {
        if ((x & 1) == 0) {
            evenSum += x;
        }
    }
}

void findOdd(ull start, ull end) {
    for (ull x = start; x < end + 1; x++) {
        if ((x & 1) == 1) {
            oddSum += x;
        }
    }
}

int main(int argc, char const *argv[]) {
    ull start = 0;
    ull end = 1000000000;

    auto startTime = std::chrono::high_resolution_clock::now();

    findEven(start, end);
    findOdd(start, end);

    auto endTime = std::chrono::high_resolution_clock::now();

    std::cout << "Even Sum: " << evenSum << std::endl;
    std::cout << "Odd Sum: " << oddSum << std::endl;
    std::chrono::duration<double> timeDeff = endTime - startTime;
    std::cout << "Time: " << timeDeff.count() << std::endl;
    return 0;
}
```

## Multithreading approach

```c++
#include <algorithm>
#include <chrono>
#include <iostream>
#include <thread>

typedef unsigned long long ull;

ull oddSum = 0;
ull evenSum = 0;

void findEven(ull start, ull end) {
    for (ull x = start; x < end + 1; x++) {
        if ((x & 1) == 0) {
            evenSum += x;
        }
    }
}

void findOdd(ull start, ull end) {
    for (ull x = start; x < end + 1; x++) {
        if ((x & 1) == 1) {
            oddSum += x;
        }
    }
}

int main(int argc, char const *argv[]) {
    ull start = 0;
    ull end = 1000000000;
    auto startTime = std::chrono::high_resolution_clock::now();

    std::thread threadOne(findEven, start, end);
    std::thread threadTwo(findOdd, start, end);

    // allow to finish the thread
    threadOne.join();
    threadTwo.join();

    auto endTime = std::chrono::high_resolution_clock::now();

    std::cout << "Even Sum: " << evenSum << std::endl;
    std::cout << "Odd Sum: " << oddSum << std::endl;
    std::chrono::duration<double> timeDeff = endTime - startTime;
    std::cout << "Time: " << timeDeff.count() << std::endl;
    return 0;
}
```

> If we create multiple threads at the same time it does not guarantee which one will start first.

### By function pointers

```c++
#include <iostream>
#include <thread>

void fun(int x) {
    while (x-- > 0) {
        std::cout << x << std::endl;
    }
}

int main(int argc, char const *argv[]) {
    std::thread t1(fun, 10);
    std::thread t2(fun, 20);

    t1.join();
    t2.join();
    return 0;
}
```

### By Lambda functions

```c++
#include <iostream>
#include <thread>

int main(int argc, char const *argv[]) {
    auto fun = [](int x) {
        while (x-- > 0) {
            std::cout << x << std::endl;
        }
    };

    std::thread t1(fun, 10);
    std::thread t2(fun, 20);

    t1.join();
    t2.join();
    return 0;
}
```

### By Function objects

```c++
#include <iostream>
#include <thread>

class Base {
   public:
   // this is a function object
    void operator()(int x) {
        while (x-- > 0) {
            std::cout << x << std::endl;
        }
    }
};

int main(int argc, char const *argv[]) {
    std::thread t1(Base(), 10);
    t1.join();
    return 0;
}

```

### Non-static member functions

```c++
#include <iostream>
#include <thread>

class Base {
   public:
    void fun(int x);
};

void Base::fun(int x) {
    while (x-- > 0) {
        std::cout << x << std::endl;
    }
}

int main(int argc, char const *argv[]) {
    Base *b = new Base();
    std::thread t1(&Base::fun, b, 10);

    t1.join();

    delete b;
    return 0;
}
```

### Static member functions

```c++
#include <iostream>
#include <thread>

class Base {
   public:
    static void fun(int x);
};

void Base::fun(int x) {
    while (x-- > 0) {
        std::cout << x << std::endl;
    }
}

int main(int argc, char const *argv[]) {
    std::thread t1(&Base::fun, 20);

    t1.join();
    return 0;
}
```

## Use of `join()`, `detach()` and `joinable()`

### `join()`

- Once a thread is started we wait for this thread to finish by calling `join()`.
- Double `join()` will result into program termination

```c++
#include <iostream>
#include <chrono>
#include <thread>

void run(int x) {
    while(x --> 0) {
        std::cout << "Threads: " << x << std::endl; 
    }
}

int main(int argc, char const *argv[]) {
    std::thread t1(run , 10);
    t1.join();
    return 0;
}
```

### `detach()`

- This is used to detach newly created thread from parent thread.
- Always check `joinable()`

```c++
#include <iostream>
#include <chrono>
#include <thread>

void run(int x) {
    while(x --> 0) {
        std::cout << "Threads: " << x << std::endl;
    }
    std::this_thread::sleep_for(std::chrono::seconds(3));
}

int main(int argc, char const *argv[]) {
    std::thread t1(run , 10);
    if(t1.joinable()) {
        t1.detach();
    }
    std::cout << "After" << std::endl;
    return 0;
}
```

### `Joinable`

```c++
#include <iostream>
#include <chrono>
#include <thread>

void run(int x) {
    while(x --> 0) {
        std::cout << "Threads: " << x << std::endl;
    }
    std::this_thread::sleep_for(std::chrono::seconds(3));
}

int main(int argc, char const *argv[]) {
    std::thread t1(run , 10);
    if(t1.joinable()) {
        t1.join();
    }
    std::cout << "After" << std::endl;
    return 0;
}
```

## Mutex - Mutual Execution

### Race conditions

- Race Condition is a situation where two or more threads/processes happened to change a common data at the same time.
- If there is a race condition then we have to protect it and the protected section is called the critical section or region.

### Mutex

- Mutex is used to avoid race condition.
- we use `lock()` and `unlock()` on mutex to avoid race condition.

```c++
#include <iostream>
#include <thread>
#include <mutex>

std::mutex m;

int myAccount = 0;

void addMoney() {
    m.lock();
    myAccount++;
    m.unlock();
}

int main(int argc, char const *argv[]) {
    std::thread t1(addMoney);
    std::thread t2(addMoney);

    t1.join();
    t2.join();

    std::cout << myAccount << std::endl;
    return 0;
}
```

## Mutex `try_lock`

- `try_lock()` try to lock the mutex. Returns immediately. On successful lock acquisition returns true otherwise returns false.
- if `try_lock()` is not able to lock the mutex, then it doesn't get blocked. That's why it is called non-blocking.
- if `try-lock()` is called again by the same thread which owns the mutex, the behavior is undefined.
- It is a dead lock behavior with undefined behavior

```cpp
#include <iostream>
#include <thread>
#include <mutex>

int counter = 0;
std::mutex m;

void increaseCounter() {
    for(auto i = 0; i < 1000; i++) {
        if(m.try_lock()) {
            counter++;
            m.unlock();
        }
    }
}

int main(int argc, char const *argv[]) {
    std::thread t1(increaseCounter);
    std::thread t2(increaseCounter);

    t1.join();
    t2.join();

    std::cout << counter << std::endl;
    return 0;
}
```

## `std::try_lock()`

- `std::try_lock()` tries to lock all the lockable objects passed in it one by one in given order

```c++
std::try_lock(m1 , m2 , m3 , .... , mn);
```

- On success this function returns -1. Otherwise it will return __0-based__ mutex index number which it could not lock
- If it fails to lock any of the mutex then it will __release__  all the mutex it locked before.
- If a call to `try_lock()` result in an exception, unlock is called for any locked objects before re-throwing