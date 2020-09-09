#ifndef __FILE_HANDLING__
#define __FILE_HANDLING__

#include "query_handling.h"
#include "trie.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

class File_Handling{
private:
	string FILENAME;
	void importfileExe(vector<pair<string, int>>& result, string& cmpstr, string* arr);
	void filterPunctation(string& str);
	bool isStopWord(string cmpstr, string* stopword);
public:
	vector <string> load_file_names(string index_file);
	//Task 2: load file names to a vector from __index.txt

	vector <pair <string, int>> import_file(string filename);
	//task 1: filter out stopwords, read keywords and their frequency and return to vector

	Trie import_data();
	//task 3

	File_Handling(string filename);
};

void rank(vector <string>& filename);
// rank files based on query and then sort them

#endif
