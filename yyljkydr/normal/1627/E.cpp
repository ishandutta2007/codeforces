#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=1e5+1e3+7;

int T,n,m,k;

int x[N];

map<int,int>f[N];

typedef pair<int,int> pii;
#define fs first
#define sd second
#define mp make_pair

map<int,vector<pair<pii,int> > >g[N];

signed main()
{
    scanf("%lld",&T);
    while(T--)
    {
        scanf("%lld%lld%lld",&n,&m,&k);
        for(int i=1;i<=n;i++)
            g[i].clear(),f[i].clear();
        for(int i=1;i<=n;i++)
            scanf("%lld",&x[i]);
        for(int i=1;i<=k;i++)
        {
            int a,b,c,d,h;
            scanf("%lld%lld%lld%lld%lld",&a,&b,&c,&d,&h);
            g[a][b].push_back({{c,d},-h});
            f[a][b]=2e18;
            f[c][d]=2e18;
        }
        f[1][1]=0;
        f[n][m]=2e18;
        for(int i=1;i<=n;i++)
        {
            int mn=2e18;
            for(auto [j,w]:f[i])
            {
                f[i][j]=min(f[i][j],mn+j*x[i]);
                mn=min(mn,w-j*x[i]);
            }
            mn=2e18;
            for(auto it=f[i].rbegin();it!=f[i].rend();it++)
            {
                auto [j,w]=*it;
                f[i][j]=min(f[i][j],mn-j*x[i]);
                mn=min(mn,w+j*x[i]);
            }
            for(auto [j,d]:f[i])
            {
                for(auto [p,w]:g[i][j])
                {
                    auto [x,y]=p;
                    f[x][y]=min(f[x][y],d+w);
                }
            }
        }
        if(f[n][m]>=1e18)
            puts("NO ESCAPE");
        else
            printf("%lld\n",f[n][m]);
    }
}