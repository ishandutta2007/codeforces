#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, int> P;
const ll inf = 0x3f3f3f3f3f3f3f3f;
#define run(u) for(int i = head[u], v = e[i].to, w = e[i].val; i; i = e[i].nxt, v = e[i].to, w = e[i].val)

const int N = 200005, M = 400005;
int n, m, q, cnt = 1, k;
struct edge {
	int to, nxt, val;
} e[M]; int head[N];
void add(int u, int v, int w) {
	e[++cnt] = (edge) {v, head[u], w};
	head[u] = cnt;
}
priority_queue<P, vector<P>, greater<P> > qu;

ll dis[2][N];
int ind[M], id[N], l[N], r[N];
void dijkstra(int s, ll *dis) {
	dis[s] = 0;
	qu.push(P(0, s)); int tot = 0;
	while(!qu.empty()) {
		int u = qu.top().second; qu.pop();
		id[++tot] = u;
		run(u) {
			if(dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				qu.push(P(dis[v], v));
			}
		}
	}
}
void trace() {
	for(int u = n; u != 1; ) 
		run(u) if(dis[0][u] == dis[0][v] + w) {
			ind[i >> 1] = ++k;
			u = v; break;
		}
	for(int i = 1; i <= m; ++i) 
		if(ind[i]) ind[i] = k - ind[i] + 1;
}
void get(int *p, bool tp) {
	for(int _ = 1; _ <= n; ++_) {
		int u = id[_];
		run(u) if(dis[tp][v] == dis[tp][u] + w) {
			if(ind[i >> 1]) p[v] = tp ? max(p[v], ind[i >> 1]) : min(p[v], ind[i >> 1]);
			else p[v] = tp ? max(p[v], p[u]) : min(p[v], p[u]); 
		}
	}
}

#define mid (t[p].l + t[p].r >> 1)
#define ls p << 1
#define rs p << 1 | 1 
struct SegT {
	int l, r;
	ll v;
} t[N << 2];
void build(int p, int l, int r) {
	t[p].l = l, t[p].r = r, t[p].v = inf;
	if(l == r) return;
	build(ls, l, mid), build(rs, mid + 1, r);
}
void update(int p, int l, int r, ll v) { 
	if(t[p].l >= l && t[p].r <= r) return void(t[p].v = min(t[p].v, v));
	if(mid >= l) update(ls, l, r, v);
	if(mid < r) update(rs, l, r, v);
}
ll query(int p, int x) {
	if(t[p].l == t[p].r) return t[p].v;
	return min(t[p].v, mid >= x ? query(ls, x) : query(rs, x));
}

int main() {
	scanf("%d%d%d", &n, &m, &q);
	memset(dis, 0x3f, sizeof(dis));
	for(int i = 1, u, v, w; i <= m; ++i) {
		scanf("%d%d%d", &u, &v, &w);
		add(u, v, w), add(v, u, w);
	}
	dijkstra(1, dis[0]), trace(); 
	for(int i = 2; i <= n; ++i) l[i] = k + 1; get(l, 0);
	dijkstra(n, dis[1]), r[n] = k + 1, get(r, 1); 
	build(1, 1, k);
	for(int i = 1; i <= m; ++i) if(!ind[i]) {
		int u = e[i << 1].to, v = e[i << 1 | 1].to, w = e[i << 1].val;
		if(l[u] < r[v] - 1) update(1, l[u] + 1, r[v] - 1, dis[0][u] + dis[1][v] + w);
		if(l[v] < r[u] - 1) update(1, l[v] + 1, r[u] - 1, dis[0][v] + dis[1][u] + w);
	}
	for(int i = 1, x, w; i <= q; ++i) {
		scanf("%d%d", &x, &w); 
		int u = e[x << 1].to, v = e[x << 1 | 1].to, lst = e[x << 1].val;
		if(!ind[x]) printf("%lld\n", min(dis[0][n], min(dis[0][v] + dis[1][u], dis[0][u] + dis[1][v]) + w)); 
		else printf("%lld\n", min(dis[0][n] - lst + w, query(1, ind[x])));
	}
	return 0;
}