#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

struct PersonInfo
{
    string name;
    vector<string> phones;
};

int main()
{
    ifstream fin("PersonInfo.txt");
    if (!fin)
    {
        cerr << "Can not open the file: " << endl;
    }
    string line;
    vector<PersonInfo> Persons;
    int i = 0;
    while (getline(fin, line))
    {
        PersonInfo person;
        string phone;
        istringstream sin(line);
        sin >> person.name;
        while (sin >> phone)
        {
            person.phones.push_back(phone);
        }
        ++i;
        Persons.push_back(person);
    }

    ostringstream os;
    for (const auto &i : Persons)
    {
        os << i.name;
        for (auto j : i.phones)
        {
            os << j << " ";
        }
        os << endl;
    }
    cout << os.str() << endl;// ostringstream 对象相当于 一个可以存储string或者换行符  的容器

    return 0;
}