#ifndef __QUERY_HANDLING__
#define __QUERY_HANDLING__

#include "trie.h"

class QueryHandling {
public:
	void filter(string& search_string);
	vector<pair<string, int>> OR(string search_string);
	string intitle(string search_string);
	string exclude(string search_string);
	string price();
};

void QueryHandling::filter(string& search_string)
{
	string substring;
	ifstream LoadStopWord;
	string* arr = new string[174]; // 174 stopwords
	LoadStopWord.open("stopword.txt");
	if (!LoadStopWord.is_open())
	{
		cout << "File is not existed." << endl;
	}
	else
	{
		// Create an array of stopwords' string
		int i = 0;
		while (!LoadStopWord.eof())
		{
			LoadStopWord >> arr[i];
		}
	}
	LoadStopWord.close();

	// Compare each word in search_string to stop-words and erase it from string
	string word;
	string tmpstr = search_string;
	int pos = 0; // first position of each word
	for (int i = 0;i < tmpstr.length();++i)
	{
		if (tmpstr[i] == ' ')
		{
			bool IsExisted = false; // check whether the word is in the stopword's list or not
			for (int i = 0;i < 174;++i)
			{
				if (word == arr[i])
				{
					// Filter stopword - erase word + ' ' 
					tmpstr.erase(pos, word.length() + 1);
					IsExisted = true;
					break;
				}
			}
			word = "";
			if (!IsExisted)
			{
				pos = i + 1;
			}
			else
			{
				i -= word.length() + 1;
			}
		}
		else if (tmpstr[i] == '\0') // end of string
		{
			for (int i = 0;i < 174;++i)
			{
				if (word == arr[i])
				{
					// Filter stopword - erase word
					tmpstr.erase(pos, word.length());
					break;
				}
			}
		}
		else
		{
			word += tmpstr[i];
		}
	}

	search_string = tmpstr;
	delete[]arr;
}

vector<pair<string, int>> QueryHandling::OR(string search_string)
{
	vector<pair<string, int>> tmp;
	int pos = 0;
	int num = 0;
	for (int i = 0;i < search_string.length();++i)
	{
		if (search_string[pos] == ' ')
		{
			pos++;
			continue;
		}
		if (search_string[i] == ' ')
		{
			if (search_string[pos] == 'O' && search_string[pos + 1] == 'R' && i - pos == 2)
			{
				pos = i + 1;
				continue;
			}
			else
			{
				num++;
				tmp.push_back(make_pair(search_string.substr(pos, i - pos), num));
				pos = i + 1;
			}
		}
		if (search_string[i + 1] == '\0')
		{
			num++;
			tmp.push_back(make_pair(search_string.substr(pos, i - pos + 1), num));
		}
	}
	return tmp;
}

string QueryHandling::intitle(string search_string)
{
	for (int i = 0;i < search_string.length() - 8;++i)
	{
		if (search_string.substr(i, 8) == "intitle:" && (search_string[i + 8] != '\0' && search_string[i + 8] != ' ') && (i == 0 || (i > 0 && search_string[i - 1] == ' ')))
		{
			int pos = 0; // end position of intitle
			for (int j = i + 9; j <= search_string.length();++j)
			{
				if (search_string[j] == '\0' || search_string[j] == ' ')
				{
					pos = j;
					break;
				}
			}
			if (i == 0)
			{
				if (search_string[pos] == '\0')
				{
					search_string.erase(i, pos);
				}
				else if (search_string[pos] == ' ')
				{
					search_string.erase(i, pos + 1);
				}
			}
			else
			{
				search_string.erase(i - 1, pos - i + 1);
			}
			i--;
		}
		if (i >= search_string.length())
			break;
	}
	return search_string;
}

string QueryHandling::exclude(string search_string) // redo
{
	for (int i = 0;i < search_string.length() - 1;++i)
	{
		if (search_string[i] == '-' && search_string[i + 1] == ' ' && search_string[i - 1] == ' ')
		{
			return search_string.substr(0, i - 1);
		}
	}
	return search_string;
}

string QueryHandling::price()
{

}
#endif
