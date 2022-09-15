#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
bool isShorter(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}

void elimdups(vector<string> &words)
{
    stable_sort(words.begin(), words.end(), isShorter);
    auto end_unique = unique(words.begin(), words.end());
    words.erase(end_unique, words.end());
    for (auto i = words.begin(); i < words.end(); i++)
    {
        cout << *i << " ";
    }
}

bool bigFive(const string &s1)
{
    if (s1.size() < 5)
    {
        return false;
    }
    else
        return true;
}

int main()
{
    vector<int> vint;
    fill_n(back_inserter(vint), 10, 0);

    string word;
    vector<string> words;
    while (cin >> word)
    {
        words.push_back(word);
    }
    auto a = partition(words.begin(), words.end(), bigFive);
    for (auto i = words.begin(); i < a; i++)
    {
        cout << *i << endl;
    }
    
    return 0;
}