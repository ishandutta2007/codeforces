#include <bits/stdc++.h>
using namespace std;
int n, m;
int cnt;
int first[200001];
int last[200001];
int f[200001][20];
int h[200001];
vector <int> g[200001];
void dfs(int u){
	cnt++;
	for(int i=0; f[f[u][i]][i]; i++) f[u][i+1]=f[f[u][i]][i];
	first[u]=cnt;
	for(int v: g[u]){
		h[v]=h[u]+1;
		f[v][0]=u;
		dfs(v);
	}
	last[u]=cnt;
}
int lca(int u, int v){
	if(h[u]<h[v]) swap(u, v);
	for(int i=__lg(h[u]); i>=0; i--) if(h[f[u][i]]>=h[v]) u=f[u][i];
	if(u==v) return u;
	for(int i=__lg(h[u]); i>=0; i--) if(f[u][i]!=f[v][i]){
		u=f[u][i];
		v=f[v][i];
	}
	return f[u][0];
}
int climb(int u, int v){
	for(int i=__lg(h[u]); i>=0; i--) if(h[f[u][i]]>h[v]) u=f[u][i];
	return u;
}
vector <pair <pair <int, int>, long long>> edges[200001];
long long ft[200001];
void update(int u, int x){
	for(; u<=n; u+=u&-u) ft[u]+=x;
}
long long get(int u){
	int res=0;
	for(; u>0; u-=u&-u) res+=ft[u];
	return res;
}
long long dp[200001];
long long sum[200001];
void make(int u){
	for(int v: g[u]) make(v);
	for(int v: g[u]) sum[u]+=dp[v];
	dp[u]=sum[u];
	for(auto x: edges[u]){
		if(x.first.second==u) swap(x.first.first, x.first.second);
		x.second+=sum[u]-dp[climb(x.first.second, u)];
		if(x.first.first!=u) x.second+=-dp[climb(x.first.first, u)];
		dp[u]=max(dp[u], x.second+((x.first.first==u)?0:sum[x.first.first])+get(first[x.first.first])+sum[x.first.second]+get(first[x.first.second]));
	}
	for(int v: g[u]){
		update(first[v], sum[u]-dp[v]);
		update(last[v]+1, -(sum[u]-dp[v]));
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m;
	for(int i=2, p; i<=n; i++){
		cin>>p;
		g[p].push_back(i);
	}
	h[1]=1;
	dfs(1);
	for(int i=1, x, y, c; i<=m; i++){
		cin>>x>>y>>c;
		edges[lca(x, y)].push_back({{x, y}, c});	
	}
	make(1);
	cout<<dp[1]<<'\n';
}