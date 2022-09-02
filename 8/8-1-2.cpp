#include<iostream>
#include<string>
#include<vector>
using namespace std;

istream& Ioexercise (istream& is)
{
    int v;
    while (is >> v ,!is.eof())
    {
        if (is.bad())
        {
            throw runtime_error("IO error");

        }
        if (is.fail())
        {
            cerr<< "数据错误，请重试" << endl;
            is.clear();
            is.ignore(100,'\n');
            continue;
        }
        cout << v <<endl;
    }
    is.clear();
    return is;
}

int main()
{
    cout<<"请输入整数:" <<endl;
    Ioexercise(cin);


    return 0;
}