#include "INCL.H"
#include <memory>

using namespace std;
struct destination
{
};
struct connection
{
    /* data */
};
connection connect(destination *pd)
{
    cout << "Open the linajie" << endl;
    return connection();
}
void disconnect(connection c)
{
    cout << "Close the lianjie" << endl;
}

//未使用shared_ptr版本
void f(destination &d)
{
    cout << "直接管理connect" << endl;
    connection c = connect(&d);
    //忘记调用disconnect 关闭连接
    cout << endl;
}

void end_connection(connection *p)
{
    disconnect(*p);
}

//使用 shared_ptr版本
void f1(destination &d)
{
    cout << "用shared_ptr管理 connect" << endl;
    connection c = connect(&d);

    shared_ptr<connection> p(&c, end_connection);
    //使用 lambda版本
    shared_ptr<connection> p1(&c,
                              [](connection *p)
                              { disconnect(*p); });

    cout << endl;
}

int main()
{
    destination d;
    f(d);
    f1(d);
    return 0;
}