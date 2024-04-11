#include <bits/stdc++.h>

typedef long long ll;
typedef int vec[40], *pvec;
const int N = 4054, M = 8054, mod = 998244353;

int A, B, n;
int fact[154], finv[154];
vec f, g;

inline int & reduce(int &x) {return x += x >> 31 & mod;}
inline void add(int &x, const int y) {x += y - mod, x += x >> 31 & mod;}
inline void sub(int &x, const int y) {x -= y, x += x >> 31 & mod;}
ll PowerMod(ll a, int n, ll c = 1) {for (; n; n >>= 1, a = a * a % mod) if (n & 1) c = c * a % mod; return c;}

void init(int n) {
	int i;
	for (*fact = i = 1; i <= n; ++i) fact[i] = (ll)fact[i - 1] * i % mod;
	finv[n] = PowerMod(fact[n], mod - 2);
	for (i = n; i; --i) finv[i - 1] = (ll)finv[i] * i % mod;
}

inline ll C(int n, int r) {return (ll)fact[n] * finv[r] % mod * finv[n - r] % mod;}

namespace Poly {
	vec B1;

	inline void Clear(vec a) {memset(a, 0, (n + 1) << 2);}
	inline void Copy(vec a, vec b) {memcpy(b, a, (n + 1) << 2);}
	void AddTo(vec a, vec b) {for (int i = 0; i <= n; ++i) add(a[i], b[i]);}
	void SubFrom(vec a, vec b) {for (int i = 0; i <= n; ++i) sub(a[i], b[i]);}

	void Mul(vec a, vec b, vec ret) {
		int i, j; Clear(B1);
		for (i = 0; i <= n; ++i)
			for (j = 0; i + j <= n; ++j)
				B1[i + j] = (B1[i + j] + (ll)a[i] * b[j]) % mod;
		Copy(B1, ret);
	}

	void Inv(vec a, vec ret) {
		int i, j; assert(*a == 1), *B1 = 1;
		for (i = 1; i <= n; ++i) {
			for (B1[i] = j = 0; j < i; ++j)
				B1[i] = (B1[i] - (ll)B1[j] * a[i - j]) % mod;
			reduce(B1[i]);
		}
		Copy(B1, ret);
	}
}

namespace Solver {
	int V, E;
	int to[M], first[N], next[M];
	int p[N];
	vec f[N], tmp;
	pvec ans;

	inline void addedge(int u, int v) {
		to[++E] = v, next[E] = first[u], first[u] = E;
		to[++E] = u, next[E] = first[v], first[v] = E;
	}

	void dfs(int x) {
		int i, y; Poly::Clear(f[x]);
		for (i = first[x]; i; i = next[i])
			if ((y = to[i]) != p[x]) p[y] = x, dfs(y), Poly::SubFrom(f[x] + 1, f[y]);
		*f[x] = 1, f[x][n + 1] = 0, Poly::Inv(f[x], f[x]);
	}

	void dfs2(int x) {
		int i, y; Poly::AddTo(ans, f[x]);
		for (i = first[x]; i; i = next[i])
			if (p[y = to[i]] == x)
				Poly::Mul(f[x], f[y], tmp + 1), *tmp = 1, tmp[n + 1] = 0,
				Poly::Mul(f[y], tmp, f[y]), dfs2(y);
	}

	void main(int n_, pvec ret) {
		int i, u, v;
		V = n_, E = 0, memset(first, 0, (V + 1) << 2);
		Poly::Clear(ans = ret);
		for (i = 1; i < V; ++i) scanf("%d%d", &u, &v), addedge(u, v);
		dfs(1), dfs2(1);
	}
}

int main() {
	int i, ans = 0;
	scanf("%d%d%d", &A, &B, &n), init(n);
	if (n & 1) return putchar(48), putchar(10), 0;
	n /= 2, Solver::main(A, f), Solver::main(B, g);	
	for (i = 0; i <= n; ++i) ans = (ans + C(2 * n, 2 * i) * f[i] % mod * g[n - i]) % mod;
	printf("%d\n", ans);
	return 0;
}