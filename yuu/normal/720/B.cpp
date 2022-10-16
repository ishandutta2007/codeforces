#include <bits/stdc++.h>
using namespace std;
int n, m;
vector <pair <int, int>> g[10001];
vector <bool> used;
vector <pair <int, int>> s;
int t;
int done[10001];
vector <int> c;
vector <vector <int>> cc;
void dfs(int u, int e){
	t++;
	done[u]=t;
	for(auto v: g[u]) if(!done[v.first]){
		s.push_back(make_pair(u, e));
		dfs(v.first, v.second);
		if((!s.empty())&&(s.back().second==e)) s.pop_back();
	}
	else if(e!=v.second) if(done[v.first]<done[u]){
		s.push_back(make_pair(u, e));
		cc.push_back(vector <int>());
		cc.back().push_back(c[v.second]);
		used[v.second]=1;
		while(s.back().first!=v.first){
			used[s.back().second]=1;
			cc.back().push_back(c[s.back().second]);
			s.pop_back();
		}
	}
}
vector <int> r;
vector <int> f;
int root(int u){
	if(r[u]<0) return u;
	return r[u]=root(r[u]);
}
void unite(int u, int v){
	u=root(u);
	v=root(v);
	f[u]++;
	if(u==v) return;
	if(r[u]>r[v]) swap(u, v);
	r[u]+=r[v];
	f[u]+=f[v];
	r[v]=u;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	used.resize(m+1, 0);
	r.resize(m+1, -1);
	f.resize(m+1, 0);
	c.resize(m+1, 0);
	f[0]=1;
	for(int i=1, u, v; i<=m; i++){
		cin>>u>>v>>c[i];
		g[u].push_back(make_pair(v, i));
		g[v].push_back(make_pair(u, i));
	}
	dfs(1, 0);
	for(int i=1; i<=m; i++) if(!used[i]) unite(0, c[i]);
	for(auto &x: cc) for(int i=1; i<x.size(); i++)	unite(x[i], x[i-1]);
	int ans=-1;
	for(int i=0; i<=m; i++) if(i==root(i)){
		if(f[i]>=-r[i]) ans+=-r[i];
		else ans+=-r[i]-1;
	}
	cout<<ans<<'\n';
}