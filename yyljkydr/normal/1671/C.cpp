#include<bits/stdc++.h>
using namespace std;

const int N=1e6+1e3+7;

int T;

int n,a[N];

long long s[N];

int x;

bool chk(int t,int p)
{
    return 1ll*(t-1)*p+s[p]<=x;
}

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&x);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        for(int i=1;i<=n;i++)
            s[i]=s[i-1]+a[i];
        long long ans=0;
        for(int i=1;i<=n;i++)
        {
            int l=1,r=x+1;
            if(s[i]>x)
                continue;
            while(r-l>1)
            {
                int mid=(l+r)>>1;
                if(chk(mid,i))
                    l=mid;
                else
                    r=mid;
            }
            ans+=l;
        }
        printf("%lld\n",ans);
    }
}