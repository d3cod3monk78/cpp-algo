#include <bits/stdc++.h>
void bubbleSort(int arr[] , int n) {
	for(auto i = 0; i < n - 1; i++) {
		bool isSwaped = false;

		for(auto j = 0; j < n - i - 1; j++) {
			if(arr[j] > arr[j + 1]) {
				auto temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				isSwaped = true;
			}
			for(auto k = 0; k < 10; k++) {
				std::cout << arr[k] << " ";
			}
			std::cout << std::endl;
		}

		for(auto k = 0; k < 10; k++) {
			std::cout << arr[k] << " ";
		}
		std::cout << std::endl;
		std::cout << std::endl;

		if(!isSwaped) {
			break;
		}
	}
}

int main(int argc, char const *argv[]) {
	int arr[10] = { 4 , 9 , 1 , 7 , 3 , 8 , 2 , 0 , 5 , 6 };
	for(auto k = 0; k < 10; k++) {
			std::cout << arr[k] << " ";
		}
		std::cout << std::endl;
		std::cout << std::endl;
	bubbleSort(arr , 10);
	return 0;
}