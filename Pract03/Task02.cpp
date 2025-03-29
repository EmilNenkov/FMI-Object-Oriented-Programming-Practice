#include <iostream>
#include <fstream>

void printMostCommon(int *&arr, unsigned int size) {
    int most_common = arr[0];
    unsigned int counter = 0;
    unsigned int highest_count = counter;

    for (int i = 0; i < size; i++) {
        counter = 0;
        for (int j = 0; j < size; j++) {
            if (i == j) continue;
            if (arr[i] == arr[j]) counter++;
            if (counter > highest_count) {
                highest_count = counter;
                most_common = arr[i];
            }
        }
    }
    std::cout << most_common;
}

void inputArr(int*& arr, unsigned int &n) {
    std::ifstream ifNums("nums.txt");

    if (!ifNums.is_open() || !ifNums.good()) {
        return;
    }

    ifNums >> n;
    arr = new (std::nothrow) int[n];

    for (int i = 0; i < n; i++) {
        ifNums >> arr[i];
    }
    ifNums.close();
}

int main()
{
    int* arr;
    unsigned int n = 0;
    inputArr(arr, n);
    printMostCommon(arr, n);
    delete[] arr;
}
