#include<bits/stdc++.h>
using namespace std;

int T,n;

signed main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        int tot=0;
        for(int i=1;i<=n*2;i++)
        {
            int x;
            scanf("%d",&x);
            tot+=(x&1);
        }
        puts(tot==n?"YES":"NO");
    }
}