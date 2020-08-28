#ifndef __QUERY_HANDLING__
#define __QUERY_HANDLING__

#include "trie.h"

class QueryHandling {
public:
	void filter(string& search_string);
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

#endif
