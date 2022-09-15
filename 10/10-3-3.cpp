#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>
using namespace std;

void lambda_test(int i)
{
    int a = i;
    auto f1 = [a]() mutable -> bool
    {
        if (a == 0)
        {
            return true;
        }
        else
        
        {
            a--;
        }
            
        return false;
    };
    cout << f1() <<endl;
}

int main()
{
    int num = 0;
    list<string> lstr = {"wo", "hello", "hi world", "tecent", "bytedance"};
    auto bigthan6num = count_if(lstr.begin(), lstr.end(),
                                [num](const string &a)
                                { return a.size() > 1 ? num + 1 : num; });
    cout << bigthan6num << endl;

    lambda_test(12);
    return 0;
}
