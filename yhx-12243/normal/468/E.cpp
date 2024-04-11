#include <bits/stdc++.h>
#define EB emplace_back
#define ctz __builtin_ctz
#define ctz64 __builtin_ctzll
#define popc __builtin_popcount
using std::cin;
using std::cout;
using std::vector;

typedef long long ll;
typedef unsigned long long u64;
typedef std::pair <int, int> pr;
const int N = 54, mod = 1000000007;

inline int & reduce(int &x) {return x += x >> 31 & mod;}
inline void add(int &x, const int y) {x += y - mod, x += x >> 31 & mod;}
inline void sub(int &x, const int y) {x -= y, x += x >> 31 & mod;}

struct poly : std::array <int, N> {
	inline poly & operator += (const poly &B) {for (int i = 0; i < N; ++i) add(at(i), B[i]); return *this;}
	inline poly & operator -= (const poly &B) {for (int i = 0; i < N; ++i) sub(at(i), B[i]); return *this;}
	inline poly & operator *= (const int k) {for (int i = 0; i < N; ++i) at(i) = (ll)at(i) * k % mod; return *this;}
	inline poly & operator *= (const poly &B) {
		int i, j; static u64 $[N]; memset($, 0, N << 3);
		for (i = 0; i < N; ++i) {
			for (j = 0; i + j < N; ++j) $[i + j] += (u64)at(i) * B[j];
			if (!(~i & 15)) for (j = 0; j < N; ++j) $[i] %= mod;
		}
		for (i = 0; i < N; ++i) at(i) = $[i] % mod;
		return *this;
	}
	inline poly operator + (const poly &B) const {poly ret(*this); return ret += B;}
	inline poly operator - (const poly &B) const {poly ret(*this); return ret -= B;}
	inline poly operator * (const int k) const {poly ret(*this); return ret *= k;}
	inline poly operator * (const poly &B) const {poly ret(*this); return ret *= B;}
	inline void shift() {std::copy_backward(begin(), end() - 1, end()), front() = 0;}
};

struct graph {
	vector <vector <pr>> G;
	inline void reset(int n) {G.assign(n, vector <pr> ());}
	inline void addedge(int u, int v, int w) {G[u].EB(v, w), G[v].EB(u, w);}
	poly perm() const;
} G;

int n, K, V1, V2;
int x[N], y[N], w[N];
int ccu[100054];

