#include<list>
#include<forward_list>
#include<vector>
using namespace std;

int main()
{
    list<int> lint = {1,23,4,5,6,7,8};//list 在地址中内存不连续，不能通过地址加减在元素间远距离移动；
    auto lint_be = lint.begin();
    while (lint_be != lint.end())
    {
        if (*lint_be %2 == 1)
        {
            auto temp = *lint_be+2;
            ++lint_be;
            
            lint_be = lint.insert(lint_be,temp);//lint_be--  先运行 lint_be, 再--
            ++lint_be;
        }
        else
        {
            lint_be = lint.erase(lint_be);
        }
        
    }
    
    forward_list<int> fint = {1,2,3,4,5,6,8,9};
    auto curr_fint = fint.begin();
    auto prev_fint = fint.before_begin();
    while (curr_fint != fint.end())
    {
        if (*curr_fint %2)
        {
            curr_fint = fint.insert_after(curr_fint,100);
            ++prev_fint;++prev_fint;
            ++curr_fint;
        }
        else
        {
            curr_fint = fint.erase_after(prev_fint);
        }
        
    }
    




    return 0;
}