#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main(){
	ifstream scalesFile("theScales.txt");	
	vector<string> scales;
	string item;

	if (scalesFile.is_open()) {
		while (getline(scalesFile, item)) {			
			scales.push_back(item);
		}
		scalesFile.close();
	}

	for (int i=0; i<scales.size(); i++) {
		cout << scales[i] << endl;
	}	

	return 0;
}