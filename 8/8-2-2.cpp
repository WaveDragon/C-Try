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
    // ofstream out(argv[2]);//out隐式设置为输出和截断，即原文件内容会被清空
    //等价于 ofstream out; 
    // out open(argv[2]);

    ofstream out(argv[2],ofstream::app);//改为追加模式，即源文件内容不会清空；
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
        out<< *i << " "<<endl;
        cout << *i<<" ";
    }
    out.close();//似乎不加 不重新编译 out 不会刷新；并不是，只要保存 输入文件就会刷新


    return 0;
}
