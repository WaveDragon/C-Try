#include <iostream>
#include<string>
#include<vector>
#include<list>

using namespace std;

template <typename I,typename T>
I find(I b,I e,const T &v)
{
    while (b!=e && *b != v)
    {
        b++;    
    }
    return b;
}

int main()
{
    vector<int> vi = {1,2,3,4,5,6,3,4,7,8,9,10};
    list<string> ls = { "Hello world","Hi,mom","Oops"};
    auto iter = find(vi.begin(),vi.end(),6);
    if (iter == vi.end())
    {
        cout<<"No find 6" <<endl;
    }
    else
    {
        cout << "6 at" << iter-vi.begin() << endl;
    }

    auto iter1 = find(ls.begin(),ls.end(),"Oops");
    if (iter1 == ls.end())
    {
        cout<<"No find 6" <<endl;
    }
    else
    {
        cout << "find it"  << endl;
    }
    return 0;
}