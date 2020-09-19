#include "file_handling.h"
#include "trie.h"
#include "search.h"
#include "query_handling.h"

#include <vector>
#include <chrono>
#include <ctime>
#include <time.h>
#include <iostream>
#include <string>

using namespace std;
using namespace std::chrono;

bool cmp(pair <string, int> a, pair <string, int> b) {
	return a.second > b.second;
}

int main() {
	int mode = 1;
	Trie tree;
	if (mode) {
		auto start = std::chrono::system_clock::now();
		File_Handling fh;
		tree = fh.head;
		auto end = std::chrono::system_clock::now();
		std::chrono::duration<double> elapsed_seconds = end - start;
		std::time_t end_time = std::chrono::system_clock::to_time_t(end);

		char str[26];
		ctime_s(str, sizeof(str), &end_time);
		std::cout << "finished computation at " << str
			<< " elapsed time: " << elapsed_seconds.count() << "s\n";
		//fh.clear();
	}
	else tree.load("save");

	do {
		//system("cls");
		cout << "---------------Search Engine----------Group 10-----\n";
		cout << "---------------------------------------------------\n";
		cout << "Search (or leave a blank and enter to exit): ";
		string query; getline(cin, query);
		if (query == "") break;
		cout << "\nTop 5 results:\n";
		
		//CLOCK
		auto start = high_resolution_clock::now();

		firstSearch SE(query, tree);
		vector <pair <string, int>> res = SE.search();

		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<microseconds>(stop - start);
		//END CLOCK
		cout << "Searched in: "
			<< duration.count() << " microseconds" << endl << endl;

		numtag(0); cout << " Do another search\n\n";
		if (res.size() == 0)
			cout << "There are no results that match your search :(\n";
		sort(res.begin(), res.end(), cmp);
		for (int i = 0; i < 5 && i < res.size(); ++i) {
			numtag(i + 1); cout << " " << res[i].first << "\n\n";
			preview(res[i].first, 300); cout << '\n' << endl;
		}
		int opt = int_option(min(5, (int) res.size()) + 1);
		system("cls");
		if (opt == 0) continue;
		int tmp = opt - 1; // ???
		fullview(res[tmp].first);
		cout << "\n\nPress ESC to exit...";
		esc_pressed();
	} while (true);
	tree.clear();
}
