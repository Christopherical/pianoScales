#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

int main(){
	//TODO: add functions for choosing the scales.
	//TODO: add header file to store functions.
	//Todo: change choice variable to something less stupid.

	ifstream scalesFile("theScales.txt");
	vector<string> dynamics = { "(p)", "(mf)", "(f)" };
	vector<string> articulation = { "legato", "stacatto" };
	vector<string> scales;
	string item;
	string exit;
	string choice;
	srand(time(0));
	
	//Read theScales.txt file and push them into vector.
	if (scalesFile.is_open()) {
		while (getline(scalesFile, item)) {			
			scales.push_back(item);
		}
		scalesFile.close();
	}	
	cout << "Please choose yes for all 5." << endl;
	cin >> choice;
	if (choice == "yes") {
		for (int i = 0; i < 6; i++) {
			cout << scales[(rand() % scales.size())] + " + " << dynamics[(rand() % dynamics.size())] + " + "
				<< articulation[(rand() % articulation.size())] << +"." << endl;
		}
	}
	else {		
		while (true) {
			if (exit != "a") {
				cout << scales[(rand() % scales.size())] + " + " << dynamics[(rand() % dynamics.size())] + " + "
					<< articulation[(rand() % articulation.size())] << +".\n" << endl;
				cin >> exit;
			}
			else {
				break;
			}
		}
	}	
	
	string a;
	cin >> a;
	return 0;
}