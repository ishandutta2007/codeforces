#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
inline void add(int &a, int b) { (a += b) >= mod && (a -= mod); }
inline int Add(int a, int b) { return add(a, b), a; }
inline void mul(int &a, int b) { a = 1ll * a * b % mod; }
inline int Mul(int a, int b) { return 1ll * a * b % mod; }

typedef long long ll;
const int N = 100005, M = 400005, K = 70;
int n, m, sz, p[N], tot;
ll b[K], d[N], s[N];
bool vis[N];

int cnt, hd[N], to[M], nxt[M]; ll val[M];
inline void add(int u, int v, ll w) {
	to[++cnt] = v;
	nxt[cnt] = hd[u];
	val[cnt] = w;
	hd[u] = cnt;
} 

inline void ins(ll x) {
	for(int i = 63; ~i; --i) if(x >> i & 1) {
		if(!b[i]) {
			b[i] = x;
			++tot;
			break;
		}
		x ^= b[i];
	}
}
void dfs(int u) {
	vis[u] = 1, s[++sz] = d[u];
	for(int i = hd[u]; i; i = nxt[i]) {
		if(vis[to[i]]) ins(d[u] ^ d[to[i]] ^ val[i]);
		else d[to[i]] = d[u] ^ val[i], dfs(to[i]);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for(int i = 1; i <= m; ++i) {
		int u, v; ll w; cin >> u >> v >> w;
		add(u, v, w), add(v, u, w);
	}
	p[0] = 1; for(int i = 1; i <= n; ++i) p[i] = Mul(p[i - 1], 2);
	int ans = 0;
	for(int i = 1; i <= n; ++i) if(!vis[i]) {
		memset(b, 0, sizeof(b)); 
		sz = tot = 0, dfs(i);
		for(int k = 0; k <= 63; ++k) {
			bool type = 0;
			for(int j = 0; j <= 63; ++j) type |= b[j] >> k & 1;
			if(type) {
				add(ans, Mul(1ll * sz * (sz - 1) / 2 % mod, p[tot - 1 + k]));
			} else {
				int coef = 0;
				for(int j = 1; j <= sz; ++j) coef += s[j] >> k & 1;
				add(ans, Mul(Mul(coef, sz - coef), p[tot + k]));
			}
		}
	}
	cout << ans << '\n';
	return 0; 
}