#include "file_handling.h"
#include "trie.h"
#include "search.h"
#include "query_handling.h"
#include "system.h"
#include "option.h"
#include "tools.h"

#include <vector>
#include <iostream>
#include <string>

using namespace std;

bool cmp(pair <string, int> a, pair <string, int> b) {
	return a.second > b.second;
}

int main() {
	cout << "---------------Search Engine----------Group 10-----\n";
	cout << "---------------------------------------------------\n";
	cout << "Search (leave a blank and enter to exit): ";
	string query; getline(cin, query);
	if (query == "") return 0;
	cout << "\nTop 5 results:\n";
	numtag(0); cout << " Do another search\n";
	firstSearch SE;
	vector <pair <string, int>> res = SE.search(query);
	sort(res.begin(), res.end(), cmp);
	for (int i = 0; i < 5 && i < res.size(); ++i) {
		numtag(i + 1); cout << " " << res[i].first << "\n\n";
		preview(res[i].first); cout << '\n';
	}
	int opt = int_option(6);
	if (opt == 0) return main();
	
}
