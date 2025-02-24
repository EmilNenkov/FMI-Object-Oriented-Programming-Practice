#include <iostream>

void inputArr(int *arr, unsigned int size) {
    for (int i = 0; i < size; i++) {
        std::cin >> arr[i];
    }
}

bool isEven(int num) {
    return num % 2 == 0;
}

bool isOdd(int num) {
    return num % 2 == 1;
}

bool isPrime(int num) {
    for (int i = 0; i < num / 2; i++) {
        if ((num / 2) % i == 0) {
            return false;
        }
    }
    return true;
}

unsigned int countSatisfied(int *arr, unsigned int size, bool (*func)(int)) {
    unsigned int counter = 0;
    for (int i = 0; i < size; i++) {
        counter += func(arr[i]);
    }
    return counter;
}

int main() {
    unsigned int n;
    std::cin >> n;
    int* arr = new int[n];
    inputArr(arr, n);
    std::cout << countSatisfied(arr, n, isEven);
    delete[] arr;
}
