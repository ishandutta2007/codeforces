#include <bits/stdc++.h>

typedef long long ll;
typedef std::valarray <ll> vector;
const int N = 108, mod = 1000000007;
const int dr[4] = {0, -1, 0, 1}, dc[4] = {-1, 0, 1, 0};

int n, eqns = 0;
int p[4], w[N];
vector f[N][N];
int m[N][N], b[N];

inline ll reduce(ll &x) {return x += x >> 63 & mod;}
inline ll reduced(const ll &x) {return x + (x >> 63 & mod);}

ll PowerMod(ll a, int n, ll c = 1) {for (; n; n >>= 1, a = a * a % mod) if (n & 1) c = c * a % mod; return c;}

void gauss(int n) {
	int i, j, k; ll coe;
	static int *m[N];
	for (i = 0; i < n; ++i) m[i] = ::m[i];
	for (i = 0; i < n; ++i) {
		for (j = i; j < n && !m[j][i]; ++j);
		if (j == n) continue;
		if (i != j) std::swap(m[i], m[j]), std::swap(b[i], b[j]);
		coe = PowerMod(m[i][i], mod - 2);
		for (j = i; j < n; ++j) m[i][j] = m[i][j] * coe % mod; b[i] = b[i] * coe % mod;
		for (k = 0; k < n; ++k) if (k != i) {
			coe = mod - m[k][i];
			for (j = i; j < n; ++j) m[k][j] = (m[k][j] + coe * m[i][j]) % mod;
			b[k] = (b[k] + coe * b[i]) % mod;
		}
	}
}

int main() {
	int i, j, k, r, c = 0, d; ll s = 0, iv3; vector g;
	scanf("%d%d%d%d%d", &n, p, p + 1, p + 2, p + 3);
	if (!n) return putchar(49), putchar(10), 0;
	s = PowerMod(*p + p[1] + p[2] + p[3], mod - 2);
	for (i = 0; i < 4; ++i) p[i] = p[i] * s % mod;
	iv3 = PowerMod(p[3], mod - 2);
	for (i = 0; i <= n; ++i) w[54 - i] = w[54 + i] = sqrt(n * n - i * i);
	for (i = 54 - n; i <= 54 + n; ++i)
		for (j = 54 - w[i]; j <= 54 + w[i]; ++j) f[i][j].resize(2 * n + 2);
	for (j = 54 - n; j <= 54 + n; ++j) f[54 - w[j]][j][c++] = 1;
	assert(c == 2 * n + 1);
	for (i = 54 - n; i <= 54 + n; ++i)
		for (j = 54 - w[i]; j <= 54 + w[i]; ++j) {
			g = f[i][j], reduce(--g[2 * n + 1]);
			for (d = 0; d < 3; ++d) {
				r = i + dr[d], c = j + dc[d];
				if (f[r][c].size())
					g = (g - (ll)p[d] * f[r][c]) % mod;
			}
			g = g.apply(reduced);
			if (i == 54 + w[j]) {
				for (k = 0; k <= 2 * n; ++k) m[eqns][k] = g[k];
				b[eqns++] = reduced(-g[2 * n + 1]);
			} else
				f[i + 1][j] = g * iv3 % mod;
		}
	assert(eqns == 2 * n + 1), gauss(eqns);
	b[2 * n + 1] = 1;
	for (c = i = 0; i <= 2 * n + 1; ++i) c = (c + f[54][54][i] * b[i]) % mod;
	printf("%d\n", c);
	return 0;
}