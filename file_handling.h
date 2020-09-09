#ifndef __FILE_HANDLING__
#define __FILE_HANDLING__

#include "query_handling.h"

vector <string> load_file_names(string index_file);
// load file names to a vector from __index.txt

vector <pair <string, int>> import_file(string filename);
// filter out stopwords, read keywords and their frequency and return to vector

Trie import_data();
Trie import_data()
{
	Trie head;
	vector<string> AllFileName = load_file_names("___index.txt");
	while (!AllFileName.empty())
	{
		// Load file index
		vector<pair<string, int>> wordsandfreq = import_file(AllFileName.back());

		// Build tree
		head.build(AllFileName.back(), wordsandfreq);
		
		AllFileName.pop_back();
	}
	return head;
}
// read from __index.txt file names and then start importing from files to a trie

void rank(vector <string>& filename);
// rank files based on query and then sort them

#endif
