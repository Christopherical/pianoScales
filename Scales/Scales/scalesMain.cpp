#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

int main(){
	ifstream scalesFile("theScales.txt");
	vector<string> dynamics = { "(p)", "(mf)", "(f)" };
	vector<string> articulation = { "legato", "stacatto" };
	vector<string> scales;
	string item;
	string exit;

	srand(time(0));
	
	//Read theScales.txt file and push them into vector.
	if (scalesFile.is_open()) {
		while (getline(scalesFile, item)) {			
			scales.push_back(item);
		}
		scalesFile.close();
	}	

	//Output Random scale with random articulation and dynamics.
	while (true) {
		if (exit != "a") {
			cout << scales[(rand() % scales.size())] + " + " << dynamics[(rand() % dynamics.size())] + " + "
				<< articulation[(rand() % articulation.size())] << +"." << endl;
			cin >> exit;
		}
		else {
			break;
		}
	}	
	
	return 0;
}