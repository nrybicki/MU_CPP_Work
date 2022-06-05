// Copyright (c) Nick Rybicki, 3/8/22

#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char* argv[]) {
	if (argc != 3) {
		cout << "you should type two file names" << endl;
		return 1;
	}
	
	ifstream inFile(argv[1]);
	ofstream outFile(argv[2]);

	if (!inFile.good() || !outFile.good()) {
		cout << "unable to open one of the files" << endl;
		return 2;
	}

	string line;
	while (getline(inFile, line)) {
		outFile << line << endl;
	}

	inFile.close();
	outFile.close();

	return 0;
}
