#include <bits/stdc++.h>

void Log(const char* message);

int mutliply(int a  , int b) {
	Log("Mutliply");
	return a * b;
}

int main(int argc, char const *argv[]) {
	
	std::cout << mutliply(5 , 8) << std::endl;

	return 0;
}