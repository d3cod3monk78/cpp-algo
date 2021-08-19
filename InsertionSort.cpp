#include <bits/stdc++.h>

void insertionSort(int* arr , int n) {
	for(auto i = 1; i < n; i++) {
		auto current = arr[i];
		auto j = i - 1;

		while(j >= 0 && arr[j] > current) {
			arr[j + 1] = arr[j];
			j--;
		}

		arr[j + 1] = current;
	}
}

int main(int argc, char const *argv[]) {
	int arr[10] = { 9 , 3 , 5 , 8 , 2 , 0 , 4 , 1 , 7 , 6 };
	insertionSort(arr , 10);
	for(auto i = 0; i < 10; i++) {
		std::cout << arr[i] << std::endl;
	}
	return 0;
}