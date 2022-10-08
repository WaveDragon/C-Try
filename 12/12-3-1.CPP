#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <memory>
#include "INCL.H"

using namespace std;
class QueryResult;
struct TextQuery
{
    using line_no = vector<string>::size_type;
private:
    shared_ptr<vector<string>> file;
    map<string,shared_ptr<set<line_no>>> wm;
public:
    TextQuery(ifstream &);
    QueryResult query (const string&) const;
};


class QueryResult
{
    friend ostream& print (ostream&, const QueryResult&);
    using line_no = vector<string>::size_type;

private:
    string sought; //查询单词；
    shared_ptr<set<line_no>> lines;//出现的行号;
    shared_ptr<vector<string>> file;//输入文件;
public:
    QueryResult(string s,shared_ptr<set<line_no>> p,shared_ptr<vector<string>> f):
    sought(s),lines(p),file(f){};
    
};




TextQuery::TextQuery(ifstream &in):file(new vector<string>)//???
{
    string text;
    while (getline(in, text))
    {
        file->push_back(text);
        int n = file->size() - 1;//当前行号;
        istringstream line(text);
        string word;
        while (line >> word)
        {
            auto &lines = wm[word];//lines是一个 shared_ptr;
            if (!lines)
            {
                lines.reset(new set<line_no>);//分配一个新的set；
            }
            lines->insert(n);    
        }
        
    }
}

QueryResult
TextQuery::query(const string& sought) const
{
    //未找到sought，将返回一个指向set的指针
    static shared_ptr<set<line_no>> nodata(new set<line_no>);
    auto loc = wm.find(sought);
    if (loc == wm.end())
    {
        return QueryResult(sought,nodata,file);
    }
    else
    {
        return QueryResult(sought,loc->second,file);
    }
}

ostream& print(ostream& os,const QueryResult &qr)
{
    os << qr.sought << " occurs " << qr.lines->size() << " "
    <<"times" << endl;

    for (auto num : *qr.lines)
    {
        os << "\t (line " << num + 1 << ")"<< *(qr.file->begin()+num) << endl;

    }
    return os;
}
void runQuerie(ifstream &infile)
{
    TextQuery tq(infile);

    while (true)
    {
        cout << "Enter the word to look for,or q to quit: " << endl;
        string s;
        if (!(cin >> s) || s == "q")
        {
            break;
        }
        print(cout, tq.query(s)) << endl;
    }
}


int main(int argc,char* argv[])
{
    ifstream infile(argv[1]);
    if (! infile)
    {
        cout << "Please enter the file! "<< endl;
        exit(1);
    }
    
    runQuerie(infile);
    return 0;
}