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

int main() {
	auto start = std::chrono::system_clock::now();
	// Some computation here
	File_Handling FH;
	auto end = std::chrono::system_clock::now();

	std::chrono::duration<double> elapsed_seconds = end - start;
	std::time_t end_time = std::chrono::system_clock::to_time_t(end);

	char str[26];
	ctime_s(str, sizeof(str), &end_time);
	std::cout << "finished computation at " << str
		<< " elapsed time: " << elapsed_seconds.count() << "s\n";
}