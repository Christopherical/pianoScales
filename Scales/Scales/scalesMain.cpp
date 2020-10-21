#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

int main(){
	ifstream scalesFile("theScales.txt");
	vector<string> dynamics = { "p", "mf", "f" };
	vector<string> articulation = { "legato", "stacatto" };
	vector<string> scales;
	string item;

	srand(time(0));

	
	if (scalesFile.is_open()) {
		while (getline(scalesFile, item)) {			
			scales.push_back(item);
		}
		scalesFile.close();
	}
	

	for (int i = 0; i < 100; i++) {
		cout << (rand() % scales.size()) << endl;
	}
	
	
	string a;
	cin >> a;
	return 0;
}