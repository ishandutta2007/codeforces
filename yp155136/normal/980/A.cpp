#include <bits/stdc++.h>
using namespace std;

int main ()
{
    string s;
    cin >> s;
    int _=0,__=0;
    for (char i:s)
    {
        if (i == 'o') _++;
        else __++;
    }
    if (!_) puts("YES");
    else if (__%_==0) puts("YES");
    else puts("NO");
}