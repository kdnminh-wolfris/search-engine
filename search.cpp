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

void firstSearch::intersection(vector<string> f2)
{
	if (!this->container || this->container->size() == 0)
	{
		if (!this->container) delete this->container;
		this->exit();
		return;
	}
	//HAVE NOT OPTIMIZED YET
	map<string, bool>* newContainer = new map<string, bool>;
	for (auto it = f2.begin(); it != f2.end(); it++)
	{
		auto temp = this->container->find(*it);
		if (temp == this->container->end()) continue;
		(*newContainer)[temp->first] = true;
	}

	delete this->container;
	this->container = newContainer;
	return;
}

vector<string> firstSearch::intersection(vector<string>* f1, vector<string>* f2)
{
	//code goes here;
	vector<string> result;
	return result;
}
					
vector<string> firstSearch::search(string ss, Trie* T)
{
	if (!T) return vector<string>();
	return vector<string>();
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

public:
//SS STAND FOR SEARCH_STRING
void firstSearch::intitle(string ss)
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

void firstSearch::quote(vector<pair<string, int>> quotes)
{
	if (!quotes.size()) return;

	string first = quotes[0].first;
	vector<string> q;
	/*CONSTRUCT THE FULL QUOTE


	END CONSTRUCTING THE FULL QUOTE*/
	vector<string> tempResult = this->search(first, this->T);
	vector<string>* result = new vector<string>;
	for (vector<string>::iterator it = tempResult.begin(); it != tempResult.end(); it++)
	{
		string filename = this->matchSearch(q, *it);
		if (!filename.size()) continue;
		(*result).push_back(filename);
	}

	this->intersection(*result);
	delete result;
	this->gate++;
	return;
}

void firstSearch::origin(vector<pair<string, int>> origins)
{
	vector<string>* result = nullptr;
	for (vector<pair<string, int>>::iterator it = origins.begin(); it != origins.end(); it++)
	{
		if (!result)
		{
			result = new vector<string>;
			(*result) = this->search((*it).first, this->T);
			continue;
		}
		vector<string>* temp = new vector<string>;
		(*temp) = this->search((*it).first, this->T);
		(*result) = this->intersection(result, temp);
		delete temp;
	}

	this->intersection((*result));
	delete result;
	this->gate++;
	return;
}

void firstSearch::findOr(vector<pair<string, int>> OR)
{
	this->gate++;
	return;
}

void firstSearch::exclude(string ss)
{
	this->gate++;
	return;
}

firstSearch::firstSearch(string query, Trie* T)
{
	if (!this->T) this->T = T;
	this->query = query;
}

firstSearch::firstSearch(string query, Trie* T, Trie* fileList)
{
	if (!this->T) this->T = T;
	if (!this->fileList) this->fileList = fileList;
	this->query = query;
}
};