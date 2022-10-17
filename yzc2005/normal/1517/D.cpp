#include <bits/stdc++.h>
using namespace std;
inline int read(){
	int num=0; char g=getchar(); while(g<48||57<g) g=getchar();
	while(47<g&&g<58) num=(num<<1)+(num<<3)+g-48,g=getchar(); return num;
}
const int N=505,inf=0x3f3f3f3f;
int n,m,k,a[N][N],b[N][N],ans[N][N],dp[N][N],L[N*N];
struct node{
  int x,y;
}f[N*N],g[N*N];
inline void down(int &x,int y){x>y?x=y:0;}
int main(){
  scanf("%d%d%d",&n,&m,&k);
  if(k&1){
    memset(ans,-1,sizeof ans);
  }else{
    k/=2;memset(ans,0x3f,sizeof ans),memset(dp,0x3f,sizeof dp);
    for(int i=1;i<=n;++i)for(int j=1;j<m;++j)a[i][j]=read();
    for(int i=1;i<n;++i)for(int j=1;j<=m;++j)b[i][j]=read();
    for(int i=1;i<=n;++i)for(int j=1;j<=m;++j){
      int k1=0,k2=0;g[++k2]=(node){i,j};dp[i][j]=0;
      int res=inf;
      for(int t=1;t<=k+1;++t){
        k1=k2,k2=0;
        for(int i=1;i<=k1;++i)f[i]=g[i],L[i]=dp[g[i].x][g[i].y],dp[g[i].x][g[i].y]=inf;
        for(int i=1;i<=k1;++i){
          int x=f[i].x,y=f[i].y,len=L[i];
          if(t==k+1)down(res,len*2);
          else{
            if(x>1){
            if(dp[x-1][y]==inf)g[++k2]=(node){x-1,y};
            down(dp[x-1][y],len+b[x-1][y]);
            }
            if(x<n){
            if(dp[x+1][y]==inf)g[++k2]=(node){x+1,y};
            down(dp[x+1][y],len+b[x][y]);
            }
            if(y>1){
            if(dp[x][y-1]==inf)g[++k2]=(node){x,y-1};
            down(dp[x][y-1],len+a[x][y-1]);
            }
            if(y<m){
            if(dp[x][y+1]==inf)g[++k2]=(node){x,y+1};
            down(dp[x][y+1],len+a[x][y]);
            }
          }
        }
      }
      ans[i][j]=res;
    }
  }
  for(int i=1;i<=n;++i)
    for(int j=1;j<=m;++j)
      printf("%d%c",ans[i][j]," \n"[j==m]);
  return 0;
}