#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include <algorithm>
#include <iterator>
#include <vector>
#include <map>
#include <set>
using namespace std;


int main(int argc , char* argv[])
{
    ifstream in(argv[1]);
    if (! in)
    {
        cout<< "不能打开文件！"<<endl;
        exit(1);
    }
    



    return 0;
}