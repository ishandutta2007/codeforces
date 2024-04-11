#include <bits/stdc++.h>
using namespace std;

int main ()
{
    string s;
    cin >> s;
    int ans = 123456789;
    int n=s.size();
    for (int i=1;(1<<n)>i;i++)
    {
        int sz=0;
        int now=0;
        bool first=false;
        for (int j=0;n>j;j++)
        {
            if (((1<<j)&i) != 0)
            {
                if (!first && s[j] == '0')
                {
                    sz = -10247;
                }
                first = true;
                ++sz;
                now *= 10;
                now += (s[j] - '0');
            }
        }
        int gee = sqrt(now);
        if (gee * gee == now)
        {
            ans = min(ans,n-sz);
        }
    }
    if (ans > 13) cout << -1 << endl;
    else cout << ans << endl;
}