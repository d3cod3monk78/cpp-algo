# __C__ Inputs/Outputs

## printf

> In C programming, `printf()` is one of the main output function. The function sends formatted output to the screen.

```c
#include <stdio.h>    
int main()
{ 
    // Displays the string inside quotations
    printf("C Programming");
    return 0;
}
```

---

## scanf

In C programming, `scanf()` is one of the commonly used function to take input from the user. The `scanf()` function reads formatted input from the standard input such as keyboards.

```c
#include <stdio.h>
int main()
{
    int testInteger;
    printf("Enter an integer: ");
    scanf("%d", &testInteger);  
    printf("Number = %d",testInteger);
    return 0;
}
```

## Format Specifiers for I/O

- __%d__ for int
- __%f__ for float
- __%lf__ for double
- __%c__ for char

## puts

The `puts()` function writes the string str and a trailing newline to stdout.

```c
#include <stdio.h>
int main()
{
    int testInteger;
    printf("Enter an integer: ");
    scanf("%d", &testInteger);  
    puts(testInteger);
    return 0;
}
```

## Read lines in __C__

- This `scanf` mechanism does not allocate in all compilers.

```c
#include <stdin.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char* input;
    scanf("%m[^\n]%*c" , &input);
    printf("%s" , input);
    free(input);
}
```

- __getline__ mechanism

```c
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char* input = NULL; // input buffer , NULL forces getline to allocate
    size_t n = 0; // maximum characters to read (0 - no limit)
    ssize_t nchr = 0; // (number of characters actually read)

    if((nchr = getline(&input , &n , stdin )) != -1) {
        input[nchr - 1] = 0;
    }

    printf("%s" , input);
    free(input);
    return 0;
}
```

### example

```c
#include <stdio.h>
#include <stdlib.h>

int main(int argc , int argv[])
{
    FILE *stream;
    char* line = NULL;
    size_t len = 0;
    ssize_t nread;

    if(argc != 2) {
        fprintf(stderr , "Usage: %s <file>\n" , argv[0]);
        exit(EXIT_FAILURE);
    }

    stream = fopen(argv[1] , "r");

    if(stream == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    while((nread = getline(&line , &len , stream)) != -1 ) {
        printf("%zd" , nread);
        fwrite(line , nread , 1 , stdout);
    }

    free(line);
    fclose(stream);
    exit(EXIT_SUCCESS);
}
```
