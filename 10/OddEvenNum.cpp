#include<fstream>
#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
using namespace std;

int main(int argc,char* argv[])
{
    // argv[1] = "int.txt";
    // argv[2] = "even.txt";
    // argv[3] = "odd.txt";
    ifstream in(argv[1]);
    if (!in)
    {
        cout<<"打开文件失败"<<endl;
        exit(1);
    }
    istream_iterator<int> in_int_iter(in);
    istream_iterator<int> eof;
    vector<int> nums;
    while (in_int_iter != eof)
    {
        nums.push_back(*in_int_iter++);
    }
    in.close();
    vector<int> odd_n,even_n;

    ofstream fout_even(argv[2]);
    ostream_iterator<int> outfile_even(fout_even," ");

    ofstream fout_odd(argv[3]);
    ostream_iterator<int> outfile_odd(fout_odd,"\n");
    // for (auto i :nums)
    // {
    //     if ((i) %2)
    //     {
    //         outfile_odd = i;
    //     }
    //     else
    //     {
    //         outfile_even = i;
    //     }
        
    // }
    vector<int> int1 = {1,2,3,4,5,7};
    copy(int1.begin(),int1.end(),outfile_odd);

    return 0;
}