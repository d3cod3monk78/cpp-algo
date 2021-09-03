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