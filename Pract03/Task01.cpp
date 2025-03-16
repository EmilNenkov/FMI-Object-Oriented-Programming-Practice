#include <iostream>
#include <fstream>

void inputSumAndDiff(double &num1, double &num2) {
    std::ofstream outFile("result1.txt");
    double sum = num1 + num2;
    double diff = num1 - num2;
    outFile << "Sum of numbers: " << sum << " Difference of numbers: " << diff;
}

void outputOrigianlNums(double &num1, double &num2) {
    std::ifstream inFile("result1.txt");
    char buffer[1024];
    while (inFile.getline(buffer, 1024)) {
        std::cout << buffer << std::endl;
    }
    std::cout << "Original nums: " << num1 << ", " << num2;
}

int main() {
    double num1, num2;
    std::cin >> num1 >> num2;
    inputSumAndDiff(num1, num2);
    outputOrigianlNums(num1, num2);
}
