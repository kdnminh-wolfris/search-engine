#include "query_handling.h"

void QueryHandling::ToLower(string& word)
{
	for (int i = 0;i < word.length();++i)
	{
		if (word[i] >= 'A' && word[i] <= 'Z')
			word[i] += 32;
	}
}

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
			++i;
		}
	}
	LoadStopWord.close();

	// Compare each word in search_string to stop-words and erase it from string
	string word = "";
	string tmpstr = search_string;
	int pos = 0; // first position of each word
	for (int i = 0;i <= tmpstr.length();++i)
	{
		if (tmpstr[i] == ' ')
		{
			if (word == "AND" || word == "OR")
			{
				word = "";
				continue;
			}
			ToLower(word);
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
			if (!IsExisted)
			{
				pos = i + 1;
			}
			else
			{
				i -= word.length() + 1;
			}
			word = "";
		}
		else if (tmpstr[i] == '\0') // end of string
		{
			if (word == "AND" || word == "OR")
			{
				word = "";
				continue;
			}
			ToLower(word);
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

vector<vector<string>> QueryHandling::OR(string& search_string)
{
	vector<vector<string>> tmp;
	vector<string> arr;
	int pos = 0;
	bool IsOrigin = true;
	string origin;
	for (int i = 0;i < search_string.length();++i)
	{
		if (search_string[i] == ' ')
		{
			arr.push_back(search_string.substr(pos, i - pos));
			pos = i + 1;
		}
		if (search_string[i + 1] == '\0')
			arr.push_back(search_string.substr(pos, i - pos + 1));
		if (i + 4 < search_string.length() && search_string.substr(i, 4) == " OR ")
		{
			if (IsOrigin == true)
			{
				while (!arr.empty())
				{
					origin += arr.front();
					arr.erase(arr.begin());
				}
				IsOrigin = false;
			}
			else
			{
				tmp.push_back(arr);
				while (!arr.empty())
					arr.pop_back();
			}
			pos = i + 4;
			i = i + 3;
		}
	}
	tmp.push_back(arr);
	search_string = origin;
	return tmp;
}

string QueryHandling::intitle(string& search_string)
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
			string tmp = search_string.substr(i + 8, pos - i - 8);
			if (i == 0 && search_string[pos] == '\0')
				search_string.erase(i, pos - i);
			else if (i == 0 && search_string[pos] == ' ')
				search_string.erase(i, pos - i + 1);
			else if (i != 0 && search_string[pos] == '\0')
				search_string.erase(i - 1, pos - i + 1);
			else if (i != 0 && search_string[pos] == ' ')
				search_string.erase(i, pos - i + 1);
			return tmp;
		}
	}
	return "";
}

string QueryHandling::exclude(string& search_string)
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
			string tmp = search_string.substr(i + 1, pos - i - 1);
			if (i == 0 && search_string[pos] == '\0')
				search_string.erase(i, pos - i);
			else if (i == 0 && search_string[pos] == ' ')
				search_string.erase(i, pos - i + 1);
			else if (i != 0 && search_string[pos] == '\0')
				search_string.erase(i - 1, pos - i + 1);
			else if (i != 0 && search_string[pos] == ' ')
				search_string.erase(i, pos - i + 1);
			return tmp;
		}
	}
	return "";
}

string QueryHandling::price(string& search_string)
{
	for (int i = 0;i < search_string.length();++i)
	{
		if (search_string[i] == '$' && search_string[i + 1] != '\0' && (search_string[i + 1] >= 48 && search_string[i + 1] <= 57) && (i == 0 || (i > 0 && search_string[i - 1] == ' ')))
		{
			int pos = 0;
			for (int j = i + 1;j < search_string.length();++j)
			{
				if (search_string[j] == '\0' || search_string[j] == ' ')
				{
					pos = j;
					break;
				}
			}
			string tmp = search_string.substr(i + 1, pos - i - 1);
			if (i == 0 && search_string[pos] == '\0')
				search_string.erase(i, pos - i);
			else if (i == 0 && search_string[pos] == ' ')
				search_string.erase(i, pos - i + 1);
			else if (i != 0 && search_string[pos] == '\0')
				search_string.erase(i - 1, pos - i + 1);
			else if (i != 0 && search_string[pos] == ' ')
				search_string.erase(i, pos - i + 1);
			return tmp;
		}
	}
	return "";
}