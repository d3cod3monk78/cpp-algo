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