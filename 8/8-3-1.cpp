#include<string>
#include<vector>
#include<iostream>
#include<sstream>
#include<fstream>
using namespace std;


istream& Ioexercise (istream& is)
{
    string v;
    // while (is >> v ,!is.eof())
    while (is >> v )
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

// ifstream in("data.txt");

int main()
{

    
    cout<<"请输入整数:" <<endl;
    
    string line = "For study";
    // getline(cin,line);
    istringstream recorddd(line);//getline 后面自带 停止符？  确实是，更改while条件后能输出；

    ostringstream mesage;
    mesage << "Hello world " << endl;// 遇到空格 就会停止，相当于两个string 输入到message 
    istringstream in(mesage.str());
    Ioexercise(recorddd);
    Ioexercise(in);

    //8-10部分
    ifstream fin("test.txt");

    if (!fin)
    {
        cerr << "Can not open the file! " << endl;
        return -1;
    }
    vector<string> stringrecord;
    while (getline(fin,line))
    {
        stringrecord.push_back(line);
    }
    fin.close();

    cout<< "IOexercise output"<<endl;
    for (auto i = stringrecord.begin(); i != stringrecord.end(); i++)
    {
        istringstream readline(*i);//换行符 就算做in.eof()
        Ioexercise(readline);

    }

    cout<< "readline >> word output"<<endl;

    istringstream readline1;
    for (auto i = stringrecord.begin(); i != stringrecord.end(); i++)
    {
        istringstream readline(*i);//如果定义到循环外
        readline1.clear();//重复使用的话，得clear
        readline1.str(*i);//讲*i绑定到readline1
        string word;

        while (readline >> word)
        {
            cout << word<< " ";
        }
        cout << endl;

    }
    



    return 0;
}
