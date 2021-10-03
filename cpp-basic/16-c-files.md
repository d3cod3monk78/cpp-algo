# __C__ File I/O

## Files

> File can be any input or output device

It can be a keyboard , it can be a display screen, it can be a printer , it can even be a text file.

> Information can extract from text file and information can enter into a text file. Because of that text file can act like input and output device.

When dealing with files, there are two types of files you should know about:

- Text files
- Binary filesa

### Text files

Text files are the normal .txt files. You can easily create text files using any simple text editors such as Notepad.

When you open those files, you'll see all the contents within the file as plain text. You can easily edit or delete the contents.

They take minimum effort to maintain, are easily readable, and provide the least security and takes bigger storage space.

### Binary files

Binary files are mostly the .bin files in your computer.

Instead of storing data in plain text, they store it in the binary form (0's and 1's).

They can hold a higher amount of data, are not readable easily, and provides better security than text files.

---

## Streams

A program accepts data or information in streams.

> A stream is a simply a sequence of bytes.

There are two types of major streams

- Text stream

> _Text stream_ is a sequence of characters. C allows a text stream to be organized into lines terminated by a newline character `\n`.

- Binary stream

> _Binary stream_ is a sequence of bytes.

---

## Standard Streams

There are three types of standard streams.

- stdin -> `FILE*`
- stdout -> `FILE*`
- stderr -> `FILE*`

![Streams](https://i.imgur.com/UbzZQqY.png)

## File System Operations

| Operation   | Process                                                        |
| ----------- | -------------------------------------------------------------- |
| `fopen()`   | Opens a file                                                   |
| `fclose()`  | Closes a file                                                  |
| `fputc()`   | Writes a character to a file                                   |
| `fgetc()`   | Reads a character from a file                                  |
| `fgets()`   | Reads a string from a file                                     |
| `fputs()`   | Writes a string to a file                                      |
| `fseek()`   | Seeks to a specified byte in a file                            |
| `fprintf()` | Is to a file what `printf()` is to the console                 |
| `fscanf()`  | Is to a file what `scanf()` is to the console                  |
| `feof()`    | Returns true if end-of-file is reached                         |
| `remove()`  | Erase a file                                                   |
| `fflush()`  | Flushes a file                                                 |
| `rewind()`  | Resets the file position indicator to the beginning of the file |

> You de-associate a file from a specific stream with close operation. If you close a file opened for output, the contents, if any, of its associated streams are written to the external device. This process is generally referred to as _flushing_ the stream, and guarantees that no information is accidentally left in the disk buffer.

## Opening a file or Creating a file

```c
    FILE* fopen(const char* filename , const char* mode);
```

- __File opening modes in C__

| Mode    | Meaning                                       |
| ------- | --------------------------------------------- |
| __r__   | Opens a text file for reading                 |
| __w__   | Opens a text file for writing                 |
| __a__   | Append to a text file                         |
| __rb__  | Opens a binary file for reading               |
| __wb__  | Opens a binary file for writing               |
| __ab__  | Append to a binary file                       |
| __r+__  | Opens a text file for read/write              |
| __w+__  | Opens a text file for read/write              |
| __a+__  | Append or create a text file for read/write   |
| __rb+__ | Opens a binary file for read/write            |
| __wb+__ | Opens a binary file for read/write            |
| __ab+__ | Append or create a binary file for read/write |

```c
FILE* fp;
fp = fopen("test.txt", "w");
```

```c
FILE* fp;

if((fp = fopen("test.txt" , "r")) == NULL) {
    printf("Cannot open file.\n");
    exit(EXIT_FAILURE);
}
```

## Closing a file

```c
int fclose(FILE* fp);
// Succuss - returns 0
// If an error occurs - return EOF
```

## Writing a character

```c
int fputc(int ch , FILE* f);
```

- Write a character

```c
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]){
    FILE* f = NULL;    
    if((f = fopen("test.txt" , "w+")) == NULL) {
        printf("Cannot creat file\n");
        exit(EXIT_FAILURE);
    }    
    fputc('c' , f);    
    fclose(f);    
    return 0;
}
```

- Write lines into the file

```c
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]){
FILE* f = NULL;
if((f = fopen("test.txt" , "w+")) == NULL) {
    printf("Cannot creat file\n");
    exit(EXIT_FAILURE);
}
char ch;
while((ch = getchar()) != EOF) {
    fputc(ch , f);
}
fclose(f);
return 0;
}
```

## Reading a character

```c
int fgetc(FILE* f);
```

```c
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]){
    FILE* f = NULL;    
    if((f = fopen("test.txt" , "w+")) == NULL) {
        printf("Cannot creat file\n");
        exit(EXIT_FAILURE);
    }    
    char ch;    
    while((ch = getchar()) != EOF) {
        fputc(ch , f);
    }    
    rewind(f);    
    while((ch = fgetc(f)) != EOF) {
        printf("%c" , ch);
    }    
    fclose(f);    
    return 0;
}
```

---

## feof

```c
int feof(FILE* f);
```

---

## rewind

```c
void rewind(FILE* f);
```

---

## Erasing files

```c
int remove(const char* filename);
```

---

## Flushing a stream

```c
int fflush(FILE* f);
```
