#include <bits/stdc++.h>
using namespace std;
int n, m, q;
int r[300001];
int ans[300001];
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
	r[v]=u;
	ans[u]=max(max(ans[u], ans[v]), (ans[u]+1)/2+(ans[v]+1)/2+1);
}
vector <int> g[300001];
int f[300001];
int done[300001];
int cnt=0;
int bfs(int u){
	queue <int> q;
	cnt++;
	done[u]=cnt;
	q.push(u);
	f[u]=0;
	while(!q.empty()){
		u=q.front();
		q.pop();
		for(int v: g[u]) if(done[v]!=cnt){
			done[v]=cnt;
			f[v]=f[u]+1;
			q.push(v);
		}
	}
	return u;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m>>q;
	for(int i=1; i<=n; i++) r[i]=-1;
	for(int i=1, a, b; i<=m; i++){
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
		unite(a, b);
	}
	for(int i=1; i<=n; i++) if(i==root(i)) ans[i]=f[bfs(bfs(i))];
	for(int i=1, t, u, v; i<=q; i++){
		cin>>t>>u;
		if(t==1) cout<<ans[root(u)]<<'\n';
		else{
			cin>>v;
			unite(u, v);
		}
	}
	
}