#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char const *argv[]) {
	
	std::ifstream f = std::ifstream("test.txt" , std::ios::in);

	if(!f.is_open()) {
		std::cout << "File cannot open" << std::endl;
	}

	std::string s;

	while(f.tellg != std::ios_base::end) {
		f.getline(s , sizeof(s));
		std::cout << s << std::endl;
	}

	f.close();

	return 0;
}