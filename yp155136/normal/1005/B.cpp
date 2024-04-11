#include <bits/stdc++.h>
using namespace std;

int main ()
{
    string a,b;
    cin >> a >> b;
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    int tot = a.size() + b.size();
    for (int i=0;;i++)
    {
        if (i == a.size()) break;
        if (i == b.size()) break;
        if (a[i] != b[i]) break;
        tot -= 2;
    }
    cout << tot << endl;
}