#include<iostream>
#include<fstream>
#include<map>
#include<string>
#include<algorithm>

using namespace std;

int main(int argc,char *argv[])
{
    ifstream in(argv[1]);
    if (!in)
    {
        cout << "打开文件失败！"<< endl;
        exit(1);
    }
    map<string,size_t> word_count;
    string word;
    while (in >> word)
    {
        ++word_count[word];
    }
    for (auto &w : word_count)
    {
        cout<<w.first << " " << w.second << endl;
    }
    
    return 0;
}