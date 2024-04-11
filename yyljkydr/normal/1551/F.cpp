#include<bits/stdc++.h>
using namespace std;

const int N=117,P=1e9+7;

int n,k;

vector<int>g[N];

int cnt[N],f[N][N];

void dfs(int x,int f,int d)
{
    cnt[d]++;
    for(auto v:g[x])
    {
        if(v==f)
            continue;
        dfs(v,x,d+1);
    }
}

int T;

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++)
            g[i].clear();
        for(int i=1;i<n;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        if(k==2)
        {
            printf("%d\n",n*(n-1)/2);
            continue;
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<n;j++)
            {
                f[j][0]=1;
                for(int t=1;t<=k;t++)
                    f[j][t]=0;
            }
            for(auto x:g[i])
            {
                for(int j=0;j<n;j++)
                    cnt[j]=0;
                dfs(x,i,0);
                for(int j=0;j<n;j++)
                    for(int t=k;t>=1;t--)
                        f[j][t]=(f[j][t]+1ll*f[j][t-1]*cnt[j]%P)%P;
            }
            for(int j=0;j<n;j++)
                ans=(ans+f[j][k])%P;
        }
        printf("%d\n",ans);
    }
}