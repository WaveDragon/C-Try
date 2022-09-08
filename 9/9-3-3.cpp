#include <vector>
#include <list>
#include <iostream>

using namespace std;


int main()
{
    int ia[]={0,1,1,2,3,5,8,13,21,55,89};

    vector<int> vina;
    list<int> lina;
    vina.assign(ia,ia+11);
    lina.assign(ia,ia+11);

    // for (auto i = vina.begin(); i < vina.end(); i++)//vector删除元素后 之后的迭代器引用和指针失效。
    // {
    //     if (*i%2 == 1)
    //     {       
    //         // i = vina.erase(i);//把指针指向删除后的元素，但是for循环还是会++i;
    //         vina.erase(i);//会使i失效；行为 未知
    //     }
        
    // }
    // for (auto i = lina.begin(); i != lina.end(); i++)//vector删除元素后 之后的迭代器引用和指针失效。
    // {
    //     if (*i%2 == 1)
    //     {       
    //         i = lina.erase(i);//把指针指向删除后的元素，但是for循环还是会++i;
    //         // lina.erase(i);//i虽然不会失效，但是程序卡顿？
    //     }
        
    // }

    //for 循环不适合

    auto vina_b = vina.begin();
    auto lina_b = lina.begin();
    while (lina_b != lina.end() )
    {
        if (*lina_b %2 == 1)
        {
            lina_b = lina.erase(lina_b);
        }
        else
            lina_b++;
    }
    while (vina_b != vina.end() )
    {
        if (*vina_b %2 == 1)
        {
            vina_b = vina.erase(vina_b);
        }
        else
            vina_b++;
    }

    return 0;
}