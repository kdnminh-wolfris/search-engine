#include "file_handling.h"
#include "trie.h"
#include "search.h"
#include "query_handling.h"

#include <vector>
#include <iostream>
#include <string>

using namespace std;

int main() {
	//File_Handling FH;
	//Trie T = FH.head;
	Trie T;
	T.load("save");
	cout << "If Trie was loaded succesfully: " << T.isEmpty() << endl;
	T.trieTraverse();
	//vector<pair<string, int>> temp = T.search("greedy");

	/*std::cout << temp.size();
	for (auto it = temp.begin(); it != temp.end(); it++)
	{
		cout << it->first << " " << it->second << endl;
	}
	return 0;*/
}