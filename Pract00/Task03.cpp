#include <iostream>

int returnSumOfDigits(unsigned long long num) {
	if (!num) {
		return 0;
	}

	return num % 10 + returnSumOfDigits(num / 10);
}

int main() {
	unsigned long long num;
	std::cin >> num;
	std::cout << returnSumOfDigits(num);
}
