#ifndef __FILE_HANDLING__
#define __FILE_HANDLING__

#include "query_handling.h"
#include "trie.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <regex>
#include <map>

#include <sstream>	
#include <algorithm>

class File_Handling{
private:
	string FILENAME;

	TrieNode* stopword = nullptr;

	TrieNode* loadStopword();

	void importfileExe(map<string, int> &result, string& cmpstr, TrieNode* stopword);

	void filterPunctation(string& str);

	bool isStopWord(string cmpstr, TrieNode* stopword);

	//REGULAR EXPRESSION
	regex unicode = regex("[^\\u0020-\\u0024\\u0030-\\u0039\\u0041-\\u005A\\u0061-\\u007A\\u002E]+");
public:
	vector<string> load_file_names(string index_file);

	map<string, int> import_file(string filename);

	Trie import_data();

	Trie head;

	File_Handling(string filename);

	File_Handling();
};

#endif
