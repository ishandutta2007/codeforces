#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=1e6+1e3+7;

int T,a,b,k,p[N],ptot,vis[N];

void pre()
{
    int n=100000;
    for(int i=2;i<=n;i++)
    {
        if(!vis[i])
            p[++ptot]=i;
        for(int j=1;j<=ptot&&i*p[j]<=n;j++)
        {
            if(i%p[j]==0)
                continue;
            vis[i*p[j]]=1;
        }
    }
}

signed main()
{
    pre();
    scanf("%lld",&T);
    while(T--)
    {
        scanf("%lld%lld%lld",&a,&b,&k);
        int ca=0,cb=0;
        int x=a,y=b;
        for(int i=1;i<=ptot&&p[i]*p[i]<=x;i++)
            while(x%p[i]==0)
                ca++,x/=p[i];
        if(x!=1)
            ca++;
        for(int i=1;i<=ptot&&p[i]*p[i]<=y;i++)
            while(y%p[i]==0)
                cb++,y/=p[i];
        if(y!=1)
            cb++;
        if(ca<cb)
            swap(ca,cb);
        if(a==b&&k==1)
            puts("NO");
        else if(k>ca+cb)
            puts("NO");
        else if(a%b==0||b%a==0)
            puts("YES");
        else
            puts(k==1?"NO":"YES");
    }
}