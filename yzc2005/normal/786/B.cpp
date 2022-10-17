#include <bits/stdc++.h>
using namespace std;
#define rg register
#define Each(u) for(rg int i = head[u]; i; i = nxt[i])
#define fu(i, a, b) for(rg int i = (a), I = (b) + 1; i < I; ++i)
#define ls p << 1
#define rs p << 1 | 1
typedef long long ll;
inline int read(int &x) {
	x = 0; char op = getchar();
	while(op < '0' || op > '9') op = getchar();
	while(op >= '0' && op <= '9') x = (x << 3) + (x << 1) + op - 48, op = getchar();
} 
const int N = 300005, M = N * 20;
const ll inf = 0x3f3f3f3f3f3f3f3f;

int n, m, cnt = 1, tot, s, q, head[N], to[M], val[M], nxt[M];
ll dis[N << 2];

inline void add(int u, int v, int w, int opt) {
	if(opt) swap(u, v);
	to[++cnt] = v, val[cnt] = w, nxt[cnt] = head[u];
	head[u] = cnt; 
}

struct SegmentTree {
	int l[N << 2], r[N << 2], id[N << 2];
	
	void build(int p, int L, int R, int opt) {
		l[p] = L, r[p] = R;
		if(L == R) {
			id[p] = L;
			return;
		}
		id[p] = ++tot;
		int mid = L + R >> 1;
		build(ls, L, mid, opt); build(rs, mid + 1, R, opt);
		add(id[p], id[ls], 0, opt); add(id[p], id[rs], 0, opt);
	}
	
	void update(int p, int u, int L, int R, int w, int opt) {
		if(l[p] >= L && r[p] <= R) {
			add(u, id[p], w, opt);
			return;
		}
		int mid = l[p] + r[p] >> 1;
		if(mid >= L) update(ls, u, L, R, w, opt);
		if(mid < R) update(rs, u, L, R, w, opt);
	}
}in, out; 

namespace dij {
	struct node {
		int u; ll dis;
		inline bool operator < (const node &n1) const {return dis > n1.dis;}
	};
	priority_queue<node>q;
	
	inline void solve() {
		memset(dis, 0x3f, sizeof(dis));
		dis[s] = 0; q.push((node) {s, 0});
		while(!q.empty()) {
			if(q.top().dis != dis[q.top().u]) {
				q.pop();
				continue;
			}
			int u = q.top().u; q.pop();
			Each(u) 
				if(dis[to[i]] > dis[u] + val[i]) 
					dis[to[i]] = dis[u] + val[i], q.push((node) {to[i], dis[to[i]]});
		}
	}
}

int main() {
	read(n), read(q), read(s); tot = n;
	out.build(1, 1, n, 0); in.build(1, 1, n, 1);
	for(rg int i = 1, opt, u, l, r, v, w; i <= q; ++i) {
		read(opt);
		if(opt == 1) read(u), read(v), read(w), add(u, v, w, 0);
		else {
			read(u), read(l), read(r), read(w);
			if(opt == 2) out.update(1, u, l, r, w, 0);
			else in.update(1, u, l, r, w, 1);
		}
	}
	dij::solve();
	fu(i, 1, n) printf("%lld ", dis[i] == inf ? -1 : dis[i]);
	return 0;
}