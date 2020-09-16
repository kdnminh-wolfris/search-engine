#ifndef __QUERY_HANDLING__
#define __QUERY_HANDLING__

#include "trie.h"
pair<string, string> range(string extract_string)
{
	string first, second, tmp;
	pair<string, string> result;
	stringstream ss;
	ss << extract_string;
	bool flag = false;
	while (ss >> tmp)
	{
		for (int i = 0; i < tmp.length(); i++)
		{
			if (tmp[i] == '.' && tmp[i + 1] == '.' && tmp[i + 2] != '.')
			{
				flag = true;
				for (int j = 0; j < i; j++)
				{
					first.push_back(tmp[j]);
				}
				for (int j = i + 2; j < tmp.length(); j++)
				{
					second.push_back(tmp[j]);
				}
			}
		}
		if (flag == true)
			return result = make_pair(first, second);
	}
	return result = make_pair("-1", "-1");
}

vector<string> quotes(string extract_string)
{
	string first, second, tmp;
	vector<string> result;
	stringstream ss;
	bool flag = false;
	for (int i = 0; i < extract_string.length(); i++)
	{
		if (extract_string[i] == '"')
		{
			for (int j = i + 1; j < extract_string.length(); j++)
			{
				if (extract_string[j] == '"')
				{
					flag = true;
					for (int k = i + 1; k < j; k++)
					{
						tmp.push_back(extract_string[k]);
					}
				}
			}

		}
	}
	ss << tmp;
	tmp.erase();
	while (ss >> tmp)
	{
		result.push_back(tmp);
	}
	if (flag != true)
		result.push_back("-1");
	return result;
}


#endif
