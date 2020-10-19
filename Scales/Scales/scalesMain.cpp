#include <iostream>
#include <fstream>

using namespace std;

int main(){

	ifstream scalesFile("theScales.txt");
	string scale;	

	while (scalesFile >> scale) {
		cout << scale;
	}

	return 0;
}