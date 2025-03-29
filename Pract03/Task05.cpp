#include <iostream>
#include <fstream>

struct Pair {
	unsigned int num1 = 0;
	unsigned int num2 = 0;
};

struct Relation {
	Pair pairs[25];
};

void addPairToRelation() {}

void readRelation(std::ifstream &ifFile, Relation &rel, unsigned int &idx) {
	if (!ifFile.is_open() || !ifFile.good()) {
		return;
	}
	
	while (!ifFile.eof() && ifFile.peek() != EOF && idx < 25) {
		Pair pair;
		ifFile >> pair.num1;
		ifFile >> pair.num2;
		rel.pairs[idx] = pair;
		idx++;
	}
}

void writePairsInFile(std::ofstream &ofFile, Relation &rel, unsigned int& count) {
	for (int i = 0; i < count; i++) {
		ofFile << "<" << rel.pairs[i].num1 << ", " << rel.pairs[i].num2 << ">" << "  ";
	}
 }

int main()
{
	unsigned int pairs_idx = 0;
	Relation rel;
	std::ifstream ifNums("nums.txt");
	std::ofstream ofPairs("pairs.txt", std::ios::app);
	readRelation(ifNums, rel, pairs_idx);
	writePairsInFile(ofPairs, rel, pairs_idx);
	ifNums.close();
	ofPairs.close();
}
