#include <vector>
#include<iostream>
#include<iostream>
using namespace std;

int main()
{

    vector<int> vi;
    int s,c;
    for (s  = vi.size(),c=vi.capacity(); s <= c; s++)
    {
        vi.push_back(s);

    }
    cout <<vi.capacity()<< " " << vi.size()<<endl;

    for (s  = vi.size(),c=vi.capacity(); s <= c; s++)
    {
        vi.push_back(s);

    }
    cout <<vi.capacity()<< " " << vi.size()<<endl;

    for (s  = vi.size(),c=vi.capacity(); s <= c; s++)
    {
        vi.push_back(s);

    }
    cout <<vi.capacity()<< " " << vi.size()<<endl;

    for (s  = vi.size(),c=vi.capacity(); s <= c; s++)
    {
        vi.push_back(s);

    }
    cout <<vi.capacity()<< " " << vi.size()<<endl;



    return 0;
}