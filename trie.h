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

	TrieNode* child[36];
};

class Trie {
private:
	TrieNode* root;

public:
	vector <pair <string, int>> search(string keyword);
	// search and rank all files to a vector based on the keyword
	// first: file name; second: point according to the keyword

	void build(string key, vector <pair <string, int>> data);
	void build(string key, vector <pair <string, int>> data)
	{
		TrieNode* tmproot = root;
		for (int i = 0;i < key.length();++i)
		{
			int tmp = -1;
			// Numbers
			if (key[i] >= 48 && key[i] <= 57)
			{
				tmp = key[i] - 48;
			}
			// Uppercase letters
			if (key[i] >= 65 && key[i] <= 90)
			{
				tolower(key[i]);
			}
			// Lowercase letters
			if (key[i] >= 97 && key[i] <= 122)
			{
				tmp = key[i] - 87;
			}
			// Not in 3 cases above
			if (tmp == -1)
				continue;
			if (!root)
			{
				root = new TrieNode;
				tmproot = root;
			}
			else
				tmproot->child[tmp] = new TrieNode;
			tmproot = tmproot->child[tmp];
		}
		bool IsExisted = false;
		auto it = tmproot->data.begin();
		for (it = tmproot->data.begin(); it != tmproot->data.end(); ++it)
		{
			if (it->first == data[0].first)
			{
				IsExisted = true;
				break;
			}
		}
		if (!IsExisted)
		{
			tmproot->data.push_back(make_pair(data[0].first, data[0].second));
		}
		else
			it->second += data[0].second;
	}
	// data of a file are keywords and their frequency

	void save(string filename);

	void load(string filename);

	void clear();
	// clear nodes
};

#endif