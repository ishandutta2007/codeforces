#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll,ll>
#define fi first
#define se second

int n, m, p0, p1, v[2020];
struct E{
    int to, w;
};
vector<E>G[2020];

ll d[2][2020], a[2020][2020], s[2020][2020], c[2020][2020], f[2020][2020][2], g[2020][2020][2];

int to[2020][2020][2];

void djst(int s,ll d[2020]){
    priority_queue<pll,vector<pll>,greater<pll> >q;
    for (int i=1;i<=n;++i) d[i]=1e18; d[s]=0; q.push({0,s});
    while (!q.empty()){
        pll p=q.top(); q.pop();
        if (d[p.se]!=p.fi) continue;
        int x=p.se;
        for (auto o:G[x]){
            int y=o.to; ll w=o.w+p.fi;
            if (w<d[y]){
                d[y]=w; q.push({w,y});
            }
        }
    }
    map<ll,int>mp; int tot=0;
    for (int i=1;i<=n;++i) mp[d[i]]=0;
    for (auto &o:mp) o.se=++tot;
    for (int i=1;i<=n;++i) d[i]=mp[d[i]];
}

int main(){
    cin>>n>>m>>p0>>p1;
    for (int i=1;i<=n;++i) cin>>v[i];
    for (int x,y,z;m--;){
        cin>>x>>y>>z;
        G[x].push_back({y,z});
        G[y].push_back({x,z});
    }
    djst(p0,d[0]);
    djst(p1,d[1]);
    for (int i=1;i<=n;++i) a[d[0][i]][d[1][i]]+=v[i], ++c[d[0][i]][d[1][i]];
    for (int i=n;i>=1;--i)
        for (int j=n;j>=1;--j){
            s[i][j]=a[i][j]+s[i+1][j]+s[i][j+1]-s[i+1][j+1];
            c[i][j]=c[i][j]+c[i+1][j]+c[i][j+1]-c[i+1][j+1];
        }
    memset(f,-33,sizeof f);
    memset(g,33,sizeof g);
    for (int i=n+1;i>=1;--i)
        for (int j=n+1;j>=1;--j)
            for (int k=0;k<2;++k){
                if (i>n||j>n){
                    to[i][j][k]=n+1;
                    f[i][j][k]=0;
                }else{
                    to[i][j][k]=c[i][j]-c[i+(k==0)][j+(k==1)]? (k==0? i+1: j+1): to[i+(k==0)][j+(k==1)][k];
                    f[i][j][k]=s[i][j]-(k==0? g[to[i][j][k]][j][k^1]: g[i][to[i][j][k]][k^1]);
                }
                g[i][j][k]=min(g[i+(k==1)][j+(k==0)][k],f[i][j][k]+s[i][j]);
            }
    ll ans=f[1][1][0];
    if (ans==0) puts("Flowers");
    if (ans>0) puts("Break a heart");
    if (ans<0) puts("Cry");
}