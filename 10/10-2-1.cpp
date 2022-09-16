#include <vector>
#include <string>
#include <iostream>
#include <numeric>
using namespace std;

int main()
{
    vector<int> vint = {1, 2, 3, 4, 5, 2, 2, 2, 2, 3};
    int sum = accumulate(vint.begin(), vint.end(), 0);
    cout << sum << endl;

    return 0;
}