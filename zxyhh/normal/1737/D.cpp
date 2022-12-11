#include<bits/stdc++.h>
#define ll long long 
inline ll rd() {
    ll _x=0;int _ch=getchar(),_f=1;
    for(;!isdigit(_ch)&&(_ch!='-')&&(_ch!=EOF);_ch=getchar());
    if (_ch=='-'){_f=-1;_ch=getchar();}
    for(;isdigit(_ch);_ch=getchar()) _x=_x*10+_ch-'0';
    return _f*_x;
}
#define maxn 505
struct edg{
    int x,y,w;
};
std::vector< edg > edge;
int g[maxn][maxn];
int n,m;
void solve() {
    edge.clear();
    memset(g,0x3f,sizeof g);
    n=rd(),m=rd();
    for(int i=1;i<=n;i++) g[i][i]=0;
    for(int i=1;i<=m;i++) {
        int x=rd(),y=rd(),w=rd();
        edge.push_back({x,y,w});
        g[x][y]=1;g[y][x]=1;
    }
    for(int k=1;k<=n;k++) {
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) if (g[i][k]+g[k][j]<g[i][j])
                g[i][j]=g[i][k]+g[k][j];
        }
    }
    ll ans=1e18;
    for(auto i:edge) {
        ans=std::min(1ll*(std::min(g[1][i.x]+g[i.y][n],g[1][i.y]+g[i.x][n])+1)*i.w,ans);
        for(int j=1;j<=n;j++) {
            ans=std::min(ans,1ll*(std::min(g[i.x][j],g[i.y][j])+1+g[j][1]+g[j][n]+1)*i.w);
        }
    }
    printf("%lld\n",ans);
}
int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        solve();
    }
}