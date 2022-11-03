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
    virtual double net_price(size_t n) const
    {
        return n * price;
    }
    virtual void debug()
    {
        cout << "bookNo=" << bookNo << " price=" << price << endl;
    }

    virtual ~Quote()
    {
        cout << "运行析构函数" << endl;
    }
    friend ostream &operator<<(ostream &, Quote &);
};

ostream &operator<<(ostream &os, Quote &e)
{
    os << "使用operator<<(ostream& ,Quote&)" << endl;
    return os;
};
class Bulk_quote : public Quote
{
private:
    size_t min_qty;
    double discount;
public:
    Bulk_quote(const string &book = " ",double sale_price = 0.0,
    size_t qty = 0,double disc = 0.0):
    Quote(book,sale_price),min_qty(qty),discount(disc)
    {
        cout <<"使用Bulk_quote版本构造函数"<< endl;
    }
    double net_price(size_t cnt) const
    {
        if (cnt > min_qty)
        {
            return cnt*(1-discount)*price;
        }
        else
            return cnt*price;
        
    }
    void debug() 
    {
        cout << "bookNo=" << Quote::isbn() << " price=" << price << endl;
        cout<< "最小数量"<< min_qty<<" 折扣为："<< discount<<endl;
    }
    ~Bulk_quote()
    {
        cout <<"运行Bulk_quote析构函数" <<endl;
    }
};
ostream &operator<<(ostream &os,Bulk_quote& bq)
{
    os<<"使用<<(ostream&,Bulk_quote&)" << endl;
    return os;
}

int main()
{
    Quote base("C++Prime",129.0);
    Bulk_quote bulk("Hello Python",89,5,0.1);
    cout <<base <<endl;
    cout <<bulk<<endl;
    bulk.debug();
    cout << bulk.net_price(10) <<endl;
    bulk.debug();
    return 0;
}
