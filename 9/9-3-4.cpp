#include <forward_list>
#include <string>
#include <vector>
using namespace std;

void T928(forward_list<string>& flist, string &s1, string &s2)//不是引用的话 无法对flist更改
{
    auto prev = flist.before_begin();
    auto curr = flist.begin();
    auto en = flist.end();
    int t = 0;
    while (curr != flist.end())
    {
        if (*curr == s1)
        {
            curr = flist.insert_after(curr, s2);
            t++;
        }

        prev = curr;
        ++curr;
    }
    if (t == 0)
    {
        flist.insert_after(prev, s2);
    }
}

int main()
{
    forward_list<string> l1 = {"sdfasd", "adfasdfcc", "James", "Durant"};
    forward_list<string> l2 = {"sdfasd", "adfasdfcc", "James", "Durant"};
    string st1 = "James", st2 = "King", st3 = "Curry";
    T928(l1, st1, st2);
    T928(l2, st3, st2);
    vector<int> vint = {};
    
    auto vbe = vint.begin();
    vbe++;
    while (vbe != vint.end())
    {
        vbe = vint.insert(vbe,4);
        vbe+=2;
    }
    
    int t = 3;
    ++t;
    t++;
    return 0;
}