#include <bits/stdc++.h>
#define EB emplace_back
using std::cin;
using std::cout;

typedef unsigned long long u64;
typedef std::vector <int> vector;
const int N = 324, M = N * 2, mod = 998244353;

int n, radius;
vector G[N];
int cnt = 0, o[N], id[N];
int p[N], size[N];
int ans[N];
int dak_f[N][M], dak_F[N][M];
int *f[N], *F[N];

inline void add(int &x, const int y) {x += y - mod, x += x >> 31 & mod;}
u64 PowerMod(u64 a, int n, u64 c = 1) {for (; n; n >>= 1, a = a * a % mod) if (n & 1) c = c * a % mod; return c;}

inline void addedge(int u, int v) {G[u].EB(v), G[v].EB(u);}

void predfs(int x) {
	o[++cnt] = x, id[x] = cnt, size[x] = 1;
	for (int y : G[x]) if (y != p[x]) p[y] = x, predfs(y), size[x] += size[y];
	if (x != 1) G[x].erase(std::find(G[x].begin(), G[x].end(), p[x]));
}

int solve() {
	int _, i, x, *g = *dak_f + N;
	for (_ = n; _; --_) {
		x = o[_], memset(dak_f[x], 0, sizeof *dak_f),
		f[x][radius] = f[x][-1] = 1, F[x][radius + 1] = 0;
		for (i = radius; i >= -radius; --i) add(F[x][i] = F[x][i + 1], f[x][i]);
		for (int y : G[x]) {
			g[radius] = (u64)f[x][radius] * F[y][-radius] % mod; 
			for (i = 0; i < radius; ++i)
				g[i] = (f[x][i] * u64(F[y][-i] - F[y][i + 1] + mod) + f[y][i + 1] * u64(F[x][~i] - F[x][i + 1] + mod)) % mod;
			for (i = 1; i <= radius; ++i)
				g[-i] = (f[x][-i] * u64(F[y][1 - i] - F[y][i] + mod) + f[y][1 - i] * u64(F[x][1 - i] - F[x][i - 1] + mod)) % mod;
			memcpy(f[x] - radius, g - radius, (2 * radius + 1) << 2), F[x][radius + 1] = 0;	
			for (i = radius; i >= -radius; --i) add(F[x][i] = F[x][i + 1], f[x][i]);
		}
	}
	return F[1][0];
}

int main() {
	int i, u, v; u64 s = 0;
	std::ios::sync_with_stdio(false), cin.tie(nullptr);
	cin >> n;
	for (i = 1; i < n; ++i) cin >> u >> v, addedge(u, v);
	predfs(1);
	for (i = 1; i <= n; ++i) f[i] = dak_f[i] + N, F[i] = dak_F[i] + N;
	for (radius = 1; radius < n - 1; ++radius) s += mod - solve();
	cout << (int)PowerMod(2, mod - 1 - n, (s + (n - 2ull) * solve() + n - 1) % mod) << '\n';
	return 0;
}