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
		vector<pair<string, int>> wordsandfreq = import_file(AllFileName.back()); // <word, freq>
		vector<pair<string, int>> fileandfreq;                                    // <filename, freq>

		// Convert <word,freq> to <filename, freq>
		while (!wordsandfreq.empty())
		{
			// Convert <word,freq> to <filename, freq>
			fileandfreq.push_back(make_pair(AllFileName.back(), wordsandfreq.back().second));

			// Build Trie
			head.build(wordsandfreq.back().first, fileandfreq);

			// Remove 
			wordsandfreq.pop_back();
			fileandfreq.pop_back();
		}
		AllFileName.pop_back();
	}
	return head;
}
// read from __index.txt file names and then start importing from files to a trie

void rank(vector <string>& filename);
// rank files based on query and then sort them

#endif
