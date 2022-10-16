#include <bits/stdc++.h>
using namespace std;
int n, m, s;	
bool done[200001];
long long w[200001];
int r[200001];
int p[200001];
int num[200001];
int low[200001];
bool good[200001];
vector <int> g[200001];
vector <int> h[200001];
int cnt=0;
void dfs(int u){
	done[u]=1;
	cnt++;
	num[u]=low[u]=cnt;
	for(int v: g[u]) if(!done[v]){
		p[v]=u;
		dfs(v);
		low[u]=min(low[u], low[v]);
	}
	else if(v!=p[u]) low[u]=min(low[u], num[v]);
}
long long ans=0;
long long f[200001];
void visit(int u){
	done[u]=1;
	good[u]=r[u]>1;
	for(int v: h[u]) if(!done[v]){
		visit(v);
		f[u]+=f[v];
		good[u]=good[u]||good[v];
	}
	if(good[u]) f[u]+=w[u];
}
void visit2(int u, long long now=0){
	done[u]=1;
	if(!good[u]) now+=w[u];
	ans=max(ans, now+f[s]);
	for(int v: h[u]) if(!done[v]) visit2(v, now);
}
int root(int u){
	if(r[u]<0) return u;
	return r[u]=root(r[u]);
}
void unite(int u, int v){
	u=root(u);
	v=root(v);
	if(u==v) return;
	if(r[u]>r[v]) swap(u, v);
	r[u]+=r[v];
	w[u]+=w[v];
	r[v]=u;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	for(int i=1; i<=n; i++) cin>>w[i];
	for(int i=0, u, v; i<m; i++){
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	cin>>s;
	dfs(1);
	for(int i=1; i<=n; i++) r[i]=-1;
	for(int i=1; i<=n; i++) for(int j: g[i]) if(p[j]==i) if(low[j]<=num[i]) unite(i, j);
	for(int i=1; i<=n; i++) for(int j: g[i]) if(p[j]==i){
		if(low[j]>num[i]){
			h[root(i)].push_back(root(j));
			h[root(j)].push_back(root(i));
		}
	}
	for(int i=1; i<=n; i++) done[i]=0;
	s=root(s);
	for(int i=1; i<=n; i++) r[i]=-r[i];
	visit(s);
	for(int i=1; i<=n; i++) done[i]=0;
	visit2(s);
	cout<<ans<<'\n';
}