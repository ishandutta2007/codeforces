#include<bits/stdc++.h>
using namespace std;

const int N=21;

int T,n,a[N],f[1<<N],vis[1000001];

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        memset(vis,0,sizeof(vis));
        scanf("%d",&n);
        int ok=0;
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]),ok|=!a[i],f[1<<(i-1)]=abs(a[i]);
        for(int S=0;S<(1<<n);S++)
        {
            f[S]=f[S-(S&-S)]+f[S&(-S)];
            if(vis[f[S]])
                ok=1;
            vis[f[S]]++;
        }
        puts(ok?"YES":"NO");
    }
}