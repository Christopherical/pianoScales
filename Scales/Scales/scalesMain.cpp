#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <windows.h>
#include <typeinfo>

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

int getInt() {
	string returnedInt;
	cin >> returnedInt;	
	return stoi(returnedInt);
}

int main(){	

	// Rowan's TODO List:
	// string initialisation can be simplified DONE
	// Put the file reading into it's own class DONE
	// Don't use a number typed out for the selection of all (5), or in the loop after it
	// Change program flow so at all times you can get all, get one, or exit - look at switch statements
	// Whilst not wrong, it's typically frowned upon from my experience to use while(true) DONE
	
	vector<vector<string>> dynamicsArticulation = { { "(p)", "(mf)", "(f)" }, { "legato", "stacatto" } };		
	string exit;
	readFileReturnScales readFile;	
	vector<string> scales = readFile.readScales("theScales.txt");

	cout << "How many scales?";
	int amount = getInt();
	cout << amount;

	/*

	srand(time(0));	
	
	while (exit != "y") {			
		cout << "-------------------------\n\n";
		for (int i = 0; i < amount; i++) {
			cout << i+1 << ":" << scales[(rand() % scales.size())] + " + " << dynamicsArticulation[0][(rand() % dynamicsArticulation[0].size())] + " + "
				<< dynamicsArticulation[1][(rand() % dynamicsArticulation[1].size())] << +".\n\n";
		}
		cout << "-------------------------\n";

		cout << "\nEnter \'yes\' to exit\n\n";
		cin >> exit;
		exit = tolower(exit[0]);		
	}	
	*/
	
	return 0;
}