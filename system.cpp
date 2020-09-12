#include "system.h"

int get_index(char key)
{
	if ('0' <= key && key <= '9')
		return key - '0';
	if ('a' <= key && key <= 'z')
		return key - 'a' + 10;
	if ('A' <= key && key <= 'Z')
		return key - 'A' + 10;
	if (key == '$')
		return 35;
	if (key == '#')
		return 36;
	return -1;
}

int string_to_int(string str)
{
	int ans = 0;
	for (int i = 0; i < str.length(); ++i)
		ans = ans * 10 + (str[i] - '0');
	return ans;
}


std::string get_link(std::string folder, std::string filename)
{
	return "save\\" + folder + "\\" + filename + ".txt";
}