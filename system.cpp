#include "system.h"

std::string get_link(std::string folder, std::string filename)
{
	return "save\\" + folder + "\\" + filename + ".txt";
}