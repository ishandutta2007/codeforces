#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

int main ()
{
    int n,w;
    scanf("%d %d",&n,&w);
    LL mx=0,mn =0;
    LL pre=0;
    for (int i=1;n>=i;i++)
    {
        int x;
        scanf("%d",&x);
        pre += x;
        mx = max(mx,pre);
        mn = min(mn,pre);
    }
    LL del = mx-mn;
    if (del > w+1) puts("0");
    else printf("%lld\n",w+1-del);
}