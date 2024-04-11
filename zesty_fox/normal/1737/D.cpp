#include <bits/stdc++.h>

using namespace std;

using i64=long long;
using vi=vector<int>;
using pii=pair<int,int>;

template<typename T>
inline T read(){
    T x=0,f=0;char ch=getchar();
    while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();
    while(isdigit(ch)) x=(x*10)+(ch^48),ch=getchar();
    return !f?x:-x;
}

#define rdi read<int>
#define rdi64 read<i64>
#define fi first
#define se second
#define mp make_pair
#define pb push_back

const int N=510,M=N*N,INF=0x3f3f3f3f;

int n,m;
int e[N][N],d[N][N],c[N][N];
struct{int x,y,w;}e1[M];

void solve(){
    n=rdi(),m=rdi();
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            e[i][j]=(i==j?0:INF);
    for(int i=1;i<=m;i++){
        int x=rdi(),y=rdi(),w=rdi();
        e[x][y]=e[y][x]=1;
        e1[i]={x,y,w};
    }
        
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            d[i][j]=e[i][j];
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j) continue;
            c[i][j]=min(d[i][1]+d[j][n],d[j][1]+d[i][n]);
            for(int k=1;k<=n;k++){
                c[i][j]=min(c[i][j],min(d[i][k],d[j][k])+1+d[k][1]+d[k][n]);
            }
        }
    }
    i64 ans=1e18;
    for(int i=1;i<=m;i++)
        ans=min(ans,(i64)(c[e1[i].x][e1[i].y]+1)*e1[i].w);
    cout<<ans<<'\n';

    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            e[i][j]=d[i][j]=c[i][j]=0;
}

int main(){
#ifdef LOCAL
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    int T=rdi();
    while(T--)
        solve();
    return 0;
}