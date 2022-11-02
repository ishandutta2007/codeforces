#include<bits/stdc++.h>
using namespace std;
#define ll long long

const ll inf = 1e18;
const int maxn = 1e5+10;
struct Dinic { // dinicspfa
	struct Edge { int v, rev; ll cap, cot; };
	vector<Edge> G[maxn];
	ll dis[maxn];
	int cur[maxn], vis[maxn], n, sp, tp;
	void init(int nn) {
		n = nn;
		for (int i = 1; i <= n; i++) G[i].clear();
	}
	void add(int u, int v, ll cap, ll cot) {
		// cout<<"add:"<<u<<" "<<v<<" "<<cap<<" "<<cot<<endl;
		G[u].push_back({ v, int(G[v].size()), cap, cot });
		G[v].push_back({ u, int(G[u].size()) - 1, 0, -cot });
	}
	int bfs() {
		queue<int> q;
		for (int i = 1; i <= n; i++) dis[i] = inf, vis[i] = 0;
		dis[sp] = 0, q.push(sp), vis[sp] = 1;
		while (!q.empty()) {
			int u = q.front(); q.pop(); vis[u] = 0;
			for (Edge &e : G[u]) {
				if (e.cap && dis[e.v] > dis[u] + e.cot) {
					dis[e.v] = dis[u] + e.cot;
					if (!vis[e.v]) q.push(e.v), vis[e.v] = 1;
				}
			}
		} return dis[tp] != inf;
	}
	ll dfs(int u, ll flow) {
		if (u == tp || !flow) return flow;
		ll ret = 0, tmp; vis[u] = 1;
		for (int i = cur[u]; i < G[u].size(); i++) {
			Edge &e = G[u][i];
			if (!vis[e.v] && dis[e.v] == dis[u] + e.cot 
			&& (tmp = dfs(e.v, min(e.cap, flow - ret)))) {
				ret += tmp, e.cap -= tmp, G[e.v][e.rev].cap += tmp;
				if (ret == flow) { vis[u] = 0; return ret; }
			}
		}
		if (!ret) vis[u] = 1;
		return ret;
	}
	pair<ll, ll> solve(int s, int t) {
		sp = s, tp = t;
		ll mf = 0, mc = 0;
		while (bfs()) {
			for (int i = 1; i <= n; i++) cur[i] = 0;
			ll tmp = dfs(sp, inf);
			mf += tmp, mc += tmp * dis[tp];
		}
		return { mf, mc };
	}
} dinic;

int ans[110][110];
int out[110];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int n,m;cin>>n>>m;

	dinic.init(3000);
	for(int i=1;i<=m;i++){
		int a,b;cin>>a>>b;
		ans[a][b]=1;
		out[a]++;
	}

	int s=2600,t=2601;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(ans[i][j]||ans[j][i]) continue;
			int e=i*50+j;
			dinic.add(s,e,1,0);
			dinic.add(e,i,1,0);
			dinic.add(e,j,1,0);
		}
	}
	for(int i=1;i<=n;i++) {
		for(int j=out[i];j<n-1;j++){
			dinic.add(i,t,1,j);
		}
	}
	dinic.solve(s,t);

	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(ans[i][j]||ans[j][i]) continue;
			int e=i*50+j;
			for(auto &it:dinic.G[e]){
				if(it.v==i&&it.cap) ans[j][i]=1;
				if(it.v==j&&it.cap) ans[i][j]=1;
			}
		}
	}

	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<ans[i][j];
		}
		cout<<endl;
	}

}