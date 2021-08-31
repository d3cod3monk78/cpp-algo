#include <bits/stdc++.h>
void selectionSort(int arr[] , int n) {
	for(auto i = 0; i < n-1; i++) {
		auto minPos = i;

		for(auto j = i + 1; j < n; j++) {
			if(arr[j] < arr[minPos]) {
				minPos = j;
			}
		}

		if(minPos != i) {
			auto temp = arr[i];
			arr[i] = arr[minPos];
			arr[minPos] = temp;
		}

		for(auto k = 0; k < 10; k++) {
			std::cout << arr[k] << " ";
		}
		std::cout << std::endl;
	}
}

int main(int argc, char const *argv[]) {
	int arr[10] = { 4 , 9 , 1 , 7 , 3 , 8 , 2 , 0 , 5 , 6 };
	selectionSort(arr , 10);
	return 0;
}