#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    const char *c1 = "Hello ";
    const char *c2 = "World";
    char *r = new char[strlen(c1) + strlen(c2) + 1];
    strcpy(r, c1);
    strcat(r, c2);

    cout << r << endl;

    string s1 = "String111";
    string s2 = "World";

    //对两个string对象，使用+即可实现连接，然后用c_str获取连接结果(临时string对象)的内存地址，用strcpy拷贝刀动态数组；
    strcpy(r, (s1 + s2).c_str());
    cout << r << endl;

    delete[] r;

    char c;

    char *r1 = new char[20];
    int l = 0;

    while (cin.get(c))
    {
        if (isspace(c))
        {
            break;
        }
        r1[l++] = c;
        if (l == 20)
        {
            cout << "达到容量上限" << endl;
            break;
        }
    }
    r1[l] = 0;
    cout << r1 << endl;

    delete [] r1;
    return 0;
}