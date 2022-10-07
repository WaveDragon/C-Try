#include <iostream>
#include <string>
#include <memory>

using namespace std;

int main()
{
    allocator <string> alloc;
    //分配100个未初始化的string;
    auto const p = alloc.allocate(100);
    string s;
    string *q = p;//q指向第一个 string
    while (cin >> s && q!= p+100)
    {
        alloc.construct(q++,s);
    }
    const size_t size = q-p;//记录读取了多少个string;

    //使用数组
    for (size_t i = 0; i < size; i++)
    {
        cout << p[i] << " " << endl;
    }
    
    //对象析构(destory)和内存释放(deallocate)分开操作

    while (q!= p)
    {
        alloc.destroy(--q);
    }
    alloc.deallocate(p,100);


    return 0;
}