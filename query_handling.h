#ifndef __QUERY_HANDLING__
#define __QUERY_HANDLING__

#include "trie.h"

class QueryHandling {
public:
	void filter(string& search_string);
	vector<vector<string>> OR(string& search_string);
	string intitle(string& search_string);
	string exclude(string& search_string);
	string price(string& search_string);

	void ToLower(string& word);

	vector <pair <string, int>> solve(string query);
};

#endif
