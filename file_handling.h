#ifndef __FILE_HANDLING__
#define __FILE_HANDLING__

#include "query_handling.h"
#include "trie.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <regex>

#include <sstream>
#include <algorithm>

class File_Handling{
private:
	string FILENAME;

	string* stopword = nullptr;

	string* loadStopword();

	void importfileExe(vector<pair<string, int>>& result, string& cmpstr, string* arr);

	void filterPunctation(string& str);

	bool isStopWord(string cmpstr, string* stopword);

	//REGULAR EXPRESSION
	regex unicode = regex("[^\\u0000-\\u007F]+");
public:
	vector <string> load_file_names(string index_file);

	vector <pair <string, int>> import_file(string filename);

	Trie import_data();

	Trie head;

	File_Handling(string filename);

	File_Handling();
};

#endif
