#include <bits/stdc++.h>

#define gc() getchar()
template <typename T> inline void rd(T& x) {
	int si = 1; char c = gc(); x = 0;
	while(!isdigit(c)) si = c == '-' ? -1 : si, c = gc();
	while(isdigit(c)) x = x * 10 + c - 48, c = gc();
	x *= si;
}
template <typename T, typename... Args>
inline void rd(T& x, Args&... args) { rd(x); rd(args...); }
#define fi first
#define se second
#define mkp std::make_pair
typedef unsigned ui;
typedef long long ll;
typedef unsigned long long ull;
typedef double ff;
typedef std::pair <int, int> pii;
const int N = 2000 + 5;

int QPow(int a, int b, int p) {
	int ret = 1, bas = a;
	for(; b; b >>= 1, bas = 1LL * bas * bas % p)
		if(b & 1) ret = 1LL * ret * bas % p;
	return ret;
}
int Inv(int a, int p) { return QPow(a, p - 2, p); }

int n, p, fac[N], fac_inv[N];
std::vector <int> E[N];
void Add(int u, int v) {
	E[u].push_back(v);
	E[v].push_back(u);
}
void Init() {
	fac[0] = 1;
	for(int i = 1; i < N; ++i)
		fac[i] = 1LL * fac[i - 1] * i % p;
	fac_inv[N - 1] = Inv(fac[N - 1], p);
	for(int i = N - 2; ~i; --i)
		fac_inv[i] = 1LL * fac_inv[i + 1] * (i + 1) % p;
}
int C(int x, int y) {
	if(x < y || y < 0) return 0;
	return 1LL * fac[x] * fac_inv[y] % p * fac_inv[x - y] % p;
}

int q[N], q_inv[N];
void GetInv(int f[], int f_inv[]) {
	q[0] = 1;
	for(int i = 1; i <= n; ++i)
		q[i] = 1LL * q[i - 1] * f[i] % p;
	q_inv[n] = Inv(q[n], p);
	for(int i = n - 1; ~i; --i)
		q_inv[i] = 1LL * q_inv[i + 1] * f[i + 1] % p;
	for(int i = 1; i <= n; ++i)
		f_inv[i] = 1LL * q_inv[i] * q[i - 1] % p;
}

int f[N][N], s[N][N], t[N][N], pre[N][N], suf[N][N], _pre[N], _suf[N];
void Dfs(int u, int fa) {
	for(int i = 1; i <= n; ++i)
		t[u][i] = 1;
	for(int v : E[u]) if(v != fa) {
		Dfs(v, u);
		for(int i = 1; i <= n; ++i)
			t[u][i] = 1LL * t[u][i] * s[v][i] % p;
	}
	for(int i = 1; i <= n; ++i)
		_pre[i] = _suf[i] = 1;
	for(int v : E[u]) if(v != fa) {
		memset(pre[v], 0, sizeof(pre[v]));
		memset(suf[v], 0, sizeof(suf[v]));
	}
	for(int v : E[u]) if(v != fa) {
		memcpy(pre[v], _pre, sizeof(pre[v]));
		for(int i = 1; i <= n; ++i)
			_pre[i] = 1LL * _pre[i] * s[v][i] % p;
	}
	std::reverse(E[u].begin(), E[u].end());
	for(int v : E[u]) if(v != fa) {
		memcpy(suf[v], _suf, sizeof(suf[v]));
		for(int i = 1; i <= n; ++i)
			_suf[i] = 1LL * _suf[i] * s[v][i] % p;
	}
	std::reverse(E[u].begin(), E[u].end());
	for(int v : E[u]) if(v != fa) {
		for(int i = 1, j = 0; i <= n; ++i) {
			f[u][i] = (f[u][i] + 1LL * j * f[v][i]) % p;
			j = (j + 1LL * pre[v][i] * suf[v][i]) % p;
		}
	}
	for(int i = 1; i <= n; ++i)
		f[u][i] = (f[u][i] + t[u][i]) % p;
	for(int i = 1; i <= n; ++i)
		s[u][i] = (s[u][i - 1] + f[u][i]) % p;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n, p);
		Init();
		for(int i = 1; i < n; ++i) {
			int u, v; rd(u, v);
			Add(u, v);
		}
		Dfs(1, 0);
		for(int i = 1; i < n; ++i) {
			int ans = 0;
			for(int j = 1; j <= i; ++j) {
				int si = (i - j) % 2 ? -1 : 1;
				ans = (ans + 1LL * C(i, j) * si * t[1][j]) % p;
			}
			ans = (ans + p) % p;
			printf("%d ", ans);
		}
		printf("\n");
	} return 0;
}