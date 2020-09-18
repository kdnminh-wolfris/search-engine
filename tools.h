#ifndef TOOLS
#define TOOLS

#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <iomanip>
#include <map>
#include <vector>
#include "option.h"

using namespace std;

void numtag(int num);
void month_in_text(int num);
bool valid_date(int year, int month, int day);
string AcademicYearCode(int academic_year);
string SemesterCode(int semester);
string weekdayCode(int day);

void preview(string filename, int char_lim = 700);
void fullview(string filename);

vector <pair <string, int>> to_vector(map <string, int> MAP);

#endif
