#include "Corner_Grocer.h"
#include <algorithm>  // For std::transform
#include <cctype> // For std::to lower

using namespace std;

// Read item file and write data to .dat file
void ItemFrequency::ReadandWrite() {

	ifstream inFS; // Input stream variable
	ofstream outFS; // Output stream variable
	string item; // Variable to hold item input
	map<string, int> newList; // Map to hold keys and values for item list

	// Open file
	inFS.open("C:\\Users\\frank\\OneDrive\\Documents\\C++\\Corner Grocer\\Resource\\CS210_Project_Three_Input_File.txt");
	outFS.open("frequency.dat");

	// Check if files are open
	if (!inFS.is_open()) {
		cout << "Error: Could not open input file.\n" << endl;
		return;
	}

	if (!outFS.is_open()) {
		cout << "Error: Could not create output file.\n" << endl;
		return;
	}

	inFS >> item; // Input from file


	// Assigns keys in map with item value and increments key value if already contained in map
	while (inFS >> item) {		
		if (newList.find(item) == newList.end()) {
			newList[item] = 1;
			}
		else {
			newList[item]++;
			}
		}
	inFS.close(); // Close file

	// Write map contents to .dat file
	for (const auto& pair : newList) {
		outFS << pair.first << ' ' << pair.second << endl;
	}
	outFS.close(); // Close file

	list = newList; // Assign private map variable with map created in this function for use later
}

// transform string and map from Itemfrequency function to lowercase
string ToLowercase(const string& str) {

	string lowerStr = str;

	transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), [](unsigned char c) {
		return tolower(c); });

	return lowerStr;
}

void ItemFrequency::ItemSearch() {

	string item;

	cout << "Enter item:\n";
	cin >> item;

	// Convert user input to lowercase
	string lowerItem = ToLowercase(item);

	bool found = false;

	// Iterate through the map to compare case-insensitive keys
	for (const auto& pair : list) {
		if (ToLowercase(pair.first) == lowerItem) {
			cout << pair.first << " " << pair.second << endl;
			found = true;
			break;
		}
	}

	if (!found) {
		cout << "Item not found." << endl;
	}
}

// return map of items and frequencies
map<string, int> ItemFrequency::GetMap() {
	return list;
}

// print item frequencies in histogram format
void ItemFrequency::PrintHistogram() {
	for (const auto& pair : list) {
		cout << pair.first << ' ';
		for (int i = 0; i < pair.second; i++) {
			cout << '*';
		}
		cout << endl;
	}
}