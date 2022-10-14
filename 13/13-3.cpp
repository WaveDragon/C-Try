//定义自己使用的引用计数版本HasPtr
#include <iostream>
#include <string>
using namespace std;

class HasPtr
{
private:
    string *ps;
    int i;
    size_t *use;

public:
    friend void swap(HasPtr&,HasPtr&);
    //构造函数分配新的string和新的计数器，将计数器置为1
    HasPtr(const string &s = string()) : ps(new string(s)), i(0), use(new size_t(1)) {}
    //拷贝构造函数拷贝三个数据成员，并递增计数器
    //拷贝的是指针
    HasPtr(const HasPtr &p) : ps(p.ps), i(p.i), use(p.use) { ++*use; }
    HasPtr &operator=(const HasPtr &); //拷贝赋值运算符
    HasPtr &operator=(const string &);
    string &operator*();
    ~HasPtr();
};
HasPtr::~HasPtr()
{
    if (--*use == 0)
    {               // if the reference count goes to 0
        delete ps;  // delete the string
        delete use; // and the counter
    }
}


HasPtr &HasPtr::operator=(const HasPtr &rhs)
{
    ++*rhs.use; // increment the use count of the right-hand operand
    if (--*use == 0)
    {               // then decrement this object's counter
        delete ps;  // if no other users
        delete use; // free this object's allocated members
    }
    ps = rhs.ps; // copy data from rhs into this object
    i = rhs.i;
    use = rhs.use;
    return *this; // return this object
}

HasPtr f(HasPtr hp) // HasPtr passed by value, so it is copied
{
    HasPtr ret;
    ret = hp; // assignment copies the given HasPtr
    // proces ret
    return ret; // ret and hp are destroyed
}
HasPtr &
HasPtr::operator=(const string &s)
{
    *ps = s;
    return *this;
}

string &HasPtr::operator*()
{
    return *ps;
}

inline
void swap(HasPtr& lhs,HasPtr& rhs)
{
    cout <<" 交换" << endl;
    swap(lhs.ps,rhs.ps);
    swap(lhs.i,rhs.i);
}

int main()
{
    HasPtr h1("Hello World");
    HasPtr h2(h1);
    HasPtr h3("mom");
    cout << *h1 << "\n" << *h2<< *h3<< endl;
    h1 = "Hello";
    swap(h1,h3);
    cout << *h1 << "\n" << *h2<< *h3<< endl;
    return 0;
}