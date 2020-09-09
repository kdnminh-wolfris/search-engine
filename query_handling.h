#ifndef __QUERY_HANDLING__
#define __QUERY_HANDLING__

#include "trie.h"

class QueryHandling {
public:
	void filter(string& search_string);
	vector<pair<string, int>> OR(string search_string);
	string intitle(string search_string);
	string exclude(string search_string);
	string price(string search_string);
};


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
			return search_string.substr(i + 8, pos - i - 8);
		}
	}
	return "";
}

string QueryHandling::exclude(string search_string)
{
	for (int i = 0;i < search_string.length() - 1;++i)
	{
		if (search_string[i] == '-' && (search_string[i + 1] != '\0' && search_string[i + 1] != ' ') && (i == 0 || (i > 0 && search_string[i - 1] == ' ')))
		{
			int pos = 0; // end position of excluded word
			for (int j = i + 2; j <= search_string.length();++j)
			{
				if (search_string[j] == '\0' || search_string[j] == ' ')
				{
					pos = j;
					break;
				}
			}
			return search_string.substr(i + 1, pos - i - 1);
		}
	}
	return "";
}

string QueryHandling::price(string search_string)
{
	for (int i = 0;i < search_string.length();++i)
	{
		if (search_string[i] == '$' && search_string[i + 1] != '\0' && (search_string[i + 1] >= 48 && search_string[i + 1] <= 57) && (i == 0 || (i > 0 && search_string[i - 1] == ' ')))
		{
			int pos = 0;
			for (int j = i + 1;j < search_string.length();++j)
			{
				if (!(search_string[j] >= 48 && search_string[j] <= 57))
				{
					pos = j;
					break;
				}
			}
			return search_string.substr(i + 1, pos - i - 1);
		}
	}
	return "";
}
#endif
