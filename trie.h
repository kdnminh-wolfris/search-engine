#ifndef __TRIE__
#define __TRIE__

#include <iostream>
#include <vector>

using namespace std;

class TrieNode {
public:
	vector <pair <string, int>> data;
	// first: file name; second: frequency

	TrieNode* child[26];
};

class Trie {
private:
	TrieNode* root;

public:
	vector <pair <string, int>> search(string keyword);
	// search and rank all files to a vector based on the keyword
	// first: file name; second: point according to the keyword

	void build(string filename, vector <pair <string, int>> data);
	// data of a file are keywords and their frequency

	void save(string filename);
	//save trie to filename in folder cheatsheet. format: <word> <frequency>

	void load(string filename);
	//load a vector <pair <string, int> > in filename from folder cheatsheet

	void clear();
	// clear nodes
};

#endif