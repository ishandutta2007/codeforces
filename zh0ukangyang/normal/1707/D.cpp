#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
#define uint unsigned int
using namespace std;
const int N = 4007;
int mod;
int qpow(int x, int y = mod - 2) {
	int res = 1;
	for(; y; x = (ll) x * x % mod, y >>= 1) if(y & 1) res = (ll) res * x % mod;
	return res;
}
int fac[N], ifac[N], inv[N];
void init(int x) {
	fac[0] = ifac[0] = inv[1] = 1;
	L(i, 2, x) inv[i] = (ll) (mod - mod / i) * inv[mod % i] % mod;
	L(i, 1, x) fac[i] = (ll) fac[i - 1] * i % mod, ifac[i] = (ll) ifac[i - 1] * inv[i] % mod;
} 
int C(int x, int y) {
	return x < y || y < 0 ? 0 : (ll) fac[x] * ifac[y] % mod * ifac[x - y] % mod;
}
int n, ns[N];
int dp[N][N], P[N][N], S[N][N]; 
vi e[N];
void dfs(int x, int f) {
	for(const int &v : e[x]) if(v != f) dfs(v, x);
	L(i, 1, n) dp[x][i] = 1;
	vi G;
	for(const int &v : e[x]) if(v != f) G.emplace_back(v);
	L(c, 0, sz(G) - 1) {
		int v = G[c], pre = 0;
		L(i, 1, n) (pre += dp[v][i]) %= mod, P[c][i] = S[c][i] = pre, dp[x][i] = (ll) dp[x][i] * pre % mod;
	}
	if(x == 1) return ;
	L(i, 1, sz(G) - 1) L(j, 1, n) P[i][j] = (ll) P[i][j] * P[i - 1][j] % mod;
	R(i, sz(G) - 2, 0) L(j, 1, n) S[i][j] = (ll) S[i][j] * S[i + 1][j] % mod; 
	L(c, 0, sz(G) - 1) {
		int v = G[c], pre = 0;
		L(i, 1, n) {
			(dp[x][i] += (ll) dp[v][i] * pre % mod) %= mod;
			int w = 1;
			if(c) w = (ll) w * P[c - 1][i] % mod;
			if(c < sz(G) - 1) w = (ll) w * S[c + 1][i] % mod; 
			(pre += w) %= mod;
		}
	}
}
int main () {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> mod;
	init(n * 2);
	L(i, 1, n - 1) {
		int u, v;
		cin >> u >> v;
		e[u].emplace_back(v);
		e[v].emplace_back(u); 
	} 
	dfs(1, 0);
//	L(i, 1, n - 1) 
//		cout << dp[1][i] << ' ';
//	cout << endl;
	L(i, 1, n - 1) ns[i] = dp[1][i];
	L(i, 1, n - 1) {
		L(j, i + 1, n - 1) {
			(ns[j] += mod - (ll) C(j, i) * ns[i] % mod) %= mod;
		}
		cout << ns[i] << ' ';
	}
	return 0;
}