#include "INCL.H"
#include"my_StrBolb.H"
using namespace std;

int main()
{
    unique_ptr<string> p1(new string("Hello world"));
    // unique_ptr<string> p2(p1);
    // unique_ptr<string> p3;
    // p3 = p1;
    //程序调用了删除的函数，原因是标准库为了禁止unique_ptr的拷贝和赋值，将其拷贝构造函数和赋值函数声明了delete；
    
    return 0;
}