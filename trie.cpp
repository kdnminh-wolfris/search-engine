#include "trie.h"
#include "system.h"

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

int get_index(char key)
{
	if ('0' <= key && key <= '9')
		return key - '0';
	if ('a' <= key && key <= 'z')
		return key - 'a' + 10;
	if ('A' <= key && key <= 'Z')
		return key - 'A' + 10;
	return -1;
}

int string_to_int(string str)
{
	int ans = 0;
	for (int i = 0; i < str.length(); ++i)
		ans = ans * 10 + (str[i] - '0');
	return ans;
}


void Trie::build(string filename, vector<pair<string, int>> data)
{
	cout << filename << " " << data.size() << endl;
	TrieNode *root = this->root;
	while (!data.empty())
	{
		string key = data.back().first;
		if (root == nullptr)
			root = new TrieNode;
		TrieNode* tmproot = root;
		for (int i = 0; i < key.length(); ++i)
		{
			int tmp = get_index(key[i]);

			if (tmp == -1)
				continue;

			if (tmproot->child[tmp] == nullptr)
				tmproot->child[tmp] = new TrieNode;

			tmproot = tmproot->child[tmp];
		}

		bool IsExisted = false;
		for (int i = 0; i < tmproot->data.size(); ++i)
			if (filename == tmproot->data[i].first)
			{
				tmproot->data[i].second += data.back().second;
				IsExisted = true;
				break;
			}

		if (!IsExisted)
			tmproot->data.push_back(make_pair(filename, data.back().second));
		data.pop_back();
	}

	if (!this->root) this->root = root;
}
// data of a file are keywords and their frequency

void Trie::save(string filename)
{
	ofstream out;
	out.open(get_link("cheatsheet", filename), ios::app);

	queue<TrieNode*> que;
	que.push(root);

	while (!que.empty())
	{
		TrieNode* u = que.front();
		que.pop();
		if (u == nullptr)
		{
			out << "0\n";
			continue;
		}
		for (int i = 0; i < u->data.size(); ++i)
			out << u->data[i].first << ' ' << u->data[i].second << ' ';
		out << "__END__ -1\n";
		for (int c = 0; c < 38; ++c)
			que.push(u->child[c]);
	}

	out.close();
}

void Trie::load(string filename)
{
	ifstream inp;
	inp.open(get_link("cheatsheet", filename));

	if (root == nullptr)
		root = new TrieNode;

	string line;
	getline(inp, line);

	queue<TrieNode*> que;
	que.push(root);

	while (!inp.eof())
	{
		TrieNode*& u = que.front();
		que.pop();

		for (int c = 0; c < 38; ++c)
		{
			getline(inp, line);

			if (line.length() == 0)
				break;

			if (line == "0")
			{
				u->child[c] = nullptr;
				continue;
			}

			u->child[c] = new TrieNode;
			istringstream iss(line);

			do
			{
				string word, number;
				iss >> word >> number;

				if (word == "__END__")
					break;

				string file = word;
				int frequency = string_to_int(number);


				u->child[c]->data.push_back(make_pair(string(file), frequency));
			} while (iss);

			que.push(u->child[c]);
		}
	}

	inp.close();
}

vector<pair<string, int>> Trie::search(string keyword) {
	if (!root)
	{
		return vector<pair<string, int>>();
	}

	TrieNode* tmp = root;
	for (int i = 0; i < keyword.length(); ++i)
	{
		if (!tmp) return vector<pair<string, int>>();
		tmp = tmp->child[get_index(keyword[i])];
	}
		
	return tmp->data;
}

void Trie::clear()
{
	return;
}

bool Trie::isEmpty()
{
	return (!this->root);
}
