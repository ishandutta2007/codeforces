#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= int(b); i++)
#define per(i, a, b) for (int i = (a); i >= int(b); i--)
#define fir first
#define sec second
#define tct template<class type>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
const int maxn = 1e5, mod = 1e9 + 7;
int n, sz[maxn + 5], a[maxn + 5], b[maxn + 5], k[maxn + 5];
ll m, mn, mx;
vector<int> G[maxn + 5], vec[maxn + 5];
vector<vector<int> > V;

inline void red(int &x) { x += x >> 31 & mod; }
tct inline void cmax(type &x, type y) { x < y ? x = y : 0; }
tct inline void cmin(type &x, type y) { x > y ? x = y : 0; }

void dfs(int u, int par = 0) {
	sz[u] = 1;
	for (int v: G[u]) if (v != par) {
		dfs(v, u);
		sz[u] += sz[v];
	}
	mx += min(sz[u], n - sz[u]);
	mn += sz[u] & 1;
	vec[min(sz[u], n - sz[u])].emplace_back(u);
}

void pr(int x, int y) {
	printf("%d %d\n", x, y);
}

void work(int u, int par = 0) {
	bool f = true;
	for (int v: G[u]) if (v != par) work(v, u), f = false;
	if (f) return k[u] = V.size(), V.emplace_back(vector<int>(1, u));
	priority_queue<P> H;
	int c = 1;
	for (int v: G[u]) if (v != par) c += a[v], H.push(P(a[v], v));
	H.push(P(1, u));
	V[0] = vector<int>(1, u);
	while (c > a[u]) {
		P x = H.top(); H.pop();
		P y = H.top(); H.pop();
		int p = x.sec, q = y.sec;
		pr(V[k[p]].back(), V[k[q]].back());
		V[k[p]].pop_back();
		V[k[q]].pop_back();
		H.push(P(x.fir - 1, x.sec));
		H.push(P(y.fir - 1, y.sec));
		c -= 2;
	}
	int w = 0;
	for (int v: G[u]) if (v != par && (!w || V[k[v]].size() > V[k[w]].size())) w = v;
	k[u] = k[w]; 
	for (int v: G[u]) if (v != par && v != w) {
		for (int x: V[k[v]]) V[k[u]].emplace_back(x);
	}
	if (V[0].size()) V[k[u]].emplace_back(u);
}

int main() {
	scanf("%d %lld", &n, &m);
	for (int i = 1, u, v; i < n; i++) {
		scanf("%d %d", &u, &v);
		G[u].emplace_back(v), G[v].emplace_back(u);
	}
	dfs(1);
	if (m < mn || m > mx || (m & 1) != (mx & 1)) puts("NO"), exit(0);
	puts("YES");
	ll t = (mx - m) / 2;
	int s[2] = {};
	per(i, n >> 1, 2) {
		s[i & 1] += vec[i].size();
		if (t <= s[i & 1]) {
			rep(j, i, n >> 1) if ((j ^ i) & 1) for (int x: vec[j]) a[x] = i - 1;
			int c = 0;
			rep(j, i, n >> 1) if (~(j ^ i) & 1) for (int x: vec[j]) a[x] = i - 2 * (++c <= t);
			rep(j, 0, i - 1) for (int x: vec[j]) a[x] = j;
			break;
		} else {
			t -= s[i & 1];
		}
	}
	V.emplace_back(vector<int>());
	work(1);
	return 0;
}