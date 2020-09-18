#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <iosfwd>
#include <ctype.h>
#include <regex>

#include "trie.h"
#include "file_handling.h"


using namespace std;

string* File_Handling::loadStopword()
{
	// Create array of stopwords
	string* arr = new string[174]; // 174 stopwords
	ifstream LoadStopWord;
	LoadStopWord.open("stopword.txt");
	if (!LoadStopWord.is_open())
	{
		cout << "File is not existed." << endl;
	}
	else
	{
		int i = 0;
		while (!LoadStopWord.eof())
		{
			LoadStopWord >> arr[i];
			++i;
		}
	}
	LoadStopWord.close();
	return arr;
}

bool File_Handling::isStopWord(string cmpstr, string* stopword)
{
	for (int i = 0; i < 174; i++)
	{
		if (cmpstr == stopword[i])
			return true;
	}
	return false;
}

void File_Handling::filterPunctation(string& str)
{
	for (int i = 0, len = str.size(); i < len; i++)
	{
		if (ispunct(str[i]))
		{
			str.erase(i--, 1);
			len = str.size();
		}
	}
}

void File_Handling::importfileExe(vector<pair<string, int>>& result, string& cmpstr, string* arr)
{
	stringstream ss;
	ss << cmpstr;
	cmpstr = "";

	while (!ss.eof())
	{
		ss >> cmpstr;

		//cmpstr.erase(remove_if(cmpstr.begin(), cmpstr.end(), ispunct), cmpstr.end());
		
		if (!this->isStopWord(cmpstr, arr) && !cmpstr.empty())
		{
			if (result.size() == 0)
			{
				result.push_back(make_pair(cmpstr, 1));
			}
			else
			{
				bool existed = false;
				for (int i = 0; i < result.size(); i++)
				{
					if (result[i].first == cmpstr)
					{
						result[i].second += 1;
						existed = true;
					}
				}
				if (existed == false)
					result.push_back(make_pair(cmpstr, 1));
			}
		}

	}
}

vector<string> File_Handling::load_file_names(string index_file)
{
	ifstream fin;
	fin.open(index_file);
	if (!fin.is_open())
	{
		cout << "Error loading index file" << endl;
		return vector<string>();
	}
	else
		cout << "Successfully open index file" << endl;
	char c;
	string temp = "";
	vector<string> result;
	while (fin.get(c))
	{
		if (c == '\n') continue;
		temp.push_back(c);
		if (temp.find("txt", 0) != string::npos)
		{
			temp = regex_replace(temp, this->unicode, "");
			cout << temp << endl;
			result.push_back(temp);
			temp = "";
		}
	}
	cout << "DONE READ ALL FILENAME" << endl;
	
	return result;
}

vector <pair <string, int>> File_Handling::import_file(string filename)
{
	ifstream fin;
	ofstream err;
	err.open("log.txt", ios::app);
	vector<pair<string, int>> result;
	fin.open(filename);
	if (!fin.is_open())
	{
		cout << "Open file error" << endl;
		err << filename << endl;
	}
	else
	{
		string temp;
		
		while (!fin.eof())
		{
			getline(fin, temp, '\n');
			temp = std::regex_replace(temp, this->unicode, " ");
			this->importfileExe(result, temp, this->stopword);
		}
		fin.close();
	}
	err.close();
	return result;
}

Trie File_Handling::import_data()
{
	Trie head;
	vector<string> AllFileName = this->load_file_names("data\\___index.txt");
	while (!AllFileName.empty())
	{
		// Load file index
		string filename = "data\\" + AllFileName.back();
		vector<pair<string, int>> wordsandfreq = import_file(filename);

		head.build(filename, wordsandfreq);

		AllFileName.pop_back();
	}
	return head;
}
// read from __index.txt file names and then start importing from files to a trie

File_Handling::File_Handling(string filename)
{
	//DEBUG 1
	this->FILENAME = filename;
	cout << this->FILENAME << endl;
	vector<pair<string, int>> temp = this->import_file(this->FILENAME);
	this->head = this->import_data();
	if (this->head.isEmpty()) cout << "This is fcking dead!!" << endl;
}

File_Handling::File_Handling()
{
	this->stopword = this->loadStopword();
	this->head = this->import_data();
	cout << "DONE IMPORTING" << endl;
	this->head.save("save");
	cout << "DONE SAVING" << endl;
}