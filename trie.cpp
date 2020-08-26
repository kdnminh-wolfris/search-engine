#include "trie.h"
#include "system.h"

#include <iostream>
#include <fstream>
#include <queue>

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
	
}