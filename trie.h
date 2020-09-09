#ifndef __TRIE__
#define __TRIE__

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class TrieNode {
public:
	vector <pair <string, int>> data;
	// first: file name; second: frequency

	TrieNode* child[256];
};

class Trie {
private:
	TrieNode* root = nullptr;

public:
	vector <pair <string, int>> search(string keyword);
	// search and rank all files to a vector based on the keyword
	// first: file name; second: point according to the keyword

	void build(string key, vector<pair<string, int>> data);

	void save(string filename);

	void load(string filename);

	void clear();
	// clear nodes
};

#endif