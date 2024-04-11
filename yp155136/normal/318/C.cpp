#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

LL m;

LL solve(LL x,LL y)
{
    if (max(x,y) >= m) return 0;
    LL mn = min(x,y);
    LL mx = max(x,y);
    x = mn;
    y = mx;
    if (x<0)
    {
        LL T = (abs(x) + y - 1) / y;
        x += T * y;
        return T + solve(x,y);
    }
    return 1 + solve(mn+mx,mx);
}

int main ()
{
    LL x,y;
    cin >>x >> y >> m;
    if (max(x,y) >= m)
    {
        cout << 0 <<endl;
        return 0;
    }
    else if (max(x,y) <= 0)
    {
        cout << -1 << endl;
        return 0;
    }
    else
    {
        cout << solve(x,y) <<endl;
    }
}