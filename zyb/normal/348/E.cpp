#include<stdio.h>
#include<cstring>
#include<vector>
#define N 100005
#define K 16
#define M 200005
using namespace std;
vector<int>v[N],val[N];
int deep[N],sum[N],i,j,m,n,p,k,f[N],g[N],F[N],G[N],fa[N],Fa[N][K+1];
int z,x,y,a[N];
inline void add(int x,int y,int z)  {
     v[x].push_back(y);
     val[x].push_back(z);
}
inline void dfs(int x) {
    int i;
    if (a[x]) f[x]=F[x]=0,g[x]=G[x]=x;
    for (i=1;i<=K;++i) Fa[x][i]=Fa[Fa[x][i-1]][i-1];
    for (i=0;i<(int)v[x].size();i++)
    if (fa[x]!=v[x][i]) {
              int p=v[x][i];
              fa[p]=Fa[p][0]=x; deep[p]=deep[x]+1;
              dfs(p);
              if (f[p]>=0&&f[p]+val[x][i]>f[x]) f[x]=f[p]+val[x][i],g[x]=g[p];
              else if (f[p]>=0&&f[p]+val[x][i]==f[x]) g[x]=x;
        }
}
inline int get(int x,int y) {
      if (deep[x]<deep[y]) swap(x,y);
      int i,k;
      for (i=K,k=deep[x]-deep[y];i>=0;i--)
      if (k&(1<<i)) x=Fa[x][i];
      if (x==y) return x;
      for (i=K;i>=0;i--)
      if (Fa[x][i]!=Fa[y][i]) x=Fa[x][i],y=Fa[y][i];
      return Fa[x][0];
}
inline void cheat(int x) {
     int i;
     for (i=0;i<(int)v[x].size();i++)
       if (fa[x]!=v[x][i]) {
         cheat(v[x][i]);
         sum[x]+=sum[v[x][i]];
       }
}
inline void Dfs(int x) {
    int sumx=-1,sumy=-1; int i;
    for (i=0;i<(int)v[x].size();i++)
      if (fa[x]!=v[x][i]) {
          int p=v[x][i];
          if (F[x]>=0) F[p]=F[x]+val[x][i],G[p]=G[x];
          if (sumx>=0) {
              if(sumx+val[x][i]>F[p]) F[p]=sumx+val[x][i],G[p]=sumy;
              else if (sumx+val[x][i]==F[p]) G[p]=x;
          }
          if (f[p]>=0) {
              if (f[p]+val[x][i]>sumx) sumx=f[p]+val[x][i],sumy=g[p];
              else if (f[p]+val[x][i]==sumx) sumy=x;
          }
      }
      sumx=sumy=-1;
        for (i=(int)v[x].size()-1;i>=0;i--)
      if (fa[x]!=v[x][i]) {
          int p=v[x][i];
          if (sumx>=0) {
              if(sumx+val[x][i]>F[p]) F[p]=sumx+val[x][i],G[p]=sumy;
              else if (sumx+val[x][i]==F[p]) G[p]=x;
          }
          if (f[p]>=0) {
              if (f[p]+val[x][i]>sumx) sumx=f[p]+val[x][i],sumy=g[p];
              else if (f[p]+val[x][i]==sumx) sumy=x;
          }
      }
        for (i=0;i<(int)v[x].size();i++)
          if (fa[x]!=v[x][i]) Dfs(v[x][i]);
}
int main() {
      scanf("%d%d",&n,&m);
      for (i=1;i<=m;i++) scanf("%d",&x),a[x]++;
      for (i=1;i<n;i++) {
         scanf("%d%d%d",&x,&y,&z);
         add(x,y,z); add(y,x,z);
      }
      memset(f,-1,sizeof(f));
      memset(F,-1,sizeof(F));
      dfs(1);
      Dfs(1);
      for (i=1;i<=n;i++) 
      if (a[i]) {
        if (f[i]>F[i]) {  
             sum[i]++; sum[g[i]]++;
             int lca=get(i,g[i]);
             sum[lca]--;
             sum[fa[lca]]--;
       }
       else if (f[i]<F[i]) {
             sum[i]++; sum[G[i]]++;
             int lca=get(i,G[i]);
             sum[lca]--;
             sum[fa[lca]]--;
       }
      }
      cheat(1); int ans=0,Ans=0;
      for (i=1;i<=n;i++)
      if (!a[i]) {
        if (sum[i]>ans) ans=sum[i],Ans=1;
        else if (sum[i]==ans) Ans++;
      }
      printf("%d %d\n",ans,Ans);
}