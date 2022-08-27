#include<string>
#include<iostream>
#include<vector>
using namespace std;

class Screen
{
public:
    using pos = string::size_type;//size type string或者vecto的长度；
    Screen() = default;
    Screen(pos ht,pos wd,char c):
    height(ht),width(wd),contents(ht*wd,c){}
    char get() const
    {
        return contents[cursor];
    }
    char get(pos ht,pos wd) const;
    Screen &move (pos ,pos );

public:
    Screen &set(char);
    Screen &set(pos,pos,char);
    Screen &display(ostream &os){do_display(os);return *this;};//非常量函数调用 常量do_display this指针隐式的从非常量转换为常量；
    const Screen &display(ostream &os) const {do_display(os);return *this;};//常量版本函数 如果 do_display不是常量函数即报错；
private:
    void do_display(ostream &os) const
    {
        os << contents;
    }
private:

    pos height = 0;
    pos width = 0;
    pos cursor = 0;
    string contents;
    

    
};

char Screen::get(pos ht,pos wd) const
{
    pos row = ht*width;
    return contents[row + wd];
}

Screen &Screen::move(pos ht,pos wd)
{
    pos row = ht*width;
    cursor = row+wd;
    return *this;
}
inline Screen &Screen::set(char c)
{
    contents[cursor] = c;
    return *this;
}
inline Screen &Screen::set(pos ht,pos wd,char c)
{
    contents[ht*width + wd] = c;
    return *this;
}

int main()
{
    Screen myscreen(5,5,'x');
    myscreen.move(4,4).set('d').display(cout);
    cout << "\n";
    myscreen.display(cout);
    return 0;
}