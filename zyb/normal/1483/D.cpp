#include<bits/stdc++.h>
#define N 605
using namespace std;
#define pb push_back
#define lowbit(x) x&-x
#define inf 10000000000000ll
int q,n,m,g[N][N],ans[N*N];
long long a[N][N],dis[N][N],D[N][N];
struct node {
    int x,y,v;
}b[N*N];
int main() {
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
    for (int j=1;j<=n;j++) a[i][j]=inf;
    for (int i=1;i<=n;i++) a[i][i]=0;
    for (int i=1;i<=m;i++) {
        scanf("%d%d%d",&b[i].x,&b[i].y,&b[i].v);
        a[b[i].x][b[i].y]=b[i].v;
        a[b[i].y][b[i].x]=b[i].v;
        g[b[i].x][b[i].y]=g[b[i].y][b[i].x]=i;
    }
    for (int i=1;i<=n;i++)
    for (int j=1;j<=n;j++) dis[i][j]=a[i][j];
    for (int i=1;i<=n;i++) dis[i][i]=0;
    for (int k=1;k<=n;k++)
    for (int i=1;i<=n;i++)
    for (int j=1;j<=n;j++)
    dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    scanf("%d",&q);
    for (int i=1;i<=q;i++) {
        int x,y,v;
        scanf("%d%d%d",&x,&y,&v);
        D[x][y]=max(D[x][y],1ll*v);
        D[y][x]=max(D[y][x],1ll*v);
    }
    for (int u=1;u<=n;u++)
    for (int y=1;y<=n;y++) {
        long long d=-inf;
        for (int v=1;v<=n;v++)
        if (D[u][v]) d=max(d,D[u][v]-dis[y][v]);
        for (int x=1;x<=n;x++) {
            if (!g[x][y]||ans[g[x][y]]) continue;
            if (dis[u][x]+a[x][y]<=d) ans[g[x][y]]=1;
        }
    }
    int Ans=0;
    for (int i=1;i<=m;i++) Ans+=ans[i];
    printf("%d\n",Ans);
}