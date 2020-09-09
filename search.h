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
	map<string, bool>* container = nullptr;
	//GATE CHECK
	int gate = 0;

	Trie* T = nullptr;
	Trie* fileList = nullptr;
	string query;

	void exit();

	void intersection(vector<string> f2);

	vector<string> intersection(vector<string>* f1, vector<string>* f2);

	vector<string> search(string ss, Trie* T);

	string matchSearch(vector<string> quotes, string filename);

public:
	//SS STAND FOR SEARCH_STRING
	void intitle(string ss);
	void quote(vector<pair<string, int>> quotes);
	void origin(vector<pair<string, int>> origins);

	void findOr(vector<pair<string, int>> OR);

	void exclude(string ss);

	firstSearch(string query, Trie* T);

	firstSearch(string query, Trie* T, Trie* fileList);
};
#endif