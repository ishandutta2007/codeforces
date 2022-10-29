#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

int main ()
{
    LL x;
    cin >> x;
    if (x == 2)
    {
        cout << 1 << endl;
        return 0;
    }
    LL ans=0;
    for (int i=0;50>i;i++)
    {
        if ((1LL<<i) > x) break;
        ans += ((x + (1LL<<i) - 1)/(1LL<<i))/2 * (1LL<<i);
    }
    cout << ans << endl;
}