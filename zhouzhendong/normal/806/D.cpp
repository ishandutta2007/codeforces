#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL read(){
    LL x=0,f=0;
    char ch=getchar();
    while (!isdigit(ch))
        f|=ch=='-',ch=getchar();
    while (isdigit(ch))
        x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
    return f?-x:x;
}
const int N=2005;
const int INF=2e9;
int n;
int g[N][N];
int tag[N],near[N];
int vis[N];
LL dis[N];
int main(){
    n=read();
    int Min=INF;
    for (int i=1;i<=n;i++)
        for (int j=i+1;j<=n;j++){
            g[i][j]=g[j][i]=read();
            Min=min(Min,g[i][j]);
        }
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            if (i!=j){
                g[i][j]-=Min;
                if (!g[i][j])
                    tag[i]=tag[j]=1;
            }
    int S=n+1;
    for (int i=1;i<=n;i++)
        g[S][i]=g[i][S]=tag[i]?0:INF;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            if (i!=j)
                g[S][i]=g[i][S]=min(g[i][S],2*g[i][j]);
    for (int i=1;i<=n+1;i++)
        vis[i]=0,dis[i]=1e15;
    dis[S]=0;
    for (int i=1;i<=n+1;i++){
        int x=0;
        for (int j=1;j<=n+1;j++)
            if (!vis[j]&&(x==0||dis[j]<dis[x]))
                x=j;
        vis[x]=1;
        for (int j=1;j<=n+1;j++)
            if (!vis[j]&&dis[j]>dis[x]+g[x][j])
                dis[j]=dis[x]+g[x][j];
    }
    for (int i=1;i<=n;i++)
        cout << dis[i]+(LL)Min*(n-1) << endl;
    return 0;
}