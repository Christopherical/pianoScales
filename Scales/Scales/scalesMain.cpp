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

	// Rowan's TODO List:
	// string initialisation can be simplified
	// Put the file reading into it's own class
	// Don't use a number typed out for the selection of all (5), or in the loop after it
	// Change program flow so at all times you can get all, get one, or exit - look at switch statements
	// Whilst not wrong, it's typically frowned upon from my experience to use while(true)

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