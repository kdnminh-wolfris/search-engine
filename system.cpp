#include "system.h"

std::string get_link(std::string folder, std::string filename)
{
	return "data/" + folder + "/" + filename + ".txt";
}