#include <vector>
#include <string>
#include <iostream>
#include <functional>
#include <algorithm>

using namespace std;
using namespace std::placeholders;

bool check_size(const string &s1, unsigned sz)
{
    return s1.size() < sz ? true : false;
}

int main()
{
    int num = 0;
    unsigned sz = 3;
    vector<string> vstr = {"curry", "Hello", "WOrld", "James", "Messi", "wo"};
    auto i = count_if(vstr.begin(), vstr.end(),
                      [](const string &s1)
                      {
                          return s1.size() > 1 ? true : false;
                      });
    auto temp = bind(check_size, _1, sz);
    auto j = count_if(vstr.begin(), vstr.end(),
                      bind(check_size, _1, 3));

    auto k = count_if(vstr.begin(), vstr.end(),
                      temp);

    cout << i << endl;
    cout << j << endl;
    cout << k << endl;

    vector<int> vint = {1,2,3,4,5,6,7,8,9,10};
    string st1 = "HEllo";
    auto site =  find_if(vint.begin(),vint.end(),bind(check_size,st1,_1));
    cout << *site <<endl;

    return 0;
}