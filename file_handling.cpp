#include"file_handling.h"

bool isStopWord(string cmpstr, string* stopword)
{
	for (int i = 0; i < 174; i++)
	{
		if (cmpstr == stopword[i])
			return true;
	}
	return false;
}

void filterPunctation(string& str)
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

void importfileExe(vector<pair<string, int>>& result, string& cmpstr, string* arr)
{
	stringstream ss;
	ss << cmpstr;
	cmpstr = "";

	while (!ss.eof())
	{
		ss >> cmpstr;

		cmpstr.erase(remove_if(cmpstr.begin(), cmpstr.end(), ispunct), cmpstr.end());

		if (!isStopWord(cmpstr, arr) && !cmpstr.empty())
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

vector <pair <string, int>> import_file(string filename)
{
	ifstream fin;
	vector<pair<string, int>> result;
	fin.open(filename);
	if (!fin.is_open())
		cout << "Open file error" << endl;
	else
	{
		string* arr = new string[174];
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

		string temp;
		while (!fin.eof())
		{
			getline(fin, temp, '\n');
			importfileExe(result, temp, arr);
		}
		fin.close();
	}
	return result;
}