#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]){
	FILE* f = NULL;

	if((f = fopen("test.txt" , "w+")) == NULL) {
		printf("Cannot creat file\n");
		exit(EXIT_FAILURE);
	}

	char* s;

	while(!feof(f)) {
		fputs(s , f);
	}

	fclose(f);

	return 0;
}