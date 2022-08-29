#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 1e6 + 7, M = 2007;
const int inf = 1e9;
int ehd[N], ev[N], enx[N], eid = 1;
int ew[N];
void eadd(int u, int v, int w) {
	++eid, enx[eid] = ehd[u], ev[eid] = v, ew[eid] = w, ehd[u] = eid;
}
void add(int u, int v, int w) {
	eadd(u, v, w), eadd(v, u, 0);
}
int dis[N], cur[N], s, t, top;
bool bfs() {
	L(i, 1, top) dis[i] = inf, cur[i] = ehd[i];
	queue <int> q;
	dis[s] = 0, q.push(s);
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		for(int i = ehd[u]; i; i = enx[i]) if(ew[i] && dis[ev[i]] > dis[u] + 1) 
			dis[ev[i]] = dis[u] + 1, q.push(ev[i]);
	}
	return dis[t] < inf;
}
int dfs(int x, int flow) {
	if(x == t) return flow;
	int F = flow;
	for(int i = cur[x]; i; i = cur[x] = enx[i]) if(ew[i] && dis[ev[i]] == dis[x] + 1) {
		int sF = dfs(ev[i], min(ew[i], F));
		ew[i] -= sF, ew[i ^ 1] += sF, F -= sF;
		if(!F) break;
	}
	return flow - F;
}
void dinic() {
	while(bfs()) dfs(s, inf);
}
int n, m, ns[N], v[N], A[N];
ll ans;
bool E[M][M]; // E[i][j] = true : a_i >= a_j
void Div(int L, int R, int sl, int sr) {
	if(sl > sr) return ;
	if(L == R) {
		L(i, sl, sr) ns[A[i]] = L;
		return;
	} 
	int mid = (L + R) >> 1, topo = sl - 1;
	eid = 1, top = sr - sl + 1, s = ++top, t = ++top;
	L(i, sl, sr) L(j, sl, sr) if(E[A[i]][A[j]]) add(i - sl + 1, j - sl + 1, inf);
	L(i, sl, sr) {
		int c = abs(mid + 1 - v[A[i]]) - abs(mid - v[A[i]]);
		if(c > 0) add(s, i - sl + 1, c);
		else add(i - sl + 1, t, - c);
	}
	dinic ();
	L(i, 1, sr - sl + 1) if(dis[i] < inf) swap(A[++topo], A[sl + i - 1]);
	L(i, 1, top) ehd[i] = 0; 
	top = 0, Div(L, mid, sl, topo), Div(mid + 1, R, topo + 1, sr);
}
int main () {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	L(i, 1, n) cin >> v[i];
	L(i, 1, m) {
		int u, v;
		cin >> u >> v;
		E[v][u] = true;
	}
	L(i, 1, n) A[i] = i;
	Div(0, inf, 1, n);
	L(i, 1, n) cout << ns[i] << ' ';
	cout << '\n';
	return 0;
}