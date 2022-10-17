#include <bits/stdc++.h>
typedef long long LL;
using namespace std;
LL u, v;
int main()
{
    ios::sync_with_stdio(false);
    cin >> u >> v;
    LL delta = v - u;
    if(delta < 0 || (delta & 1))
    {
        cout << -1 << endl;
        return 0;
    }
    if(!delta)
    {
        if(!u) cout << 0 << endl;
        else cout << 1 << '\n' << u << endl; 
    }
    else
    {
        LL haf = delta >> 1;
        if((haf & u) == 0) cout << 2 << '\n' << haf << ' ' << (haf ^ u) << endl;
        else cout << 3 << '\n' << haf << ' ' << haf << ' ' << u << endl;
    }
    return 0;
}