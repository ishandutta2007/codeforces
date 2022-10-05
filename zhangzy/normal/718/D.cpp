#include<bits/stdc++.h>
#define mii map<int,int>
using namespace std;
int n, cnt, u, v, deg[101000];
map<mii,int>mp;
mii f[101000], ans, G[101000];

int dfs(int x,int fff){
  if (f[x].count(fff)) return f[x][fff];
  mii v;
  for (auto y:G[x])
    if (y.first!=fff)
      ++v[dfs(y.first,x)];
  if (!mp.count(v)) mp[v]=++cnt;
  return f[x][fff]=mp[v];
}

int main(){
  cin>>n;
  for (int i=n;--i;){
    cin>>u>>v; ++deg[u],++deg[v];
    G[u][v],G[v][u];
  }
  for (int i=1;i<=n;++i)
    if (deg[i]<4)
      ans[dfs(i,0)]=1;
  cout<<ans.size();
}