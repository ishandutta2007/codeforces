#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e2+7;

int T,n,to[N],a[N],b[N],vis[N];

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        int ca=0,cb=0;
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]),vis[i]=0;
        for(int i=1;i<=n;i++)
            scanf("%d",&b[i]),to[a[i]]=b[i];
        for(int i=1;i<=n;i++)
        {
            if(vis[i])
                continue;
            int x=i;
            int c=0;
            while(!vis[x])
                vis[x]=1,x=to[x],++c;
            ca+=c>>1,cb+=c>>1;
        }
        long long ans=0;
        for(int i=n;i>=n-cb+1;i--)
            ans+=2*i;
        for(int i=1;i<=ca;i++)
            ans-=2*i;
        printf("%lld\n",ans);
    }
}