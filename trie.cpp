#include "trie.h"
#include "system.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <queue>
#include <utility>

void Trie::save(std::string filename)
{
	std::ofstream out;
	out.open(get_link("cheatsheet", filename), std::ios::app);

	std::queue<TrieNode*> que;
	que.push(root);

	while (!que.empty)
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
		out << '\n';
		for (int c = 0; c < 26; ++c)
			que.push(u->child[c]);
	}
}

void Trie::load(std::string filename)
{
	std::ifstream inp;
	inp.open(get_link("cheatsheet", filename));

	std::queue<TrieNode*> que;
	que.push(root);

	while (!inp.eof())
	{
		TrieNode*& u = que.front();
		que.pop;

		for (int c = 0; c < 26; ++c)
		{
			std::string line;
			std::getline(inp, line);

			if (line == "0")
			{
				u->child[c] = nullptr;
				continue;
			}

			u->child[c] = new TrieNode;
			std::istringstream iss(line);

			do
			{
				std::string word, number;
				iss >> word >> number;

				std::string file = word;
				int frequency = std::stoi(number);

				u->child[c]->data.push_back(std::make_pair(std::string(file), frequency));
			} while (iss);

			que.push(u->child[c]);
		}
	}
}