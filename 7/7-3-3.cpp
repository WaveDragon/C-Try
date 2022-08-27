#include<iostream>
#include<string>
using namespace std;

class X;
class Y;
class X
{
    public:
    Y *py;
};
class Y
{
    public:
    X a;
};


int main()
{


    return 0;
}
