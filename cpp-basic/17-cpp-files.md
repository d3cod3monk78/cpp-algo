# __C++__ File I/O

## Stream based I/O

![stream hierarchy](https://media.geeksforgeeks.org/wp-content/cdn-uploads/20191129162746/CPP-File-Handling.png)

- __fstream__: Stream class to both read and write from/to files
- __ofstream__: Stream class to writes on files
- __ifstream__: Stream class to read from files

## Opening a file

- __Opening file using constructor__

```cpp
#include <ifstream>

ifstream(const char* filename , ios_base::openmode mode = ios_base::in);
ifstream(filename , openmode); // by default openmode=ios_base::in
ifstream fin("filename");
```

- __Opening file using method__

```cpp
ifstream fin; // calling default contructor
fin.open("filename" , openmode);
fin.open("filename");
```

## Modes

| Mode | Stands for | Access |
|------|------------|--------|
|__in__|input|File open for reading: The internal stream buffer supports input operations|
|__out__|output|File open for writing: The internal stream buffer supports output operations|
|__binary__|binary|Operations are performed in binary mode rather than text|
|__ate__|at end|The output position starts at the end of the file|
|__app__|append|All output operations happen at the end of the file, appending to its existing file|
|__trunc__|truncate| Any contents that existed in the file before it is open are discarded|

- __Default open modes__

|Stream|Default mode|
|------|------------|
|__ifstream__|ios::in|
|__ofstream__|ios::out|
|__fstream__|ios::in / ios::out|

## Closing a file

```cpp
void close();
```

## Is open

```cpp
bool is_open();
```

## __ofstream__ - Write into files

- `operator<<()`

```cpp
#include <iostream>
#include <fstream>

int main(int argc, char const *argv[]) {
    std::ofstream f = std::ofstream("test.txt" ,std::ios::out);
    if(!f.is_open()) {
        std::cout << "File cannot open" <<std::endl;
    }
    f << "What the fuck is going on" << std::endl;
    f << "Yeah man we are heading to your home ";
    f << "Wait what" << std::endl;
    f.close();
    return 0;
}
```

- `put()`

```cpp
basic_ostream& put(char_type ch);
```

```cpp
#include <iostream>
#include <fstream>

int main(int argc, char const *argv[]) {
    std::ofstream f = std::ofstream("test.txt" ,    std::ios::app);

    if(!f.is_open()) {
        std::cout << "File cannot open" <<    std::endl;
    }

    f.put('\n');
    f.put('\n');
    f.put('\n');
    f.put('t');
    f.put('\n');
    f.put('e');
    f.put('\n');
    f.put('s');
    f.put('\n');
    f.put('t');
    f.put('\n');

    f.close();    
    return 0;
}
```

## __ifstream__ - Read from files

- `operator>>()`

```cpp
#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char const *argv[]) {
    std::ifstream f = std::ifstream("test.txt" ,    std::ios::in);

    if(!f.is_open()) {
        std::cout << "File cannot open" <<    std::endl;
    }    
    std::string s;    
    f >> s;    
    std::cout << s << std::endl;    

    f.close();
    return 0;
}
```

- `get()`

```cpp
#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char const *argv[]) {
    std::ifstream f = std::ifstream("test.txt" ,    std::ios::in);

    if(!f.is_open()) {
        std::cout << "File cannot open" <<    std::endl;
    }    

    char ch = f.get();    
    std::cout << ch << std::endl;    

    f.close();    
    return 0;
}
```

- `getline()`

```cpp
basic_ostream& getline(char_type* s , std::streamsize count , char_type delim);
```

```cpp
#include <iostream>
#include <sstream>
#include <vector>
#include <array>
 
int main()
{
    std::istringstream input("abc|def|gh");
    std::vector<std::array<char, 4>> v;
 
    // note: the following loop terminates when std::ios_base::operator bool()
    // on the stream returned from getline() returns false
    for (std::array<char, 4> a; input.getline(&a[0], 4, '|'); ) {
        v.push_back(a);
    }
 
    for (auto& a : v) {
        std::cout << &a[0] << '\n';
    }
}
```
