#include <map>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

void add_family(map<string, vector<string>> &families, const string &family)
{
    if (families.find(family) == families.end())
    {
        families[family] == vector<string>();
    }
}

void add_child(map<string, vector<string>> &families, const string &family,
               const string &child)
{
    families[family].push_back(child);
}

int main()
{

    map<string, vector<string>> families;

    add_child(families,"Liu","Zhaoyang");

    return 0;
}