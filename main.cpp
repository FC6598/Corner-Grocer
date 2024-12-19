#include "Corner_Grocer.h"

using namespace std;

int main() {

	int input = 0; // initial user input variable

	ItemFrequency main; // declare object to call functions later
	main.ReadandWrite();

	// display option menu
	do {
		cout << "     Item Frequency Menu     \n";
		cout << "Option 1: Return frequency for specific item\n";
		cout << "Option 2: Print frequency for all items\n";
		cout << "Option 3: Print historgram of frequency for all items\n";
		cout << "Option 4: Exit program\n" << endl;
		cout << "Select Option: \"1\" for Option 1, \"2\" for Option 2, \"3\" for Option 3, \"4\" for Option 4\n";

		cin >> input; // get input
		
		// check for valid input
		while (input < 1 || input > 4 || cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input: Enter \"1\", \"2\", \"3\", or \"4\"\n";
			cin >> input;
		}

		map<string, int> frequencies = main.GetMap(); // map variable to hold return value

		// switch-case setup to determine correct action based on input
		switch (input) {
		case 1:
			main.ItemSearch();
			cout << endl;
			break;
		case 2: // print map with ranged for loop
			for (const auto& pair : frequencies) {
				cout << pair.first << ": " << pair.second << endl;
			}
			cout << endl;
			break;
		case 3:
			main.PrintHistogram();
			cout << endl;
			break;		
		}

	} while (input != 4); // condition to determine if the loop should continue

	return 0;
}