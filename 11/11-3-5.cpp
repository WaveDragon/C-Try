#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include <algorithm>
#include <iterator>
#include <vector>
#include <map>
#include <set>
using namespace std;


int main()
{
    map<string, vector<int>> map_one;
    auto one = map_one.find("h");
    multimap<string, string> books;
    string line;
    string word;
    vector<string> words;
    books.insert({"Hello","world"});
    books.insert({"Abe","Heool"});
    books.insert({"Abe","AHeool"});
    for (auto i = books.begin(); i != books.end(); i++)
    {
        cout << (*i).first <<" "<<(*i).second;
    }
    
    

    return 0;
}