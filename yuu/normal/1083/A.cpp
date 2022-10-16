#include <bits/stdc++.h>
using namespace std;
int n;
int w[300001];
long long f[300001];
int e[300001];
vector <pair <int, int>> g[300001];
set <pair <long long, int>> s[300001];
deque <int> order;
bool done[300001];
void cal(int u){
	if(s[u].empty()) f[u]=0;
	else f[u]=max(0LL, s[u].rbegin()->first);
	f[u]+=w[u];
}
void attach(int u, int v){
	s[v].insert({f[u]-e[u], u});
}
void detach(int u, int v){
	s[v].erase({f[u]-e[u], u});
}
void dfs(int u){
	done[u]=1;
	order.push_back(u);
	for(auto v: g[u]) if(!done[v.first]){
		e[v.first]=v.second;
		dfs(v.first);
		attach(v.first, u);
		order.push_back(u);
	}
	cal(u);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	for(int i=1; i<=n; i++) cin>>w[i];
	for(int i=1, u, v, c; i<n; i++){
		cin>>u>>v>>c;
		g[u].push_back({v, c});
		g[v].push_back({u, c});
	}
	dfs(1);
	order.pop_front();
	long long ans=f[1];
	int root=1;
	for(int u: order){
		detach(u, root);
		e[root]=e[u];
		cal(root);
		attach(root, u);
		cal(u);
		root=u;
		ans=max(ans, f[root]);
	}
	cout<<ans<<'\n';
}