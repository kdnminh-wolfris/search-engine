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
	//VARIABLES
	string query;
	const string PATH = "DATABASE-PATH";
	map<string, int>* container = nullptr;
	Trie T;
	QueryHandling QH;

	void exit();

	void intersection(vector<pair<string, int>> f2);

	vector<pair<string, int>> intersection(vector<pair<string, int>> f1, vector<pair<string, int>> f2);

	vector<string> intersection(vector<string> f1, vector<string> f2);

	vector<pair<string, int>> unionSet(vector<pair<string, int>> f1, vector<string, int>> f2);

	vector<pair<string, int>> search(string ss, Trie T);

	string matchSearch(vector<string> quotes, string filename);

public:
	//SS STAND FOR SEARCH_STRING
	vector<pair<string, int>> quote(string quotes);

	vector<pair<string, int>> origin(vector<pair<string, int>> origins);

	vector<pair<string, int>> findOr(vector<pair<string, int>> OR);

	vector<pair<string, int>> exclude(string ss);

	void trieFlow();

	vector <pair <string, int>> intitle(string word);

	vector <pair <string, int>> filetype(string type);

	firstSearch(string query, Trie T);
};
#endif