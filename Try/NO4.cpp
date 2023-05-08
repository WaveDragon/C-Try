#include <vector>
#include<string>
#include<algorithm>

using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        // auto tmp = flowerbed;
        flowerbed.insert(flowerbed.begin(),0);
        flowerbed.push_back(0);
        for (auto i = flowerbed.begin()+1;i < flowerbed.end()-1; i=i+1)
        {
            if (*i == 0 and *(i-1)== 0 and *(i+1) == 0)
            {
                *i = 1;
                n -= 1;
            }
        }
        return (n <- 0);
    }
};