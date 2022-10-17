#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=2e5+1e3+7;

int T;

int n,a[N],b[N];

signed main()
{
    scanf("%lld",&T);
    while(T--)
    {
        scanf("%lld",&n);
        int sb=0;
        int sn=n*(n+1)/2;
        for(int i=1;i<=n;i++)
            scanf("%lld",&b[i]),sb+=b[i];
        if(sb%sn)
        {
            puts("NO");
            continue;
        }
        int sa=sb/sn;
        bool ok=1;
        for(int i=1;i<=n;i++)
        {
            if((sa-b[i]+b[(i-2+n)%n+1])%n)
            {
                ok=0;
                break;
            }
            a[i]=(sa-b[i]+b[(i-2+n)%n+1])/n;
            if(a[i]<=0)
            {
                ok=0;
                break;
            }
        }
        if(!ok)
        {
            puts("NO");
            continue;
        }
        for(int i=1;i<=n;i++)
            sa-=a[i];
        if(sa)
        {
            puts("NO");
            continue;
        }
        puts("YES");
        for(int i=1;i<=n;i++)
            printf("%lld%c",a[i]," \n"[i==n]);
    }
}