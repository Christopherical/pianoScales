#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

class readFileReturnScales {
public:	
	vector<string> returnedFile;
	string item;
	vector<string> readScales(string scalesTxt) {
		ifstream scalesFile(scalesTxt);
		
		if (scalesFile.is_open()) {
			while (getline(scalesFile, item)) {
				returnedFile.push_back(item);
			}
			scalesFile.close();
		}
		return returnedFile;		
	}	
};

int main(){

	

	//TODO: add functions for choosing the scales.
	//TODO: add header file to store functions.
	//Todo: change choice variable to something less stupid.

	// Rowan's TODO List:
	// string initialisation can be simplified DONE
	// Put the file reading into it's own class DONE
	// Don't use a number typed out for the selection of all (5), or in the loop after it
	// Change program flow so at all times you can get all, get one, or exit - look at switch statements
	// Whilst not wrong, it's typically frowned upon from my experience to use while(true)
	
	//vector<vector<string>> dynamicsArticulation = { { "(p)", "(mf)", "(f)" }, { "legato", "stacatto" } };
	vector<string> dynamics = { "(p)", "(mf)", "(f)" };
	vector<string> articulation = { "legato", "stacatto" };
	vector<string> scales;
	string item, exit, choice;	
	readFileReturnScales readFile;
	scales = readFile.readScales("theScales.txt");

	srand(time(0));		
		
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
		
	
	
	return 0;
}