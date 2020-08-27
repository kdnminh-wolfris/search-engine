#ifndef __QUERY_HANDLING__
#define __QUERY_HANDLING__

#include "trie.h"

void QueryHandling::filter(string& search_string)
{
	string substring;
	ifstream LoadStopWord;
	string* arr;
	LoadStopWord.open("stopword.txt");
	if (!LoadStopWord.is_open())
	{
		cout << "File is not existed." << endl;
	}
	else
	{
		// Create an array of stopwords' string
		arr = new string[174];
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
			bool IsSubStr = false;
			for (int i = 0;i < 174;++i)
			{
				if (word == arr[i])
				{
					tmpstr.erase(pos, word.length() + 1);
					IsSubStr = true;
					break;
				}
			}
			word = "";
			if (!IsSubStr)
			{
				pos = i + 1;
			}
			else
			{
				i -= word.length() + 1;
			}
		}
		else
		{
			word += search_string[i];
		}
	}

	search_string = tmpstr;
	delete[]arr;
}

#endif
