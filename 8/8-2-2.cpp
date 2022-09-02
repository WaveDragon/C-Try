#include <string>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
//在终端中输入 8-2-2 data.txt out.txt 会把文件中内容输出到out.txt
int main(int argc, char *argv[])//在终端中输入 8-2-2 data.txt 会把文件中内容输出
{
    if (argc != 3)
    {
        cout << "输入文件名！" << endl;
        return -1;
    }
    ifstream in(argv[1]);
    if (!in)
    {
        cerr << "Can not open the file! " << endl;
        return -1;
    }
    ofstream out(argv[2]);
    if (!out)
    {
        cerr << "Please enter out file name!  :( " << endl;
        return -1;
    }
    


    vector<string> words;
    string lines;
    while (getline(in, lines))
    {
        words.push_back(lines);
    }
    in.close();

    for (auto i = words.begin(); i != words.end(); i++)
    {
        out<< *i << " ";
    }



    return 0;
}
