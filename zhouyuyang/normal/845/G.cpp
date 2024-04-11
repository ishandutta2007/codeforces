#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> PLL;
LL xr[100000]={0},vs[100000]={0};
set<LL,greater<LL>> b;
vector<PLL> g[100000];
void dfs(LL v){
  vs[v]=1;
  for(PLL E :g[v]){
    auto u=E.first,w=E.second;
    if(vs[u]){
      LL W=xr[u]^xr[v]^w;
      for(LL u:b)W=min(W,W^u);
      if(W)b.insert(W);
    }else{
      xr[u]=xr[v]^w;
      dfs(u);
    }
  }
}
int main(){
  LL n,m,x,y,w;
  scanf("%lld%lld",&n,&m);
  while(m--){
    scanf("%lld%lld%lld",&x,&y,&w);
    --x,--y;
    g[x].push_back({y,w}),g[y].push_back({x,w});
  }
  dfs(0);
  for(LL u:b)xr[n-1]=min(xr[n-1],xr[n-1]^u);
  printf("%lld",xr[n-1]);
}