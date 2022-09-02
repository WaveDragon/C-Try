#include<iostream>
#include<string>
using namespace std;

int main(int argc, char **argv)// argv 为 终端中 输入的 信息： 6-25 for study 则argv 中就是 for 和 study
{
    string str;
    for (int i = 0; i != argc; i++)
    {
        str += argv[i];

    }
    cout << str << endl;

    return 0;
}