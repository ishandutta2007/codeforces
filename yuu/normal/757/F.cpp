#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int n, m, s;
vector <pair <int, ll>> g[200001];
class cmp{
public:
	bool operator ()(pair <int, ll> a, pair <int, ll> b){
		return a.second>b.second;
	}
};
priority_queue <pair <int, ll>, vector <pair <int, ll> >, cmp> q;
ll d[200001];
void dij(){
	for(int i=1; i<=n; i++) d[i]=1LL<<60;
	d[s]=0;
	q.push({s, 0});
	pair <int, ll> p;
	while(!q.empty()){
		p=q.top();
		q.pop();
		if(p.second>d[p.first]) continue;
		for(pair <int, ll> v: g[p.first]){
			if(d[v.first]>v.second+d[p.first]){
				d[v.first]=v.second+d[p.first];
				q.push({v.first, d[v.first]});
			}
		}
	}
}
vector <int> h[200001];
vector <int> rh[200001];
bool done[200001];
int count[200001];
int vertex[200001];
int f[200001][21];
int height[200001];
int parent[200001];
int cnt;
void dfs(int u){
	done[u]=1;
	for(int v: h[u]) if(!done[v]) dfs(v);
	cnt--;
	vertex[cnt]=u;
}
int lca(int u, int v){
	if(height[u]<height[v]) swap(u, v);
	for(int i=__lg(height[u]); i>=0; i--)	if(height[f[u][i]]>=height[v]) u=f[u][i];
	if(u==v) return u;
	for(int i=__lg(height[u]); i>=0; i--) if(f[u][i]!=f[v][i]){
		u=f[u][i];
		v=f[v][i];
	}
	return f[u][0];
}
void attach(int c, int p){
	height[c]=height[p]+1;
	f[c][0]=p;
	for(int j=0; f[f[c][j]][j]; j++) f[c][j+1]=f[f[c][j]][j];
}
vector <int> children[200001];
int child_count[200001];
void dfs_tree(int u){
	child_count[u]=1;
	for(int v: children[u]){
		dfs_tree(v);
		child_count[u]+=child_count[v];
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m>>s;
	{
		int u, v;
		ll w;
		for(int i=1; i<=m; i++){
			cin>>u>>v>>w;
			g[u].push_back({v, w});
			g[v].push_back({u, w});
		}
	}
	dij();
	for(int u=1; u<=n; u++) if(d[u]!=(1LL<<60)) for(auto v: g[u]) if(d[v.first]==d[u]+v.second){
		h[u].push_back(v.first);
		rh[v.first].push_back(u);
	}
	cnt=n+1;
	dfs(s);
	height[s]=1;
	for(int i=cnt+1; i<=n; i++){
			parent[vertex[i]]=rh[vertex[i]][0];
			for(int v: rh[vertex[i]]) parent[vertex[i]]=lca(parent[vertex[i]], v);
			attach(vertex[i], parent[vertex[i]]);
	}
	for(int i=1; i<=n; i++) if(parent[i]) children[parent[i]].push_back(i);
	dfs_tree(s);
	int ans=0;
	for(int i=1; i<s; i++) ans=max(ans, child_count[i]);
	for(int i=s+1; i<=n; i++) ans=max(ans, child_count[i]);
	cout<<ans<<'\n';
}