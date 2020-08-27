#ifndef __SEARCH__
#define __SEARCH__

#include <vector>
#include <map>
#include <string>

using namespace std;

class first {
private:
	map<string, bool>* container;
	int gate = 0;
	//GATE FOR CHECKING IF IT'S READY FOR 2ND PHASE

	void intersection(vector<string> f1, vector<string> f2)
	{
		return;
	}
public:
	//SS STAND FOR SEARCH_STRING
	void intitle(string ss)
	{
		this->gate++;
		return;
	}

	void quote(vector<pair<string, int>> quotes)
	{
		this->gate++;
		return;
	}

	void origin(vector<pair<string, int>> origins)
	{
		this->gate++;
		return;
	}

	void findOr (vector<pair<string, int>> OR)
	{
		this->gate++;
		return;
	}

	void exclude(string ss)
	{
		this->gate++;
		return;
	}
};

#endif
