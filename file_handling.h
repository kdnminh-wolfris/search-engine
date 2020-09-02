#ifndef __FILE_HANDLING__
#define __FILE_HANDLING__

#include "query_handling.h"
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include <sstream>
#include <algorithm>

void importfileExe(vector<pair<string, int>>& result, string& cmpstr, string* arr);
void filterPunctation(string& str);
bool isStopWord(string cmpstr, string* stopword);
vector <string> load_file_names(string index_file);
// load file names to a vector from __index.txt

vector <pair <string, int>> import_file(string filename);
// filter out stopwords, read keywords and their frequency and return to vector

Trie import_data();
// read from __index.txt file names and then start importing from files to a trie

void rank(vector <string>& filename);
// rank files based on query and then sort them

#endif
