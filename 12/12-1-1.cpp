#include<iostream>
using namespace std;

#include "my_StrBolb.H"

int main()
{
    StrBlob b1;
    {
        StrBlob b2 = {"an", "Hello","World"};
        b1 = b2;
        b1.push_back("Hell");
        cout << b2.size() <<endl;
    }

    cout << b1.size() << endl;
    
    return 0;
}
