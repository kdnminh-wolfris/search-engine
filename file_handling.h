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
		// Get file name in file index.txt
		string filename = AllFileName.back();
		AllFileName.pop_back();

		// Load file index
		vector<pair<string, int>> wordsandfreq = import_file(filename); // <word, freq>
		vector<pair<string, int>> tmp;                                  // <word, freq>
		vector<pair<string, int>> fileandfreq;                          // <filename, freq>

		// Convert <word,freq> to <filename, freq>
		while (!wordsandfreq.empty())
		{
			// Take last element of words and frequency
			tmp.push_back(wordsandfreq.back());

			// Convert <word,freq> to <filename, freq>
			fileandfreq.push_back(make_pair(filename, tmp.back().second));

			// Remove 
			wordsandfreq.pop_back();
		}
		vector<pair<string, int>> tmpfile;
		while (!tmp.empty())
		{
			// Take last element of file and frequency
			tmpfile.push_back(fileandfreq.back());

			// Build Trie
			head.build(tmp.back().first, tmpfile);

			// Remove
			tmp.pop_back();
			fileandfreq.pop_back();
			tmpfile.pop_back();
		}
	}
	return head;
}
// read from __index.txt file names and then start importing from files to a trie

void rank(vector <string>& filename);
// rank files based on query and then sort them

#endif
