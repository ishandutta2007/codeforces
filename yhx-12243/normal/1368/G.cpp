#include <bits/stdc++.h>
#define id(r, c) ((r) * C + (c) + 1)
#define EB emplace_back
using std::cin;
using std::cout;

typedef unsigned int u32;
typedef std::vector <int> vector;
const int N = 200054;

int n, R, C;
int p[N], fc[N], nc[N];
int cnt = -1, id[N], eid[N], ad[N];
long long ans;
char s[N];
vector G[N];

namespace ST {
	#define segc int M = (L + R - 1) >> 1, lc = id << 1, rc = lc | 1
	struct node {int v, cnt, tag;} x[265000];

	void update(node &ret, const node &l, const node &r) {
		if (l.v == r.v) ret.v = l.v, ret.cnt = l.cnt + r.cnt;
		else if (l.v < r.v) ret.v = l.v, ret.cnt = l.cnt;
		else ret.v = r.v, ret.cnt = r.cnt;
		ret.v += ret.tag;
	}

	void build(int id, int L, int R) {
		x[id].cnt = R - L + 1;
		if (L == R) return;
		segc; build(lc, L, M), build(rc, M + 1, R);
	}

	void add(int id, int L, int R, int ql, int qr, int v) {
		if (ql <= L && R <= qr) {x[id].v += v, x[id].tag += v; return;}
		segc;
		if (ql <= M) add(lc, L, M, ql, qr, v);
		if (qr > M) add(rc, M + 1, R, ql, qr, v);
		update(x[id], x[lc], x[rc]);
	}
}

inline int ID(int r, int c) {return (u32)r < (u32)R && (u32)c < (u32)C ? r * C + c + 3 : ((r ^ c) & 1) + 1;}

inline void link(int x, int px) {p[x] = px, nc[x] = fc[px], fc[px] = x;}

void dfs(int x) {
	int y; id[x] = ++cnt;
	for (y = fc[x]; y; y = nc[y]) dfs(y);
	eid[x] = cnt;
}

void solve(int x) {
	int y, z = ad[x];
	ST::add(1, 1, n, id[z], eid[z], 1);
	if (!ST::x[1].v) ans -= ST::x[1].cnt;
	for (y = fc[x]; y; y = nc[y]) solve(y);
	ST::add(1, 1, n, id[z], eid[z], -1);
}

int main() {
	int i, j;
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	cin >> R >> C, n = R * C / 2, ans = (long long)n * n;
	for (i = 0; i < R; ++i)
		for (cin >> s, j = 0; j < C; ++j)
			switch (s[j]) {
				case 68: link(ID(i, j), ID(i - 2, j)), ad[ID(i, j)] = ID(i - 1, j); break;
				case 76: link(ID(i, j), ID(i, j + 2)), ad[ID(i, j)] = ID(i, j + 1); break;
				case 82: link(ID(i, j), ID(i, j - 2)), ad[ID(i, j)] = ID(i, j - 1); break;
				case 85: link(ID(i, j), ID(i + 2, j)), ad[ID(i, j)] = ID(i + 1, j); break;
			}
	ST::build(1, 1, n), dfs(1), assert(cnt == n);
	for (i = fc[2]; i; i = nc[i]) solve(i);
	cout << ans << '\n';
	return 0;
}