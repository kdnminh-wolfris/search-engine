#include "file_handling.h"
#include "trie.h"
#include "search.h"
#include "query_handling.h"

#include <vector>
#include <iostream>
#include <string>

using namespace std;

int main() {

	Trie T;

	T.load("save");

	//T.trieTraverse();

	/*FILE FEEDING AND TRIE SAVING TEST*/
	//File_Handling FH;
	//Trie T = FH.head;
	
	/*TRIE SEARCHING TEST*/
	string tmp;
	do 
	{
		cout << "Searching for: ";
		tmp = "";
		cin >> tmp;
		cout << "Search result for: " << tmp << endl;
		vector<pair<string, int>> result = T.search(tmp);
		if (!result.size()) continue;
		for (auto it = result.begin(); it != result.end(); it++)
			cout << it->first << " " << it->second << endl;
	} while (tmp != "exit");
	return 0;
}