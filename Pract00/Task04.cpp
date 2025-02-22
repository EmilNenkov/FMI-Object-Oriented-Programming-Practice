#include <iostream>

void inputArr(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		std::cin >> arr[i];
	}
}
 
bool checkIfMonotonousIncreasing(int* arr, int size) {
	if (size == 1) 
		return true;

	if (*arr > *(arr + 1))
		return false;

	return checkIfMonotonousIncreasing(++arr, size - 1);
}

int main() {
	unsigned int n;
	std::cin >> n;

	int* arr = new int[n];

	inputArr(arr, n);
	std::cout << checkIfMonotonousIncreasing(arr, n);
	delete[] arr;
}
