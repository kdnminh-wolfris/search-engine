#ifndef __SEARCH__
#define __SEARCH__

#include <iostream>
#include <vector>
#include <map>
#include <string>

#include "trie.h"
#include "query_handling.h"

using namespace std;

class firstSearch {
private:
	map<string, bool>* container = nullptr;
	//GATE CHECK
	int gate = 0;

	Trie* T = nullptr;
	Trie* fileList = nullptr;
	string query;

	void exit()
	{
		//INTERFACE WHEN NULL INTERSECTION
		cout << "There are no match results !!" << endl;
		return;
	}

	void intersection(vector<string> f2)
	{
		if (!this->container || this->container->size == 0)
		{
			if (!this->container) delete this->container;
			this->exit();
			return;
		}
		//HAVE NOT OPTIMIZED YET
		map<string, bool> *newContainer = new map<string, bool>;
		for(auto it = f2.begin(); it != f2.end(); it++)
		{
			auto temp = this->container->find(*it);
			if (temp == this->container->end()) continue;
			(*newContainer)[temp->first] = true;
		}

		delete this->container;
		this->container = newContainer;
		return;
	}

	vector<string> search(string ss, Trie *T)
	{
		if (!T) return;
		//MOD LATER
		vector<string> result;
		return result;
	}

public:
	//SS STAND FOR SEARCH_STRING
	void intitle(string ss)
	{
		//LOAD A TRIE OF FILE
		vector<string> f2 = this->search(ss, fileList);
		for (auto it = f2.begin(); it != f2.end(); it++)
		{
			(*this->container)[*it] = true;
		}
		this->gate++;
		return;
	}

	void quote(vector<pair<string, int>> quotes)
	{
		vector<pair<string, int>> result;
		this->gate++;
		return;
	}

	void origin(vector<pair<string, int>> origins)
	{
		this->gate++;
		return;
	}

	void findOr (vector<pair<string, int>> OR)
	{
		this->gate++;
		return;
	}

	void exclude(string ss)
	{
		this->gate++;
		return;
	}

	firstSearch(string query, Trie* T)
	{
		if (!this->T) this->T = T;
		this->query = query;
	}

	firstSearch(string query, Trie* T, Trie* fileList)
	{
		if (!this->T) this->T = T;
		if (!this->fileList) this->fileList = fileList;
		this->query = query;
	}
};

#endif