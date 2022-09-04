#include <list>
#include <deque>
#include <iostream>
#include <vector>

using namespace std;

vector<int>::iterator Search_val(vector<int>::iterator beg, vector<int>::iterator end, int val)
{
    while (beg != end)
    {
        if (*beg == val)
        {
            return beg;
        }

        beg++;
    }
    return end;
}

int main()
{

    list<deque<int>> a{{1, 2, 3}, {3, 4, 2}};

    vector<int> vallist{1, 3, 5, 66, 2, 2, 2, 1};
    cout << Search_val(vallist.begin(), vallist.end(), 2) - vallist.begin() << endl;

    list<int> alist = {1, 2, 3, 4, 5};
    vector<int> intvector = {3, 4, 2, 3};
    vector<double> avector(alist.begin(), alist.end());
    vector<double> bvector(intvector.begin(), intvector.end());
    char d = '3';
    char b = '4';
    list<char > plist ={&d,&b};
    
    vector<char *> pvector={&d,&b};

        return 0;
}