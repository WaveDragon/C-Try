#include <vector>
#include <string>
#include <iostream>
using namespace std;

struct Data
{
private:
    unsigned year;
    unsigned moon;
    unsigned day;

public:
    Data() = default;
};

void computer(vector<string> s1)
{
    float sum = 0;
    for (auto i = s1.begin(); i < s1.end(); i++)
    {
        sum += stof(*i);
    }
    cout << sum << endl;
}

int main()
{
    string num;
    vector<string> nums;
    while (cin >> num)
    {
        nums.push_back(num);
    }
    computer(nums);
    return 0;
}