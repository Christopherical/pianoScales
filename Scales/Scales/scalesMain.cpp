#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

//Read File Class.
class readFileReturnScales { // this class name is horrific :P call it something like "ScaleReader", then call the function "ReadScalesFromFile"
public:	
	vector<string> returnedFile;//this should not be global
	string item;//this should alos not be global
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

//Input Validation.
int getInt() {
	int amount;
	while (!(cin >> amount)) {
		cout << "Error: Input was not a number. Input a number\n";
		cin.clear();
		cin.ignore(22, '\n');
	}
	return amount;
}

int main(){	

	// Rowan's TODO List:
	// look into static classes and consider using it on readFileReturnScales
	// Put the file reading class into it's own header and .cpp files, and learn the importance of using a header file
	// Look into C++ endl
	// You can't enter more than one number
	
	vector<vector<string>> dynamicsArticulation = { { "(p)", "(mf)", "(f)" }, { "legato", "stacatto" } }; //Does this need to by a vector within a vector?
	string exit;
	readFileReturnScales readFile;	
	vector<string> scales = readFile.readScales("theScales.txt");

	cout << "How many scales?";
	int amount = getInt();	

	srand(time(0));	
	
	while (exit != "y") {			
		cout << "-------------------------\n\n";
		for (int i = 0; i < amount; i++) {

			//Make this easier to read
			cout << i+1 << ":" << scales[(rand() % scales.size())] + " + " << dynamicsArticulation[0][(rand() % dynamicsArticulation[0].size())] + " + "
				<< dynamicsArticulation[1][(rand() % dynamicsArticulation[1].size())] << +".\n\n";
		}
		cout << "-------------------------\n";

		cout << "\nEnter \'yes\' to exit\n\n";
		cin >> exit;
		exit = tolower(exit[0]);		
	}
	
	return 0;
}