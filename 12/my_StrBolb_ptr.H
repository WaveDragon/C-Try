#ifndef MY_STRBLOB_H
#define MY_STRBLOB_H
#include <vector>
#include <string>
#include <initializer_list>
#include <memory>
#include <stdexcept>
using namespace std;

class StrBlobPtr;
class StrBlob
{
    friend class StrBlobPtr;

public:
    typedef vector<string>::size_type size_type;
    StrBlob();
    StrBlob(initializer_list<string> il);

    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    // 添加和删除元素
    void push_back(const string &t) { data->push_back(t); }
    void pop_back();
    // 元素访问
    string &front();
    const string &front() const;
    string &back();
    const string &back() const;

    //提供给StrBlobPtr的接口
    StrBlobPtr begin();
    StrBlobPtr end();

private:
    shared_ptr<vector<string>> data;
    void check(size_type i, const string &msg) const;
};

StrBlob::StrBlob() : data(make_shared<vector<string>>()) {}
StrBlob::StrBlob(initializer_list<string> il) : data(make_shared<vector<string>>(il)) {}

void StrBlob::check(size_type i, const string &msg) const
{
    if (i >= data->size())
    {
        throw out_of_range(msg);
    }
}

string &StrBlob::front()
{
    check(0, "front on empty StrBlob");
    return data->front();
}
const string &StrBlob::front() const
{
    check(0, "front on empty StrBlob");
    return data->front();
}
string &StrBlob::back()
{
    check(0, "back on empty StrBlob");
    return data->back();
}
const string &StrBlob::back() const
{
    check(0, "back on empty StrBlob");
    return data->back();
}

void StrBlob::pop_back()
{
    check(0, "pop_back on empty StrBlob");
    data->pop_back();
}

//当试图访问一个不存在的元素时，StrBlobPtr抛出一个异常
class StrBlobPtr
{
    friend bool eq(const StrBlobPtr &, const StrBlobPtr &);

public:
    StrBlobPtr() : curr(0){};
    StrBlobPtr(StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz){};

    string &deref() const;
    StrBlobPtr &incr(); //前缀增加；
    StrBlobPtr &decr(); //前缀递减；

private:
    //若check成功，返回一个指向vector的shared_ptr；

    shared_ptr<vector<string>> check(size_t, const string &) const;

    //保存一个 weak_ptr，意味着底层vector可能被销毁；
    weak_ptr<vector<string>> wptr;
    size_t curr; //在数组中的位置；
};

shared_ptr<vector<string>> StrBlobPtr::check(size_t i, const string &msg) const
{
    auto ret = wptr.lock(); // vector还在吗
    if (!ret)
    {
        throw runtime_error("unbound StrBlobPtr");
    }
    if (i >= (*ret).size())
    {
        throw out_of_range(msg);
    }
    return ret;
}

inline string &StrBlobPtr::deref() const
{
    auto p = check(curr, "dereference past end");
    return (*p)[curr]; //(*p)是对象所指的vector
}

//前缀递增： 返回递增后对象的引用
inline StrBlobPtr &StrBlobPtr::incr()
{
    //如果curr以及指向容器的尾后位置，则不能递增；
    check(curr, "increment past end of strblobptr");
    ++curr;
    return *this;
}
//前缀递减： 返回递减后对象的引用
inline StrBlobPtr &StrBlobPtr::decr()
{
    --curr;
    check(-1, "decrement past begin of strbloptr");
    return *this;
}

//StrBlobbegin和end成员的定义
inline StrBlobPtr StrBlob::begin()
{
    return StrBlobPtr(*this);
}
inline StrBlobPtr StrBlob::end()
{
    auto ret = StrBlobPtr(*this,data->size());
    return ret;
}

//StrBlobPtr的比较操作
inline
bool eq(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    auto l = lhs.wptr.lock(),r = rhs.wptr.lock();
    //若底层的vector是同一个
    if (l == r)
    {
        //则两个指针都是空，或者指向相同元素时，他们相等
        return (!r || lhs.curr == rhs.curr);
    }
    
}
inline
bool neq(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    return !eq(lhs,rhs);
    
}
#endif
