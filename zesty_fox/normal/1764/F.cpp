// LUOGU_RID: 96102363
#include <bits/stdc++.h>

using namespace std;

using i64=long long;
using u64=unsigned long long;
using db=double;
using pii=pair<int,int>;
using vi=vector<int>;

template<typename T>
inline T read(){
    T x=0,f=0;char ch=getchar();
    while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();
    while(isdigit(ch)) x=x*10+(ch-'0'),ch=getchar();
    return f?-x:x;
}

#define rdi read<int>
#define rdi64 read<i64>
#define fi first
#define se second
#define pb push_back

const int N=2010;

int n;
i64 f[N][N],d[N][N];

int main(){
#ifdef LOCAL
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
#endif
    n=rdi();
    for(int i=1;i<=n;i++)
        for(int j=1;j<=i;j++)
            f[i][j]=f[j][i]=rdi64();

    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            d[i][j]=(f[i][i]+f[j][j]-2*f[i][j])/n;

    static int vis[N],fr[N];
    static i64 dis[N];
    fill(dis+1,dis+n+1,4e18);
    dis[1]=0;
    for(int i=1;i<=n;i++){
        int p;i64 mi=4e18;
        for(int j=1;j<=n;j++)
            if(!vis[j]&&dis[j]<mi) mi=dis[j],p=j;
        vis[p]=1;
        if(fr[p]) cout<<fr[p]<<' '<<p<<' '<<dis[p]<<'\n';
        for(int j=1;j<=n;j++)
            if(!vis[j]&&d[p][j]<dis[j])
                dis[j]=d[p][j],fr[j]=p;
    }
    return 0;
}