#include<bits/stdc++.h>
using namespace std;
#define ll long long

#include<bits/stdc++.h>
using namespace std;
#define ll long long

const ll inf=1e18;
const int maxn=1e5+10;
struct Dinic {
	struct Edge { int v, rev; ll cap; };
	vector<Edge> G[maxn];
	int dis[maxn], cur[maxn], n, sp, tp;
	void init(int nn) {
		n = nn;
		for (int i = 1; i <= n; i++) G[i].clear();
	}
	// add(u, v, w, w)
	void add(int u, int v, ll cap, ll rcap = 0) {
		G[u].push_back({ v, int(G[v].size()), cap });
		G[v].push_back({ u, int(G[u].size()) - 1, rcap });
	}
	int bfs() {
		queue<int> q;
		for (int i = 1; i <= n; i++) dis[i] = 0;
		dis[sp] = 1, q.push(sp);
		while (!q.empty()) {
			int u = q.front(); q.pop();
			for (Edge &e : G[u]) {
				if (e.cap && !dis[e.v]) {
					dis[e.v] = dis[u] + 1;
					if (e.v == tp) return 1;
					q.push(e.v);
				}
			}
		}
		return 0;
	}
	ll dfs(int u, ll flow) {
		if (u == tp || !flow) return flow;
		ll ret = 0, tmp;
		for (int &i = cur[u]; i < int(G[u].size()); i++) {
			Edge &e = G[u][i];
			if (dis[e.v] == dis[u] + 1 && (tmp = dfs(e.v, min(e.cap, flow - ret)))) {
				e.cap -= tmp, G[e.v][e.rev].cap += tmp, ret += tmp;
				if (ret == flow) return ret;
			}
		}
		if (!ret) dis[u] = 0;
		return ret;
	}
	ll solve(int s, int t) {
		sp = s, tp = t;
		ll ret = 0;
		while (bfs()) {
			for (int i = 1; i <= n; i++) cur[i] = 0;
			ret += dfs(sp, inf);
		}
		return ret;
	}
} dinic;

int main(){
    int n;cin>>n;
    int a,b,c;cin>>a>>b>>c;
    int x,y,z;cin>>x>>y>>z;

    int ans2=min(a,y)+min(b,z)+min(c,x);

    dinic.init(8);
    int s=7,t=8;
    dinic.add(s,1,a);
    dinic.add(s,2,b);
    dinic.add(s,3,c);

    dinic.add(4,t,x);
    dinic.add(5,t,y);
    dinic.add(6,t,z);

    dinic.add(1,4,1e9);
    dinic.add(2,5,1e9);
    dinic.add(3,6,1e9);

    dinic.add(1,6,1e9);
    dinic.add(2,4,1e9);
    dinic.add(3,5,1e9);

    cout<<n-dinic.solve(s,t)<<" "<<ans2<<endl;
}