#include <bits/stdc++.h>
#define N 11111
using namespace std;
struct dinic{
  struct TEdge{
    int v;
    int f;
    int c;
    int rev;
    TEdge(int x, int y, int z){
      v = x;
      f = 0;
      c = y;
      rev = z;
    }
  };
 
  int start[N];
  int level[N];
  vector < int > g[N];
  vector < TEdge > edges;
  void addEdge(int u, int v, int c){
 //   cout << u << " " << v << endl;
    edges.emplace_back(v, c, edges.size() + 1);
    edges.emplace_back(u, 0, edges.size() - 1);
    g[u].push_back(edges.size() - 2);
    g[v].push_back(edges.size() - 1);
  }
	
  bool bfs(int S, int T){
    queue < int > que;
    que.push(S);
 
    fill(level, level + N, -1);
    level[S] = 0;
 
    while(que.size()){
      int x = que.front();
      que.pop();
 
      for(int id : g[x]){
        TEdge e = edges[id];
        if(e.f == e.c || level[e.v] != -1) continue;
        level[e.v] = level[x] + 1;
        que.push(e.v);
      }
    }
    
    if(level[T] == -1) return false;
    return true;
  } 
 
  int dfs(int u, int flow, int T){
    if(u == T) return flow;
    for(; start[u] < g[u].size(); start[u]++){
      TEdge &e = edges[g[u][start[u]]];
      if(level[e.v] != level[u] + 1 || e.f == e.c) continue;
      int p = dfs(e.v, min(flow, e.c - e.f), T);
      if(p) {
        e.f += p;
        edges[e.rev].f -= p;
        return p;
      }
    }
    return 0;
  }
 
  int maxFlow(int S, int T){
    int ans = 0;
    while(bfs(S, T)){
      int x;
      memset(start, 0, sizeof start);
      while(x = dfs(S, 999999, T)){
        ans += x;
      }
    }
    return ans;
  }
	vector <pair <int, int>> getflow(int low, int high){
		vector <pair <int, int>> res;
		for(int i=low; i<=high; i++) for(auto e: g[i]) if(edges[e].f){
			res.push_back(make_pair(i, edges[e].v));
		}
		return res;
	}
};
int n, m;
int u[5001];
int v[5001];
bool check(int lim, bool output=0){
	dinic mf;
	int source=0, sink=n+m+1;
	for(int i=1; i<=n; i++) mf.addEdge(0, i, lim);
	for(int i=1; i<=m; i++) mf.addEdge(u[i], i+n, 1);
	for(int i=1; i<=m; i++) mf.addEdge(v[i], i+n, 1);
	for(int i=1; i<=m; i++) mf.addEdge(i+n, sink, 1);
	auto res=mf.maxFlow(source, sink)==m;
	if(output){
		cout<<lim<<'\n';
		auto e=mf.getflow(1, n);
		for(auto &x: e){
			x.second-=n;
			if(x.second>m||x.second<1) continue;
			x.second=x.first^u[x.second]^v[x.second];
			cout<<x.first<<' '<<x.second<<'\n';
		}
	}
	
	return res;
}
int main(){
	cin>>n>>m;
	for(int i=1; i<=m; i++) cin>>u[i]>>v[i];
	int low=0, high=n, mid=0, ans=0;
	while(low<=high){
		mid=(low+high)/2;
		if(check(mid)){
			ans=mid;
			high=mid-1;
		}
		else low=mid+1;;
	}
	check(ans, 1);
	
}