#include <iostream>
using namespace std;

inline __int64 sqr(__int64 a) {return a*a;}
__int64 power2(int n)
{
    if(0 == n) return 1;//递归基
    return (n & 1) ? sqr(power2(n >> 1)) <<1 : sqr(power2(n >> 1));//视n奇偶分别递归;
}

int main()
{
    auto b = power2(5);
    return 0;
}