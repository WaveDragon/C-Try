#include <iostream>
#include <string>
using namespace std;

//练习让类的行为 像一个值

class HasPtr
{
private:
    string *ps;
    int i;

public:
    HasPtr(const string &s = string()) : ps(new string(s)), i(0) {}
    HasPtr(const HasPtr& P):
    ps(new string(*P.ps)),i(P.i){} // 拷贝构造函数

    HasPtr& operator= (const HasPtr&);//拷贝赋值运算符
    HasPtr& operator= (const string&);//赋予新string
    string& operator* (); //解引用
    ~HasPtr();
};

HasPtr& HasPtr::operator=(const HasPtr& rhs)
{
    auto newps = new string(*rhs.ps);//拷贝指针指向的对象
    delete ps;
    ps = newps;
    i = rhs.i;
    return *this;
}
HasPtr& HasPtr::operator=(const string& s)
{
    *ps = s;
    return *this;
}
string& HasPtr::operator*()
{
    return *ps;
}

HasPtr::~HasPtr()
{
    delete ps;
}

int main()
{
    HasPtr h("Hello world");//构造函数
    HasPtr h1(h);//拷贝构造
    HasPtr h2 = h;//拷贝赋值运算符
    string s1 = "Hello 0";//
    HasPtr h3 = s1;
    h2 = "Hello world1";//赋予新的string
    cout << *h1 <<" " << *h2 << " " << *h3<<endl;
    return 0;
}
