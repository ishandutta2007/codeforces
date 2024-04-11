#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
int n, m, k;
class edge{
public:
	int a, b;
} e[300001];
class query{
public:
	int t, x;
} q[500001];
bool bad[500001];
int r[500001];
int w[500001];
int p[500001];
int ver[500001];
int root(int u){
	if(r[u]<0) return u;
	return r[u]=root(r[u]);
}
vector <int> g[500001];
bool unite(int u, int v){
	u=root(u);
	v=root(v);
	if(u==v) return 0;
	if(r[u]>r[v]) swap(u, v);
	r[u]+=r[v];
	r[v]=u;
	return 1;
}
int id[500001];
int first[500001];
int last[500001];
int ac[500001][21];
int current;
void dfs(int u){
	current++;
	ver[current]=u;
	first[u]=current;
	for(int i=0; ac[ac[u][i]][i]; i++) ac[u][i+1]=ac[ac[u][i]][i];
	for(int v: g[u]){
		// cerr<<u<<' '<<v<<'\n';
		ac[v][0]=u;
		dfs(v);
	}
	last[u]=current;
}
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
int ft[500001];
void update(int u, int x){
	for(; u<=400000; u+=u&-u) ft[u]+=x;
}
int get(int u){
	int res=0;
	for(; u>0; u-=u&-u) res+=ft[u];
	return res;
}
int mark(int node){
	int add=rng();
	update(first[node], add);
	update(last[node]+1, -add);
}
int findRoot(int u){
	int id=get(first[u]);
	for(int i=20; i>=0; i--) if(get(first[ac[u][i]])==id) u=ac[u][i];
	return u;
}
bool done[500001];
int currentRoot[500001];
vector <int> values[500001];
void makeTree(int u){
	mark(u);
	for(int i=first[u]; i<=last[u]; i++) if(ver[i]<=n){
		currentRoot[ver[i]]=u;
		if(!done[ver[i]]) values[u].push_back(w[ver[i]]);
	}
	sort(values[u].begin(), values[u].end());
}
int query(int u){
	int r=findRoot(u);
	while(!values[r].empty()){
		int val=values[r].back();
		values[r].pop_back();
		int from=id[val];
		if(done[from]) continue;
		if(currentRoot[from]!=r) continue;
		done[from]=1;
		return val;
	}
	return 0;
}
void solve(){
	cin>>n>>m>>k;
	for(int i=1; i<=n; i++) cin>>w[i];
	for(int i=1; i<=n; i++) id[w[i]]=i;
	for(int i=1; i<=m; i++) cin>>e[i].a>>e[i].b;
	for(int i=1; i<=k; i++){
		cin>>q[i].t>>q[i].x;
		if(q[i].t==2) bad[q[i].x]=1;
	}
	for(int i=1; i<=n; i++) r[i]=-1;
	for(int i=1; i<=m; i++) if(!bad[i]) unite(e[i].a, e[i].b);
	for(int i=1; i<=n; i++) if(i!=root(i)){
		p[i]=root(i);
		g[p[i]].push_back(i);
	}
	for(int i=k; i>=1; i--) if(q[i].t==2){
		int u=root(e[q[i].x].a);
		int v=root(e[q[i].x].b);
		if(u==v){
			q[i].x=0;///this query is useless, continue
			continue;
		}
		if(r[u]>r[v]) swap(u, v);
		r[u]+=r[v];
		r[v]=u;
		p[v]=u;
		g[u].push_back(v);
		q[i].x=v;//at this step, cut the subtree rooted at v out.
	}
	for(int u=1; u<=n; u++) if(p[u]==0){
		dfs(u);
		makeTree(u);
	}
	for(int i=1; i<=k; i++){
		if(q[i].t==1) cout<<query(q[i].x)<<'\n';
		else if(q[i].x) makeTree(q[i].x);
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t=1;
	// cin>>t;
	while(t--) solve();
}