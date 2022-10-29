#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

int main ()
{
    ios::sync_with_stdio(0); cin.tie(0);
    LL n,x,y;
    cin >> n >> x >> y;
    string s;
    cin >> s;
    s += "1";
    LL cnt=0;
    int tmp=0;
    for (char i:s)
    {
        if (i == '1')
        {
            if (tmp) ++cnt;
            tmp=0;
        }
        else
        {
            ++tmp;
        }
    }
    LL all = cnt;
    LL ans = all*y;
    for (int _=1;all-1>=_;_++)
    {
        ans = min(ans,_*x + (all-_)*y);
    }
    cout << ans << endl;
}