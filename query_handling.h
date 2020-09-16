#ifndef __QUERY_HANDLING__
#define __QUERY_HANDLING__

#include "trie.h"

class QueryHandling {
private:
	vector<vector<string>> OR(string& search_string);

	string intitle(string& search_string);

	string exclude(string& search_string);

	string price(string& search_string);

	void ToLower(string& word);

	pair<string, string> range(string extract_string);

	vector<string> quotes(string extract_string);

	vector<string> origin(string& ss);
public:
	void filter(string& search_string);

	vector<vector<string>> orRe;

	string intitleRe;

	string excludeRe;

	string priceRe;

	pair<string, string> rangeRe;

	vector<string> quotesRe;

	vector<string> originRe;

	QueryHandling();

	QueryHandling(string& query);
};

#endif
