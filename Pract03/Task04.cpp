#include <iostream>
#include <fstream>

bool compareBuffers(char* buffer1, char* buffer2) {
	char *ptr1 = buffer1;
	char *ptr2 = buffer2;

	while (*ptr1 || *ptr2) {
		if (*ptr1 != *ptr2) return false;
		ptr1++;
		ptr2++;
	}
	return true;
}

void getFirstLineDifferent(std::ifstream& file1, std::ifstream& file2) {
	char buffer1[1024];
	char buffer2[1024];

	while (file1.getline(buffer1, 1024)) {
		file2.getline(buffer2, 1024);
		if (!compareBuffers(buffer1, buffer2)) {
			std::cout << buffer1;
		}
	}
}

int main()
{
	std::ifstream ifFile1("textfile1.txt");
	std::ifstream ifFile2("textfile2.txt");
	getFirstLineDifferent(ifFile1, ifFile2);
	ifFile1.close();
	ifFile2.close();
}
