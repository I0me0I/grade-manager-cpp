#include<iostream>
#include<vector>
#include<limits>
#include<climits>
#include<fstream>

using std::string;
using std::vector;
using std::ifstream;
using std::ofstream;

const int STR_LEN = 20;

inline void clearInput()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool SetString(const char *name, char *str, int n);

bool SetInt(const char *name, int &val, int min=0, int max=INT_MAX);

bool SetSex(bool &sex);