#include<bits/stdc++.h>
using namespace std;

int n, m, to[3003000], vis[3003000];
vector<int>G[1001000], vec;
struct edge{
  int u, v, tp;
};
vector<edge>ans;

void dfs(int x){
  while (G[x].size()){
    int id=G[x].back(); G[x].pop_back();
    if (vis[id]) continue;
    vis[id]=vis[id^1]=1;
    dfs(to[id]);
    ans.push_back({x,to[id],(id/2>m? 1: 0)});
  }
}

int main(){
  cin>>n>>m;
  for (int i=1;i<=m;++i){
    int u, v;
    scanf("%d%d",&u,&v);
    to[i<<1|0]=u;
    G[v].push_back(i<<1|0);
    to[i<<1|1]=v;
    G[u].push_back(i<<1|1);
  }
  for (int i=1;i<=n;++i)
    if (G[i].size()&1)
      vec.push_back(i);
  int tm=m;
  for (int i=0;i<vec.size();i+=2){
    int u=vec[i], v=vec[i+1]; ++tm;
    to[tm<<1|0]=u;
    G[v].push_back(tm<<1|0);
    to[tm<<1|1]=v;
    G[u].push_back(tm<<1|1);
  }
  vector<edge>t;
  for (int i=1;i<=m;++i)
    if (!vis[i<<1]){
      ans.clear();
      dfs(to[i<<1]);
      reverse(ans.begin(),ans.end());
      bool las=0, now;
      for (int i=0;i<ans.size();++i){
	if (ans[(i+1)%ans.size()].tp){
	  now=1;
	}else{
	  now=!las;
	}
	if (ans[i].tp) now=0;
	if (now) t.push_back(ans[i]);
	las=now;
      }
    }
  cout<<t.size()<<endl;
  for (auto o:t) printf("%d %d\n",o.u,o.v);
}