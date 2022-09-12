#include <string>
#include <vector>
#include <iostream>
using namespace std;

void Tihuan(string &s, string &oldVal, string &newVal)
{
    auto len_old = oldVal.size();
    for (auto i = s.begin(); i < s.end() - len_old + 1; i++)
    {
        if (*i == oldVal[0])
        {
            string temp = {};
            temp.append(i, i + len_old);
            if (temp == oldVal)
            {
                s.erase(i, i + len_old);
                s.insert(i, newVal.begin(), newVal.end());
            }
        }
    }

    cout << s << endl;
}

void Tihuan2(string &s, string &oldVal, string &newVal)
{
    auto len_old = oldVal.size();
    int index = 0;
    for (auto i = s.begin(); i < s.end() - len_old + 1; i++, index++)
    {
        if (*i == oldVal[0])
        {
            string temp = {};
            temp.append(i, i + len_old);
            if (temp == oldVal)
            {
                // s.replace(i,i+len_old,newVal);//repalce(迭代器)
                s.replace(index, len_old, newVal); // repalce(下标，长度，新的值)
                cout << index << endl;
            }
        }
    }

    cout << s << endl;
}

void Tihuanfind(string &s, string &oldVal, string &newVal)
{
    auto len_old = oldVal.size();
    int index = 1;
    // if (index = s.find(oldVal))
    // {
    //     s.replace(index, len_old, newVal);
    //     cout << index << endl;
    // }
    while (index > 0)
    {
        index = s.find(oldVal);
        if (index > 0)
        {
            cout << index << endl;
            s.replace(index, len_old, newVal);
        }
    }

    cout << s << endl;
}

// 9-45
void MrsName(string &name, const string& pre, const string& last)
{
    string newname;
    name.insert(name.begin(), pre.begin(), pre.end());
    name.append(last);
    name.insert(0,pre);
    auto len = name.size();
    name.insert(len,last);

}

int main()
{
    string s1 = "World hello helloyour time,hell eee helol wowoffdd hello", s2 = "hello", s3 = "YOOOO";
    // Tihuan(s1, s2, s3);
    // Tihuan2(s1, s2, s3);
    // Tihuanfind(s1, s2, s3);
    string name = "Jaames";
    MrsName(name,"Mr","Jr.");
    return 0;
}
