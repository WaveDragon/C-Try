#include<vector>
#include<iterator>
#include<iostream>
#include<algorithm>
#include<list>
using namespace std;

int main()
{
    vector<string> vstr = {"Hello","World","James","Curry"};
    for (auto i = vstr.rbegin(); i < vstr.rend(); i++)
    {
        cout << *i <<" ";
    }
    cout << endl;
    for (auto i = vstr.end()-1; i >= vstr.begin(); i--)
    {
        cout << *i << " ";
    }
    vector<int > vint = {1,2,3,4,5,3,2,32,3,4,5,03,404,0,0,3,0,4,5,6};
    list<int> lint;
    
    copy(vint.rend()-8,vint.rend()-3,inserter(lint,lint.begin()));
    auto index = find(vint.rbegin(),vint.rend(),0);
    int p = 1;
    for (auto i = vint.cbegin(); i != index.base()-1; i++,p++);
    
    cout << p <<" " << *index <<endl;    

    return 0;
}