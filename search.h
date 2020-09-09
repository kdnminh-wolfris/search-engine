#ifndef __SEARCH__
#define __SEARCH__

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>

#include "trie.h"
#include "query_handling.h"

using namespace std;

class firstSearch {
private:
	const string PATH = "DATABASE-PATH";
	map<string, int>* container = nullptr;
	//GATE CHECK
	int gate = 0;
	Trie* T = nullptr;
	string query;

	void exit();

	void intersection(vector<pair<string, int>> f2);

	vector<pair<string, int>> intersection(vector<pair<string, int>>* f1, vector<pair<string, int>>* f2);

	vector<pair<string, int>> search(string ss, Trie* T);

	string matchSearch(vector<string> quotes, string filename);

public:
	//SS STAND FOR SEARCH_STRING
	vector<pair<string, int>> intitle(string ss);

	vector<pair<string, int>> quote(vector<pair<string, int>> quotes);

	vector<pair<string, int>> origin(vector<pair<string, int>> origins);

	vector<pair<string, int>> findOr(vector<pair<string, int>> OR);

	vector<pair<string, int>> exclude(string ss);

	void trieFlow();

	firstSearch(string query, Trie* T);
};
#endif