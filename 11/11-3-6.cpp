// #include <string>
// #include <iostream>
// #include <fstream>
// #include <sstream>
// #include <list>
// #include <algorithm>
// #include <iterator>
// #include <vector>
// #include <map>
// #include <set>

#include "INCL.H"
using namespace std;

map<string,string> buildmap(ifstream& map_rules)
{
    map<string,string> rules;
    string keys;
    string value;
    while (map_rules >> keys && getline(map_rules,value))
    {
        if(value.size() > 0)
        {
            rules[keys] = value.substr(1);
        }
        else
        {
            cout << "无转换规则"<< keys;
        }
    }
    return rules;
}

string& transform(string &word,map<string,string> &rules)
{
    auto map_it = rules.find(word);
    if (map_it == rules.end())
    {
        return word;
    }
    else
    {
        return (*map_it).second;
    }
    

}


void word_transform(ifstream &map_rules,ifstream& input)
{
    auto trans_map = buildmap(map_rules);
    string line;
    while (getline(input,line))
    {
        istringstream in(line);
        string word;
        while (in >> word)
        {
            cout << transform(word,trans_map)<< " ";
        }
        cout << endl;
    }
    
}






int main(int argc , char* argv[])
{
    // ifstream in(argv[1]);
    // if (! in)
    // {
    //     cout<< "不能打开文件！"<<endl;
    //     exit(1);
    // }
    ifstream input(argv[1]);
    ifstream rules(argv[2]);
    word_transform(rules,input);


    return 0;
}