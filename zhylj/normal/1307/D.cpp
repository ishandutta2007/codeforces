#include <bits/stdc++.h>

const int kMaxN = 4e5 + 5;
const int kInf = 0x3f3f3f3f;

struct Edge {
	int from, to, nxt, val;
} edges[kMaxN];
int head[kMaxN], n, r, cnt = 0;
void AddEdge(int from, int to, int val) {
	edges[cnt].from = from; edges[cnt].to = to; edges[cnt].val = val;
	edges[cnt].nxt = head[from]; head[from] = cnt++;
}

int T[kMaxN << 2], d[kMaxN], dk1[kMaxN], M; bool vis[kMaxN];
void Update(int x) {T[x] = d[T[x << 1]] < d[T[x << 1 | 1]] ? T[x << 1] : T[x << 1 | 1];}
void Build() {
	for(M = 1; M < n + 2; M <<= 1);
	for(int i = M + 1; i <= M + n; ++i) T[i] = i - M;
	for(int i = M; i; --i) Update(i);
}
void Modify(int x) {x += M; while(x) Update(x >>= 1);}
void Dijk(int s) {
	memset(d, 0x3f, sizeof(d));
	memset(vis, false, sizeof(vis));
	Build(); d[s] = 0; Modify(s);
	while(T[1]) {
		int cur = T[1]; vis[T[1]] = true;
		T[cur + M] = 0; Modify(cur);
		for(int i = head[cur]; ~i; i = edges[i].nxt)
			if(!vis[edges[i].to] && d[edges[i].to] > d[cur] + edges[i].val) {
				d[edges[i].to] = d[cur] + edges[i].val;
				Modify(edges[i].to);
			}
	}
}

int a[kMaxN];//, bit[kMaxN];
//void ModifyB(int x, int v) { for(; x <= r; x += x & -x) bit[x] = std::max(bit[x], v); }
//int QueryB(int x) { int ret = 0; for(; x; x -= x & -x) ret = std::max(bit[x], ret); return ret; }
bool cmp(const int &x, const int &y) { return dk1[x] > dk1[y]; }
int main() {
	int k;
	memset(head, 0xff, sizeof(head));
	scanf("%d%d%d", &n, &r, &k);
	for(int i = 1; i <= k; ++i) scanf("%d", a + i);
	for(int i = 0; i < r; ++i) {
		int u, v, w;
		scanf("%d%d", &u, &v);
		AddEdge(u, v, 1); AddEdge(v, u, 1);
	}
	int ans = 0, minp, maxdj = -kInf;
	Dijk(1);
	minp = d[n];
	for(int i = 1; i <= k; ++i) dk1[a[i]] = d[a[i]];
	Dijk(n);
	std::sort(a + 1, a + k + 1, cmp);
	for(int i = 1; i <= k; ++i) {
		int v = a[i];
		//printf("%d ", v);
		ans = std::max(ans, dk1[v] + maxdj + 1);
		maxdj = std::max(d[v], maxdj);
	}
	printf("%d", std::min(ans, minp));
	return 0;
}