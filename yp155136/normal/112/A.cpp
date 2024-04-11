#include <bits/stdc++.h>
using namespace std;

int main ()
{
    string s,t;
    cin >>s >> t;
    for (char &i:s)
    {
        if (i <= 'Z') i += ('a' - 'A');
    }
    for (char &i:t)
    {
        if (i <= 'Z') i += ('a' - 'A');
    }
    if (s == t) cout << 0 << endl;
    else if (s < t) cout << -1 <<endl;
    else cout << 1 << endl;
}