#include <bits/stdc++.h>
using namespace std;

int val[2][4];

int main ()
{
    int n;
    cin >> n;
    for (int _=0;4>_;_++)
    {
        int __=0;
        for (int i=0;n>i;i++)
        {
            string s;
            cin >> s;
            for (int j=0;n>j;j++)
            {
                if ((i+j)&1)
                {
                    if (s[j]=='1') ++__;
                }
                else
                {
                    if (s[j] == '0') ++__;
                }
            }
        }
        val[0][_] = __;
        val[1][_] = n*n-__;
    }
    int ans = 145893457;
    for (int i=0;16>i;i++)
    {
        int _=0,__=0;
        for (int j=0;4>j;j++)
        {
            if (((1<<j)&i) != 0) __ += val[1][j];
            else __ += val[0][j] , _++;
        }
        if (_ == 2) ans = min(ans,__);
    }
    printf("%d\n",ans);
}