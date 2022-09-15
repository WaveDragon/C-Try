#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
bool isShorter(const string &s1, const string &s2) //使用lambda等价
{
    return s1.size() < s2.size();
}

void elimdups(vector<string> &words)
{
    // stable_sort(words.begin(), words.end(), isShorter);//使用lambda等价
    sort(words.begin(), words.end());
    auto end_unique = unique(words.begin(), words.end());
    words.erase(end_unique, words.end());
    stable_sort(words.begin(),words.end(),isShorter);
    for (auto i = words.begin(); i < words.end(); i++)
    {
        cout << *i << " ";
    }
    cout << endl;
}
// lambda编写
void lambda_test(int i1, int i2)
{
    auto sum = [](int a, int b) -> int
    { return a + b; };
    [i1](int a)
    { return a + i1; };
}

void biggies(vector<string> &words, vector<string>::size_type sz)
{
    elimdups(words);
    
    auto bigthansz_iter = find_if(words.begin(), words.end(),
                                  [sz](string &s1)
                                  { return s1.size() > sz; });
    auto count = words.end() - bigthansz_iter;
    cout << "Biger than " << sz << "is " << count << endl;
    for_each(bigthansz_iter, words.end(), [](const string &s1)
             { cout << s1 << " "; });
    cout << endl;
}

// biggies partition替换find_if
/*
接收一个谓词，对容器内容进行划分，使得谓词为true的值会排在前半部分，false排在后半部分
返回一个迭代器，指向最后一个true之后的位置。


*/
void biggies1(vector<string> &words, vector<string>::size_type sz)
{
    elimdups(words);
    
    auto bigthansz_iter = partition(words.begin(), words.end(),
                                    [sz](string &s1)
                                    { return s1.size() <= sz; });
    auto count = words.end() - bigthansz_iter;
    cout << "Biger than " << sz << "is " << count << endl;
    for_each(bigthansz_iter, words.end(), [](const string &s1)
             { cout << s1 << " "; });
    cout << endl;
}

auto sum = [](int a, int b) -> int
{ return a + b; };
int main()
{
    vector<int> vint;
    fill_n(back_inserter(vint), 10, 0);

    string word;
    vector<string> words = {"wo", "aa", "ddddd", "aaa", "bbbb", "durant", "aa", "Curry"};
    auto words1 = words;
    // while (cin >> word)
    // {
    //     words.push_back(word);
    // }

    biggies(words, 3);
    biggies1(words1, 3);
    // cout << sum(3, 4) << endl;
    return 0;
}