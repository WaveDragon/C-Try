#include <string>
#include <deque>
#include <iostream>
#include <list>
#include <vector>
using namespace std;

int main()
{
    string word;
    deque<string> sentcens;
    list<string> liststrings;
    while (cin >> word)
    {
        sentcens.push_back(word);
        liststrings.push_back(word);
    }
    for (auto i = sentcens.begin(); i != sentcens.end(); i++)
    {
        cout << *i << " ";
    }

    for (auto i = liststrings.begin(); i != liststrings.end(); i++)
    {
        cout << *i << " ";
    }

    list<int> lint = {1, 31, 3, 6, 9, 4};
    deque<int> odd;
    deque<int> even;

    for (auto i = lint.begin(); i != lint.end(); i++)
    {
        if (*i % 2 == 0)
        {
            even.push_back(*i);
        }
        else
        {
            odd.push_back(*i);
        }
    }
    auto &a = *lint.begin();
    vector<int> testa;
    // cout<< testa[0]<<testa.front()<<*testa.begin();
    
    
    return 0;
}