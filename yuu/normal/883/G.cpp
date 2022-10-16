#include <bits/stdc++.h>
using namespace std;
int n, m, s;
vector <int> g[300001];
vector <int> d[300001];
set <pair <int, int>> a;
int t[300001];
int u[300001];
int v[300001];
bool done[300001];
int cnt=0;
void dfs(int u){
	done[u]=1;
	cnt++;
	for(int v: g[u]) if(!done[v]){
		dfs(v);
	}
	for(int v: d[u]) if(!done[v]){
		a.insert({u, v});
		dfs(v);
	}
}
void dfs2(int u){
	done[u]=1;
	cnt++;
	for(int v: g[u]) if(!done[v]){
		dfs2(v);
	}
	for(int v: d[u]) if(!done[v]){
		a.insert({v, u});
		// dfs(v);
	}
}
void do_max(){
	dfs(s);
	cout<<cnt<<'\n';
	for(int i=1; i<=m; i++) if(t[i]==2){
		if(a.find({u[i], v[i]})!=a.end()) cout<<'+'; else cout<<'-';
	}
	cout<<'\n';
}
void do_min(){
	for(int i=1; i<=n; i++) done[i]=0;
	// for(int i=1; i<=n; i++) d[i].clear();
	a.clear();
	cnt=0;
	dfs2(s);
	cout<<cnt<<'\n';
	for(int i=1; i<=m; i++) if(t[i]==2){
		if(a.find({u[i], v[i]})!=a.end()) cout<<'+'; else cout<<'-';
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m>>s;
	for(int i=1; i<=m; i++) cin>>t[i]>>u[i]>>v[i];
	for(int i=1; i<=m; i++){
		if(t[i]==1){
		 g[u[i]].push_back(v[i]);
		}
		else{
		 d[u[i]].push_back(v[i]);
		 d[v[i]].push_back(u[i]);
		}
	}
	do_max();
	do_min();
}