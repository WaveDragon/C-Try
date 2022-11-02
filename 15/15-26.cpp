#include <iostream>
#include <string>
#include <ostream>
using namespace std;

class Quote
{

private:
    string bookNo;

protected:
    double price;

public:
    Quote() = default;
    Quote(const string &book = " ", double sales_price = 0.0) : bookNo(book), price(sales_price)
    {
        cout << "Quote 构造函数运行" << endl;
    }
    string isbn() const
    {
        return bookNo;
    }
    //返回给定数量的书籍的销售总额，派生类改写使用不同的折扣计算方法
    virtual
    ~Quote();
};

Quote::~Quote()
{
}