poly graph::perm() const {
	static bool used[N];
	static int inum[N];
	int i, j, k, n = G.size(), m, W, $ = 0;
	bool conn = true;
	vector <int> curps;
	vector <vector <int>> CCs;
	graph S;
	poly ret; ret.fill(0), ret[0] = 1;
	if (n <= 1) return ret;
	std::function <void(int)> dfs = [&] (int x) -> void {
		used[x] = true, curps.EB(x);
		for (const pr &e : G[x]) if (!used[e.first]) dfs(e.first);
	};
	memset(used, false, n), dfs(0);
	for (i = 1; i < n; ++i) if (!used[i]) conn = false, CCs.EB(curps), curps.clear(), dfs(i);
	if (conn) {
		for (m = i = 0; i < n; ++i) m += G[i].size();
		assert(!(m & 1)), m /= 2;
		if (m == n - 1) {
			static int p[N], pw[N]; static poly f[N], g[N];
			dfs = [&] (int x) -> void {
				int y;
				f[x].fill(0), f[x][0] = 1, g[x].fill(0), g[x][0] = 1;
				for (const pr &e : G[x])
					if ((y = e.first) != p[x])
						p[y] = x, pw[y] = e.second, dfs(y), f[x] = f[x] * f[y] + g[x] * g[y], g[x] = g[x] * f[y];
				(g[x] *= pw[x]).shift();
			};
			*p = -1, *pw = 0, dfs(0);
			return *f;
		} else if (m < n + 13) {
			static u64 conn[N]; bool succ = false;
			for (i = 0; i < n; ++i) conn[i] = 1ull << i;
			for (W = j = i = 0; i < n; ++i) {
				for (const pr &e : G[i]) if (i < (j = e.first)) {
					if (conn[i] == conn[j]) {succ = true, W = e.second; break;}
					for (u64 A = conn[i] | conn[j], B = A; A; A &= A - 1) conn[ctz64(A)] = B;
				}
				if (succ) break;
			}
			assert(succ && i != j), S.G = G;
			vector<pr>::iterator it;
			for (it = S.G[i].begin(); it != S.G[i].end(); ++it) if (it->first == j) {S.G[i].erase(it); break;}
			for (it = S.G[j].begin(); it != S.G[j].end(); ++it) if (it->first == i) {S.G[j].erase(it); break;}
			ret = S.perm();
			for (k = 0; k < n; ++k) if (k != i && k != j) inum[k] = $++;
			assert($ == n - 2), S.reset($);
			for (k = 0; k < n; ++k) if (k != i && k != j) for (const pr &e : G[k])
				if (e.first != i && e.first != j && k < e.first) S.addedge(inum[k], inum[e.first], e.second);
			poly occ = S.perm(); (occ *= W).shift();
			return ret + occ;
		} else {
			static int col[N], w$[N], f[262154];
			dfs = [&] (int x) -> void {
				int y;
				for (const pr &e : G[x]) if (!~col[y = e.first]) col[y] = !col[x], dfs(y);
			};
			memset(col, -1, n << 2), *col = 0, dfs(0);
			int L = std::count(col, col + n, 0), R = std::count(col, col + n, 1), ALL;
			assert(L + R == n);
			if (L > R) for (std::swap(L, R), i = 0; i < n; ++i) col[i] ^= 1;
			assert(L < 19), ALL = ~(-1 << L);
			for (i = 0; i < n; ++i) if (!col[i]) inum[i] = $++;
			memset(f, 0, 4 << L), *f = 1;
			for (i = 0; i < n; ++i) if (col[i]) {
				memset(w$, 0, L << 2);
				for (const pr &e : G[i]) w$[inum[e.first]] = e.second;
				for (j = ALL; j >= 0; --j)
					for (W = ALL & ~j; W; W &= W - 1)
						k = ctz(W), f[j | 1 << k] = (f[j | 1 << k] + (ll)f[j] * w$[k]) % mod;
			}
			for (i = 1; i <= ALL; ++i) add(ret[popc(i)], f[i]);
			return ret;
		}
	} else {
		CCs.EB(curps), curps.clear();
		for (const vector <int> &CC : CCs) {
			S.reset(m = CC.size());
			for (i = 0; i < m; ++i) inum[CC[i]] = i;
			for (i = 0; i < m; ++i) for (const pr &e : G[CC[i]])
				if (i < inum[e.first]) S.addedge(i, inum[e.first], e.second);
			ret *= S.perm();
		}
		return ret;
	}
}

namespace DC {
	int F[N]; pr D[N];

	int Discretize(int n) {
		int i, cnt = 0;
		std::sort(D, D + n);
		for (i = 0; i < n; ++i)
			F[D[i].second] = (i && D[i].first == D[i - 1].first ? cnt - 1 : (D[cnt] = D[i], cnt++));
		return cnt;
	}
}

int main() {
	int i, ans;
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	cin >> n >> K;
	for (i = 0; i < K; ++i) cin >> x[i] >> y[i] >> w[i], reduce(--w[i]), DC::D[i] = pr(x[i], i);
	V1 = DC::Discretize(K);
	for (i = 0; i < K; ++i) x[i] = DC::F[i], DC::D[i] = pr(y[i], i);
	V2 = DC::Discretize(K), G.reset(V1 + V2);
	for (i = 0; i < K; ++i) y[i] = DC::F[i] + V1, G.addedge(x[i], y[i], w[i]);
	memcpy(ccu, G.perm().data(), N << 2), ans = ccu[0];
	for (i = 0; i < n; ++i) ans = (ans * ll(n - i) + ccu[i + 1]) % mod;
	cout << ans << '\n';
	return 0;
}