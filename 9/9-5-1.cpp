#include<string>
#include<vector>
#include<iostream>
using namespace std;

int main()
{
    vector<char> vchar = {'h','e'};
    string s(vchar.data(),vchar.size());
    // auto a = vchar.data();
    // cout<< vchar.data()<<endl;


    return 0;
}