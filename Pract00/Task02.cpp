#include <iostream>

bool returnIfkInN(unsigned long long n, int k) {
	if (n % 10 == k)
		return true;

	if (!n)
		return false;

	return returnIfkInN(n / 10, k);
}

int main() {
	unsigned long long n;
	int k;
	std::cin >> n >> k;
	std::cout << returnIfkInN(n, k);

	return 0;
}
