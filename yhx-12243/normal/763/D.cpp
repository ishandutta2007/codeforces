#include <bits/stdc++.h>

typedef unsigned int u32;
typedef unsigned long long u64;
typedef std::map <u64, int> map;
const int N = 100054, M = N * 2;
const u64 mod = 18446744073709551557ull;

int n, E = 0, root, best = -1;
int to[M], first[N], next[M];
int p[N], size[N];
int tmp[N];
u64 seq[N], f[N];
u64 pre[N], suf[N], ff[N];
map pool;
std::mt19937_64 gen;

inline void up(int &x, const int y) {x < y ? x = y : 0;}
inline void insert(u64 x) {++pool[x];}
inline void erase(u64 x) {map::iterator it = pool.find(x); if (!--it->second) pool.erase(it);}

u64 mul(u64 A, u64 B) {return (unsigned __int128)A * B % mod;}

inline void addedge(int u, int v) {
	to[++E] = v, next[E] = first[u], first[u] = E;
	to[++E] = u, next[E] = first[v], first[v] = E;
}

void dfs(int x) {
	int i, y, la = 0, top = 0; size[x] = 1;
	for (i = first[x]; i; i = next[i])
		if ((y = to[i]) != p[x])
			p[y] = x, dfs(y), size[x] += size[y],
			pre[y] = mul(pre[la], f[y] ^ seq[size[y]]), la = y;
	f[x] = pre[la];

	for (i = first[x]; i; i = next[i])
		if (p[y = to[i]] == x) tmp[top++] = y;
	for (la = 0, i = top - 1; i >= 0; --i)
		y = tmp[i], suf[y] = mul(suf[la], f[y] ^ seq[size[y]]), la = y;
	assert(f[x] == suf[la]);
}

void solve(int x, u64 U) {
	int i, y, top = 0;
	if ((int)pool.size() > best) best = pool.size(), root = x;
	for (i = first[x]; i; i = next[i])
		if (p[y = to[i]] == x) tmp[++top] = y;
	*tmp = tmp[top + 1] = 0;
	for (i = 1; i <= top; ++i)
		ff[ tmp[i] ] = mul(U, mul(pre[ tmp[i - 1] ], suf[ tmp[i + 1] ]));
	for (i = first[x]; i; i = next[i])
		if (p[y = to[i]] == x)
			insert(ff[y]), erase(f[y]),
			solve(y, ff[y] ^ seq[n - size[y]]),
			erase(ff[y]), insert(f[y]);
}

int main() {
	int i, u, v;
	char *_ = new char; gen.seed(time(NULL) + (size_t)_), delete _;
	scanf("%d", &n);
	for (i = 1; i <= n; ++i) seq[i] = gen() % mod;
	for (i = 1; i < n; ++i) scanf("%d%d", &u, &v), addedge(u, v);
	*pre = *suf = 1, dfs(1);
	for (i = 2; i <= n; ++i) insert(f[i]);
	solve(1, 1);
	printf("%d\n", root);
	return 0;
}