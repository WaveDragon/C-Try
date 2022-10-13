#include <iostream>
#include <string>
using namespace std;

class Employee
{
private:
    static int sn;

public:
    Employee() { mysn = sn++; };
    Employee(const string &s)
    {
        name = s;
        mysn = sn++;
    }
    //拷贝构造函数和拷贝赋值运算符
    Employee(Employee &e)
    {
        name = e.name;
        mysn = sn++;
    }
    Employee &operator=(Employee &rhs)
    {
        name = rhs.name;
        return *this;
    }
    ~Employee(){};
    const string &get_name() { return name; }
    int get_mysn() { return mysn; }

private:
    string name;
    int mysn;
};
void f(Employee& e)
{
    cout << e.get_mysn() << " " << e.get_name() << endl;
}
int Employee::sn = 0;
int main()
{
    Employee a ("zhaolin");
    Employee b = a;
    Employee c;
    f(a);f(b);f(c);
    return 0;
}