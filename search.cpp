#include "search.h"

using namespace std;

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>

#include "trie.h"
#include "query_handling.h"

void firstSearch::exit()
{
	//INTERFACE WHEN NULL INTERSECTION
	cout << "There are no match results !!" << endl;
	return;
}

void firstSearch::intersection(vector<pair<string, int>> f2)
{
	if (!this->container || this->container->size() == 0)
	{
		if (!this->container) this->container = new map<string, int>;
		for (auto it = f2.begin(); it != f2.end(); it++)
		{
			(*this->container)[it->first] = it->second;
		}
		return;
	}
	//HAVE NOT OPTIMIZED YET
	map<string, int>* newContainer = new map<string, int>;
	for (auto it = f2.begin(); it != f2.end(); it++)
	{
		auto temp = this->container->find((*it).first);
		if (temp == this->container->end()) continue;
		(*newContainer)[temp->first] = true;
	}

	delete this->container;
	this->container = newContainer;
	return;
}

vector<pair<string, int>> firstSearch::intersection(vector<pair<string, int>>* f1, vector<pair<string, int>>* f2)
{
	//code goes here;
	vector<pair<string, int>> result;
	return result;
}

vector<pair<string, int>> firstSearch::search(string ss, Trie T)
{
	return T.search(ss);
}

string firstSearch::matchSearch(vector<string> quotes, string filename)
{
	//REMEMBER TO CHANGE PATH FOR FILENAME
	ifstream f;
	string path = this->PATH + filename;
	f.open(path);

	int i = 0, size = quotes.size();
	bool flag = false;
	char t;
	string temp;
	while (f >> t && i < size)
	{
		if (t == ' ' || t < 'a' || t > 'z' || t < '0' || t >'9')
		{
			if (flag == false)
			{
				if (temp == quotes[0]) flag = true, i++;
				temp = "";
				continue;
			}

			if (temp == quotes[i]) i++;
			else return "";
			temp = "";
			continue;
		}
		temp.push_back(t);
	}
	return filename;
}


//SS STAND FOR SEARCH_STRING
vector<pair<string, int>> firstSearch::intitle(string ss)
{
	return;
}

vector<pair<string, int>> firstSearch::quote(string quotes)
{
	return vector<pair<string, int>>();
}

vector<pair<string, int>> firstSearch::origin(vector<pair<string, int>> origins)
{
	vector<pair<string, int>>* result = nullptr;
	for (vector<pair<string, int>>::iterator it = origins.begin(); it != origins.end(); it++)
	{
		if (!result)
		{
			result = new vector<pair<string, int>>;
			(*result) = this->search((*it).first, this->T);
			continue;
		}
		vector<pair<string, int>>* temp = new vector<pair<string, int>>;
		(*temp) = this->search((*it).first, this->T);
		(*result) = this->intersection(result, temp);
		delete temp;
	}

	this->intersection((*result));
	delete result;
	return;
}

vector<pair<string, int>> firstSearch::findOr(vector<pair<string, int>> OR)
{
	return vector<pair<string, int>>();
}

vector<pair<string, int>> firstSearch::exclude(string ss)
{
	return vector<pair<string, int>>();
}

firstSearch::firstSearch(string query, Trie T)
{
	if (this->T.isEmpty()) this->T = T;
	else return;
}