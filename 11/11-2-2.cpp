#include <map>
#include <list>
#include <iostream>
#include <fstream>
#include <set>
#include <sstream>
using namespace std;
string &trans(string &s1)
{

    for (int i = 0; i < s1.size(); i++)
    {
        if (s1[i] >= 'A' && s1[i] <= 'Z')
        {
            s1[i] = s1[i] + ('a' - 'A');
        }
        else if (s1[i] == ',' || s1[i] == '.')
        {
            s1.erase(i, 1);
        }
    }
    return s1;
}

int main(int argc, char *argv[])
{
    ifstream in(argv[1]);
    if (!in)
    {
        cout << "打开文件失败" << endl;
        exit(1);
    }

    map<string, list<int>> word_lineno;
    string line;
    string word;
    int line_index = 0;
    while (getline(in, line))
    {
        line_index++;
        istringstream strin(line);
        while (strin >> word)
        {
            trans(word);
            word_lineno[word].push_back(line_index);
        }
    }
    for (auto &i : word_lineno)
    {
        cout << i.first << " ";
        for (auto j = i.second.begin(); j != i.second.end(); j++)
        {
            cout << *j << " ";
        }
        cout << endl;
    }

    return 0;
}