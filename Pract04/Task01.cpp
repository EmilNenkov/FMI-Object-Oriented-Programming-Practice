#include <iostream>
#include <fstream>

bool isEven(int num) { return num % 2 == 0; }
bool isOdd(int num) { return num % 2 == 1; }

void printNums(int* nums, unsigned int size) {
    for (int i = 0; i < size; i++) {
        std::cout << nums[i] << " ";
    }
    std::cout << std::endl;
}

void writeNumbersInFile(std::ofstream& ofNumbers, int* nums, unsigned int size) {
    ofNumbers.write(reinterpret_cast<char*>(nums), size * sizeof(int));
}

unsigned int getSizeBuffer(bool (*pred)(int), const int* buffer, const unsigned int size_of_file) {
    unsigned int counter = 0;
    for (unsigned int i = 0; i < size_of_file; i++) {
        if (pred(buffer[i])) {
            counter++;
        }
    }
    return counter;
}

unsigned int getSize(std::ifstream& ifNumbers) {
    std::streampos pos = ifNumbers.tellg();
    ifNumbers.seekg(0, std::ios::end);
    unsigned int size = ifNumbers.tellg();
    ifNumbers.seekg(pos);
    return size;
}

int main() {
    std::ifstream ifNumbers("numbers.dat", std::ios::binary);
    std::ofstream ofEvenNums("even_nums.dat", std::ios::binary);
    std::ofstream ofOddNums("odd_nums.dat", std::ios::binary);

    if (!ifNumbers.good() || !ifNumbers.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

    unsigned int numbers_file_size = getSize(ifNumbers) / sizeof(int);
    if (numbers_file_size == 0) {
        std::cerr << "File is empty or error in reading file size!" << std::endl;
        return 1;
    }

    int* numbers = new int[numbers_file_size];
    ifNumbers.read(reinterpret_cast<char*>(numbers), numbers_file_size * sizeof(int));

    unsigned int even_size = getSizeBuffer(isEven, numbers, numbers_file_size);
    unsigned int odd_size = getSizeBuffer(isOdd, numbers, numbers_file_size);

    int* odd_nums = new int[odd_size];
    int* even_nums = new int[even_size];

    int e = 0, o = 0;
    for (unsigned int i = 0; i < numbers_file_size; i++) {
        if (isEven(numbers[i])) {
            even_nums[e++] = numbers[i];
        }
        else {
            odd_nums[o++] = numbers[i];
        }
    }

    writeNumbersInFile(ofEvenNums, even_nums, even_size);
    writeNumbersInFile(ofOddNums, odd_nums, odd_size);

    ifNumbers.close();
    ofEvenNums.close();
    ofOddNums.close();

    printNums(even_nums, even_size);
    printNums(odd_nums, odd_size);

    delete[] numbers;
    delete[] odd_nums;
    delete[] even_nums;

    return 0;
}
