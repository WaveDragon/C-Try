#include <iostream>
#include <vector>
#include <string>
using namespace std;
// 13.5 给定的类框架,编写拷贝构造函数，和拷贝构造运算符

class HasPtr
{
public:
    //构造函数
    HasPtr(const string &s = string()) : ps(new string(s)), i(0) {}
    //拷贝构造函数
    HasPtr(const HasPtr &rhs) 
    {
        ps = new string(*rhs.ps);
        i = rhs.i;
    }
    // 拷贝赋值运算符

    HasPtr& operator= (const HasPtr &rhs)
    {
        auto newps = new string(*rhs.ps);//拷贝指针指向的对象
        delete ps;//销毁原来的string
        ps = newps;
        i = rhs.i;
        return *this;
    }
    //析构函数
    ~HasPtr(){delete ps;}

private:
    string *ps;
    int i;
};

int main()
{

    return 0;
}