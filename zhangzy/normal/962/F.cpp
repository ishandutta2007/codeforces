#include<bits/stdc++.h>
using namespace std;

int n, m, tp, ui[101000], vi[101000];
set<int>ans, in, edg;
struct E{
  int fr, to, id;
}st[202000];
vector<E>G[101000];

int dfn[101000], dft, low[101000], used[101000];

void dfs(int x,int fff){
  dfn[x]=low[x]=++dft;
  for (auto y:G[x]){
    if (!dfn[y.to]){
      st[++tp]=y;
      dfs(y.to,x); low[x]=min(low[x],low[y.to]);
    }else{
      if (!used[y.id]){
        st[++tp]=y;
        low[x]=min(low[x],dfn[y.to]);
      }
    }
  }
    
  if (low[x]==dfn[fff]){
    in.clear(); edg.clear();
    for (;;){
      edg.insert(st[tp].id);
      if (st[tp--].fr==fff) break;
    }
    for (auto o:edg){
      in.insert(ui[o]), in.insert(vi[o]);
      used[o]=1;
    }
    if (in.size()==edg.size()){
      for (auto o:edg)
        ans.insert(o);
    }
  }
}

int main(){
  cin>>n>>m; int u, v;
  for (int i=1;i<=m;++i){
    cin>>u>>v; tie(ui[i],vi[i])=tie(u,v);
    G[u].push_back((E){u,v,i});
    G[v].push_back((E){v,u,i});
  }
  for (int i=1;i<=n;++i)
    if (!dfn[i]) dfs(i,0);
  cout<<ans.size()<<endl;
  for (auto o:ans) printf("%d ",o);
}