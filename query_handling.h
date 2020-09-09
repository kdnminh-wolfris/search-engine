#ifndef __QUERY_HANDLING__
#define __QUERY_HANDLING__

#include "trie.h"
#include <vector>

class QueryHandling {
private:
	string ss;

	//FUNCTION FOR OPERATOR GOES HERE
	
public:
	void filter(string& search_string);

	//VARIABLE TO HOLD THE RESULT
	vector<string> origin;
	vector<vector<string>> OR;
	vector<string> quote;
	string intittle;
	string exclude;
	string price;
	pair<string, string> range;
	int wildcard;

	QueryHandling(string ss);

	QueryHandling()
	{
		//DEFAULT CONSTRUCTOR
		return;
	}
};


#endif
