#include <iostream>
using namespace std;

int main()
{
    int tux;
    cin >> tux;

    int foo=0, bar=0, baz=0, quz=1;

    while(tux!=0)
    {
        int pur;
        cin >> pur;
        foo += pur;
        bar++;

        if(foo*quz>=bar*baz)
        {
            baz=foo;
            quz=bar;
        }

        tux--;
    }

    double asd=baz;
    asd/=quz;
    cout << asd << endl;
}