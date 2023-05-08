#include<string>
#include<iostream>
using namespace std;


class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        auto ps = s.begin();
        auto pt = t.begin();

        int num = 0;
        for (pt; pt < t.end(); pt++)
        {
            if (*pt == *ps)
            {
                ps++;
                num++;

            }
            
        }
        return (num == s.size());
    }
};