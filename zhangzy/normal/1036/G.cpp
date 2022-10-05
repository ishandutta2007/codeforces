#include<bits/stdc++.h>
using namespace std;

const int N=1.1e6;
int n, m, vis[N], ns[N], nt[N], a[22];
vector<int>G[N], s, t;

void dfs(int x){
  vis[x]=1;
  for (auto y:G[x])
    if (!vis[y]) dfs(y);
}

int main(){
  cin>>n>>m;
  for (int x,y;m--;){
    scanf("%d%d",&x,&y);
    G[x].push_back(y);
    nt[x]=ns[y]=1;
  }
  for (int i=1;i<=n;++i){
    if (!ns[i]) s.push_back(i);
    if (!nt[i]) t.push_back(i); 
  }
  int sz=s.size();
  for (int i=0;i<sz;++i){
    memset(vis,0,sizeof vis);
    dfs(s[i]);
    for (int j=0;j<sz;++j)
      a[i]|=vis[t[j]]<<j;
  }
  for (int i=1;i<(1<<sz)-1;++i){
    int now=0;
    for (int j=0;j<sz;++j)
      if (i>>j&1) now|=a[j];
    if (__builtin_popcount(now)<=__builtin_popcount(i))
      return puts("NO"), 0;
  }
  puts("YES");
}