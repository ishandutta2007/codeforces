#include <iostream>
#include <cstdio>
using namespace std;

int main ()
{
    int a,b,c;
    cin >> a >> b >> c;
    int cnt = 1000006;
    int i=1;
    while (cnt--)
    {
        if ((a*10)/b == c)
        {
            cout << i <<endl;
            return 0;
        }
        i++;
        a *= 10;
        a %= b;
    }
    cout << -1 << endl;
}