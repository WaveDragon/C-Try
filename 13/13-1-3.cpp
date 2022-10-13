#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct X
{
    X() { cout << "构造函数X()" << endl; }
    X(const X &)
    {
        cout << "拷贝构造函数X(const X &)" << endl;
    }
    X &operator=(const X &rhs)
    {
        cout << "拷贝赋值运算符=" << endl;
        return *this;
    }
    ~X()
    {
        cout << "析构函数~X()" << endl;
    }
};

void fi(X x)
{
}

void f2(X &x)
{

}

int main()
{
    cout << "局部变量" << endl;
    X x;
    cout << endl;

    cout << "非引用参数传递" << endl;
    fi(x);
    cout << endl;

    cout << "引用参数传递" << endl;
    f2(x);
    cout << endl;

    cout << "动态分配" << endl;
    auto *px = new X;
    cout << endl;

    cout << "添加到容器中" << endl;
    vector<X> vx;
    vx.push_back(x);
    cout << endl;

    cout << "释放动态分配内存" << endl;
    delete px;
    cout << endl;

    cout << "间接初始化和 赋值" << endl;
    X y = x;
    y = x;
    cout << endl;
    return 0;
}