#include <fstream>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

string ascender = "fbdhIklti";
string descender = "gjpqy";
string cender = ascender + descender;
void Thelonggest(string &str)
{

    string ::size_type pos = 0;
    vector<int> poses;
    while ((pos = str.find_first_of(cender, pos)) != string::npos)
    {
        poses.push_back(pos);
        ++pos;
    }
    vector<int> index;
    for (auto i = poses.begin(); i < poses.end() - 1; i++)
    {
        index.push_back(*(i + 1) - *i);
    }

    int a = 0;
}

void find_longest_word(ifstream &in)
{
    string s, longest_word;
    int max_length = 0;
    while (in >> s)
    {
        if (s.find_first_of(cender) != string::npos)
        {
            continue;
        }
        cout << s << endl;
        if (max_length < s.size())
        {
            max_length = s.size();
            longest_word = s;
        }
    }
    cout << longest_word << endl;
}

int main()
{
    ifstream in("data.txt");
    if (!in)
    {
        cerr << "Can not open the file! " << endl;
        return -1;
    }
    // find_longest_word(in);
    string line;
    string words;
    while (getline(in, line))
    // while (in >> line)
    {
        words.append(line);
    }

    in.close();
    // Thelonggest(words);

    return 0;
}