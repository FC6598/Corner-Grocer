#ifndef CORNER_GROCER_H
#define CORNER_GROCER_H
#include <iostream>
#include <fstream>
#include <map>
#include <string>

using namespace std;

class ItemFrequency {

private:

	map<string, int> list;

public:

	void ReadandWrite();
	map<string, int> GetMap();
	void ItemSearch();
	void PrintHistogram();

};
#endif