#include <iostream>

int returnSumFrom1ton(int n) {
	if(n == 0)
		return 0;

	return n + returnSumFrom1ton(n - 1);
}

int main() {
	int n;
	std::cin >> n;
	std::cout << returnSumFrom1ton(n);
}
