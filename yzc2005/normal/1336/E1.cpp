#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod = 998244353, inv2 = mod + 1 >> 1;
inline void add(int &a, int b) { (a += b) >= mod && (a -= mod); }
inline int Add(int a, int b) { return add(a, b), a; }
inline void sub(int &a, int b) { (a -= b) < 0 && (a += mod); }
inline int Sub(int a, int b) { return sub(a, b), a; }
inline void mul(int &a, int b) { a = 1ll * a * b % mod; }
inline int Mul(int a, int b) { return 1ll * a * b % mod; }
const int N = 40, M = 1 << 20;
int m, n, S, f[N][M], g[M], siz[M], x[M], y[M], res[M], ans[N]; 
ll b[M];

inline void XOR(int *a, int n, bool rev) {
	for(int k = 2, m = 1; k <= n; k <<= 1, m <<= 1) {
		for(int j = 0; j < n; j += k) for(int i = 0; i < m; ++i) {
			int x = a[j + i], y = a[j + i + m];
			if(!rev) {
				a[j + i] = Add(x, y);
				a[j + i + m] = Sub(x, y); 
			} else {
				a[j + i] = Mul(Add(x, y), inv2);
				a[j + i + m] = Mul(Sub(x, y), inv2);
			}
		}
	}
}
inline void FWT(int *a, int *b, int n) {
	memcpy(x, a, sizeof(x)), memcpy(y, b, sizeof(y));
	XOR(x, n, 0), XOR(y, n, 0);
	for(int i = 0; i < n; ++i) res[i] = Mul(x[i], y[i]);
	XOR(res, n, 1); 
}

void dfs1(ll x, int y) {
	if(y == m) return ++g[x], void();
	dfs1(x, y + 1);
	if(b[y]) dfs1(x ^ b[y], y + 1);
}
void dfs2(ll x, int y) {
	if(y == n) return ++f[siz[x >> m]][x & (S - 1)], void();
	dfs2(x, y + 1);
	if(b[y]) dfs2(x ^ b[y], y + 1);
}

int main() {
	scanf("%d%d", &m, &n); int tot = 1;
	for(int i = 1; i <= m; ++i) {
		ll x; scanf("%lld", &x), mul(tot, 2);
		for(int k = n - 1; ~k; --k) if(x >> k & 1) {
			if(!b[k]) {
				b[k] = x;
				mul(tot, inv2);
				break;
			}
			x ^= b[k]; 
		}
	}
	m = n + 1 >> 1, S = 1 << m; 
	for(int i = 0; i < S; ++i) siz[i] = siz[i >> 1] + (i & 1);
	dfs1(0, 0), dfs2(0, m);
	for(int i = 0; i <= n - m; ++i) {
		FWT(f[i], g, S);
		for(int s = 0; s < S; ++s) add(ans[i + siz[s]], res[s]);
	}
	for(int i = 0; i <= n; ++i) printf("%d ", Mul(ans[i], tot));
	return 0;
}