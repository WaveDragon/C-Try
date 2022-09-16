#include <fstream>
#include<iostream>
#include<vector>
#include<string>
#include<iterator>
#include<algorithm>
#include<numeric>

using namespace std;



int main(int argc,char* agrv[])

{
    // agrv[1] = "test.txt";
    ifstream in(agrv[1]);
    if (!in)
    {
        cout << "打开文件失败！"<< endl;
        exit(1);
    }

    istream_iterator<string> in_iter(in);
    istream_iterator<string> eof;
    vector<string> words;
    while (in_iter != eof)
    {
        words.push_back(*in_iter++);
    }
    ostream_iterator<string> out(cout," ");
    copy(words.begin(),words.end(),out);

    istream_iterator<int> in_intiter(cin);
    istream_iterator<int> enof;
    vector<int> vint;
    // cout << accumulate(in_intiter,enof,0)<<endl;
    while (in_intiter != enof)
    {
        vint.push_back(*in_intiter++);
    }
    sort(vint.begin(),vint.end());
    ostream_iterator<int> out_int(cout," ");
    unique_copy(vint.begin(),vint.end(),out_int);
    
    return 0;

}