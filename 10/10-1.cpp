#include <vector>
#include <string>
#include<algorithm>
#include<list>
#include<iostream>

using namespace std;

int main()
{
    cout << "输入整数：" << endl;
    int i;
    vector<int> vint;
    while (cin >> i)
    {
        vint.push_back(i);
        if (!i)
        {
            break;
        }
        
    }
    int num = count(vint.begin(),vint.end(),2);
    cout << num << endl;


    cout << "输入string：" << endl;
    string str;
    list<string> lstr;
    while (cin >> str)
    {
        lstr.push_back(str);
    }
    int strnum = count(lstr.begin(),lstr.end(),"2");
    cout << strnum << endl;

    return 0;
}