#include <vector>
#include <functional>
#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

int main()
{
    vector<int> vint = {1, 2, 3, 4, 1, 1, 1, 2, 3, 4, 5, 6, 7, 78, 9, 9, 0};
    list<int> lint;
    list<int> lint_back_inserter,lint_front_inserter;
    unique_copy(vint.cbegin(), vint.cend(), inserter(lint, lint.begin()));
    unique_copy(vint.cbegin(), vint.cend(), front_inserter(lint_front_inserter));
    unique_copy(vint.cbegin(), vint.cend(), back_inserter(lint_back_inserter));
    for_each(lint.begin(), lint.end(),
             [](int i)
             { cout << i << " "; });

    return 0;
}