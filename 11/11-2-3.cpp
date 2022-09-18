#include <string>
#include <utility>
#include <list>
#include <iostream>
#include <vector>
using namespace std;

void readpair(list<string> lstr, list<int> lint)
{
}

int main()
{
    pair<string, int> p1;
    vector<decltype(p1)> vpair;
    int v;
    string s;
    while (cin >> s && cin >> v)
    {
        vpair.push_back(make_pair(s, v));
    }

    return 0;
}