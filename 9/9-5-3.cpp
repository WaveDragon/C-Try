#include <string>
#include <iostream>
#include <vector>
using namespace std;

void FindWord(string &str)
{
    string num = "1234567890";
    string bigletter = "ABCDEFGHIGKLMNOPQRSTUVWXYZ";
    string smallletter = "abcdefghigklmnopqrstuvwxyz";
    auto letter = bigletter + smallletter;
    string::size_type pos = 0;
    while ((pos = str.find_first_of(num,pos)) != string::npos)
    {
        cout << "Num index is :" << pos
             << "and it's :" << str[pos] << endl;
        ++pos;
    }
    string::size_type posl = 0;
    while ((posl = str.find_first_not_of(num,posl)) != string::npos)
    {
        cout << "Letter index is :" << posl
             << "and it's :" << str[posl] << endl;
        ++posl;
    }
}

int main()
{
    string test = "av2c3dfsd3fgefefg345";
    FindWord(test);
    return 0;
}