#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int>P;
const int N=105;
int t,n,m,b[N][N],a[N][N],g[N][N],f[N][N],c[N],ans[N][N];
P p[N*N];
bool vis[N][N];
int main(){
  for(scanf("%d",&t);t;--t){
    scanf("%d%d",&n,&m);
    int cnt=0;
    for(int i=1;i<=n;++i)
      for(int j=1;j<=m;++j)
        scanf("%d",&b[i][j]),a[i][j]=i,p[++cnt]=P(i,j),f[i][j]=g[j][i]=0;
    for(int i=1;i<=n;++i)sort(a[i]+1,a[i]+m+1,[&](int x,int y){
      return b[i][x]>b[i][y];
    });
    sort(p+1,p+cnt+1,[&](P x,P y){
      return b[x.first][x.second]<b[y.first][y.second];
    });
    for(int i=1;i<=m;++i)g[i][p[i].first]=p[i].second,f[p[i].first][p[i].second]=1;
    for(int i=1;i<=m;++i)
      for(int j=1;j<=n;++j)if(!g[i][j]){
        for(int k=1;k<=m;++k)if(!f[j][k]){
          f[j][k]=1,g[i][j]=k;break;
        }
      }
    for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)printf("%d%c",b[i][g[j][i]]," \n"[j==m]);
//    auto get=[&](int x){
//      while(vis[x][b[x][c[x]]])++c[x];
//      return a[x][c[x]];
//    };
//    for(int i=1;i<=m;++i){
//      int x=p[i].first,y=p[i].second;
//      for(int j=1;j<x;++j)ans[i][j]=get(j);
//      ans[i][x]=y;vis[x][y]=1;
//      for(int j=x+1;j<=n;++j)ans[i][j]=get(j);
//    }
//    for(int i=1;i<=n;++i)
//      for(int j=1;j<=m;++j)
//        printf("%d%c",b[i][ans[j][i]]," \n"[j==m]);
  }
  return 0;
}