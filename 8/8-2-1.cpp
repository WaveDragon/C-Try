#include<string>
#include<vector>
#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    ifstream in("data.txt");
    if (!in)
    {
        cerr << "Can not open the file! " << endl;
        return -1;
    }

    string line;
    vector<string> words;
    while (getline(in,line))
    // while (in >> line)
    {
        words.push_back(line);
    }
    
    in.close();

    for (auto i = words.begin(); i != words.end(); i++)
    {
        cout<< *i << " ";
    }
    

    return 0;
}