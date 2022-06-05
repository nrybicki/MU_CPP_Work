// Copyright (c) Nick Rybicki, 3/8/22

#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char* argv[]) {
	if (argc != 3) {
		cout << "you need to type a file name and line count" << endl;
		return 1;
	}

	ifstream inFile(argv[1]);

	if (!inFile.good()) {
		cout << "cannot open the file" << endl;
		return 2;
	}

	string line;
	int lineCount = 0;
	while (getline(inFile, line) && lineCount < atoi(argv[2])) {
		cout << line << endl;
		lineCount++;
	}

	inFile.close();

	return 0;
}
