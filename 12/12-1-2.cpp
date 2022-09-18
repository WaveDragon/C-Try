#include <iostream>
#include "my_StrBolb.H"
using namespace std;

vector<int> *new_vector(void)
{
    return new (nothrow) vector<int>;
}

void read_ints(vector<int> *pv)
{
    int v;
    while (cin >> v)
    {
        pv->push_back(v);
    }
}

void print_ints(vector<int> *pv)
{
    for (const auto &i : *pv)
    {
        cout << i << " ";
    }
    cout << endl;
}

//使用智能指针 管理内存 省去释放内存的工作

shared_ptr<vector<int>> new_vector_ptr(void)
{
    return make_shared<vector<int>>();
}

void read_ints_ptr(shared_ptr<vector<int>> pv)
{
    int v;
    while (cin >> v)
    {
        pv->push_back(v);
    }
}

void print_ints(shared_ptr<vector<int>> pv)
{
    for (const auto &i : *pv)
    {
        cout << i << " ";
    }
    cout << endl;
}

int main()
{
    auto pv = new_vector_ptr();
    if (!pv)
    {
        cout << "内存不足" << endl;
        return -1;
    }
    read_ints_ptr(pv);

    print_ints(pv);
    
    
    // delete pv;
    // pv = nullptr;


    return 0;
}