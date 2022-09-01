#include<string>
#include<iostream>
#include<vector>
using namespace std;

class Book
{
private:
    string Name,ISBN,Author,Publisher;
    double Price = 0;

public:
    Book(const string&n,const string &i,const string &Au,const string &P):
    Name(n),ISBN(i),Author(Au),Publisher(P){}
    Book():Book(" "," "," "," "){}
    // Book(istream &is){is >> *this;}
};


int main()
{   
    Book o = Book();
    return 0;
}