#include <bits/stdc++.h>

template <typename T> inline void Read(T& x) {
	int si = 1; char c = getchar(); x = 0;
	while(!isdigit(c)) si = c == '-' ? -1 : si, c = getchar();
	while(isdigit(c)) x = x * 10 + c - 48, c = getchar();
	x *= si;
}
template <typename T, typename... Args>
inline void Read(T& x, Args&... args) { Read(x); Read(args...); }

typedef long long ll;

const int kN = 2e6 + 5;
const ll kInf = 1e18;

struct Edge { int v; ll w; };
std::vector<Edge> E[kN]; int siz = 0, n;
void AddEdge(int u, int v, ll w) { E[u].push_back((Edge) {v, w}); }
void Build(int cur, int l, int r, int fa) {
	if(l < r) {
		int mid = (l + r) >> 1;
		Build(cur << 1, l, mid, cur);
		Build(cur << 1 | 1, mid + 1, r, cur);
	}
	if(fa) AddEdge(fa, cur, 0), AddEdge(cur + siz, fa + siz, 0);
}
void SegAddEdge(int cur, int l, int r, int ql, int qr, int v, ll w, bool in) {
	if(ql <= l && r <= qr) in ? AddEdge(cur + siz, v, w) : AddEdge(v, cur, w);
	else {
		int mid = (l + r) >> 1;
		if(ql <= mid) SegAddEdge(cur << 1, l, mid, ql, qr, v, w, in);
		if(qr > mid) SegAddEdge(cur << 1 | 1, mid + 1, r, ql, qr, v, w, in);
	}
}
int Idx(int cur, int l, int r, int q) {
	if(l == r) return cur;
	int mid = (l + r) >> 1;
	if(q <= mid) return Idx(cur << 1, l, mid, q);
	else return Idx(cur << 1 | 1, mid + 1, r, q);
}

ll d[kN << 2]; int T[kN << 2], M;
void Update(int x) { T[x] = d[T[x << 1]] < d[T[x << 1 | 1]] ? T[x << 1] : T[x << 1 | 1]; }
void BuildZkw() {
	for(M = 1; M < 2 * siz + 2; M <<= 1);
	for(int i = 1; i <= 2 * siz; ++i) T[M + i] = i;
	for(int i = M; i; --i) Update(i);
}
void Modify(int x) { x += M; while(x) Update(x >>= 1); }
void Dijkstra(int s) {
	memset(d, 0x3f, sizeof(d));
	d[s] = 0; BuildZkw();
	while(T[1]) {
		int cur = T[1]; T[cur + M] = 0; Modify(cur);
		for(auto x : E[cur]) {
			int v = x.v; ll w = x.w;
			if(d[cur] + w < d[v]) d[v] = d[cur] + w, Modify(v);
		}
	}
}

int main() {
	int q, s; Read(n, q, s); siz = n << 3;
	Build(1, 1, n, 0);
	while(q--) {
		int opt, x, y, z; ll w; Read(opt, x);
		x = Idx(1, 1, n, x);
		if(opt == 1) {
			Read(y, w); y = Idx(1, 1, n, y);
			AddEdge(x, y, w);
		} else {
			Read(y, z, w);
			SegAddEdge(1, 1, n, y, z, x, w, opt == 3);
		}
	}
	for(int i = 1; i <= n; ++i) {
		int v = Idx(1, 1, n, i);
		AddEdge(v + siz, v, 0);
		AddEdge(v, v + siz, 0);
	}
	Dijkstra(Idx(1, 1, n, s));
	for(int i = 1; i <= n; ++i) {
		int v = Idx(1, 1, n, i);
		printf("%lld ", d[v] < kInf ? d[v] : -1);
	}
	return 0;
}