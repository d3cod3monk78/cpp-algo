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