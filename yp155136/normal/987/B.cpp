#include <bits/stdc++.h>
using namespace std;

int main ()
{
    double a,b;
    int x,y;
    cin >>x >> y;
    a = x*log(y);
    b = y*log(x);
    if (x == y || abs(a-b) <= 1e-10) cout << "=" << endl;
    else if (x * log(y) > y*log(x)) cout << "<" << endl;
    else cout << ">" << endl;
}