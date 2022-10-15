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
const int N = 1e5 + 5, A = 1e7 + 5, A_P = 7e6 + 5;

int mn_p[A], mu[A], p[A_P], a_mx, p_cnt;
bool flag[A];
void Sieve() {
	mu[1] = mn_p[1] = 1;
	for(int i = 2; i <= a_mx; ++i) {
		if(!flag[i]) {
			p[++p_cnt] = mn_p[i] = i;
			mu[i] = -1;
		}
		for(int j = 1; j <= p_cnt && i * p[j] <= a_mx; ++j) {
			flag[i * p[j]] = true;
			mn_p[i * p[j]] = p[j];
			if(i % p[j] == 0) {
				mu[i * p[j]] = 0;
				break;
			}
			mu[i * p[j]] = -mu[i];
		}
	}
}

int n, k, a[N];

std::vector <int> GetFac(int x) {
	if(x == 1) return (std::vector <int>) { 1 };
	int cnt = 0, p = mn_p[x];
	for(; x % p == 0; ++cnt) x /= p;
	std::vector <int> f = GetFac(x), res;
	for(int i = 0, bas = 1; i <= cnt; ++i, bas *= p)
		for(int j : f) res.push_back(j * bas);
	return res;
}

std::vector <int> f[N];
int g[N], bg_g[N], s[A];
bool vis[N];
void Update(int i) {
	g[i] = 0;
	for(int j : f[i]) g[i] += mu[j] * s[j];
}

int Gcd(int a, int b) { return b ? Gcd(b, a % b) : a; }

std::vector <int> n_v[N];
bool has_n[N];
void Div(int l, int r, const std::vector <int> &idp, const std::vector <int> &n_idp) {
	if(l >= idp.size() || l > r) return;
	if(l == r) {
		int u = idp[l];
		for(int i : n_idp)
			if(Gcd(a[i], a[u]) == 1) {
				n_v[u].push_back(i);
			}
		return;
	}
	int mid = (l + r) / 2;
	for(int i = l; i <= mid; ++i)
		for(int j : f[idp[i]]) ++s[j];
	std::vector <int> l_n_idp, r_n_idp;
	for(int i : n_idp) {
		Update(i);
		if(g[i]) l_n_idp.push_back(i);
		else r_n_idp.push_back(i);
	}
	for(int i = l; i <= mid; ++i)
		for(int j : f[idp[i]]) --s[j];
	Div(l, mid, idp, l_n_idp);
	Div(mid + 1, r, idp, r_n_idp);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n, k);
		for(int i = 1; i <= n; ++i) {
			rd(a[i]);
			a_mx = std::max(a_mx, a[i]);
		}
		Sieve();
		for(int i = 1; i <= n; ++i) {
			f[i] = GetFac(a[i]);
			for(int j : f[i]) ++s[j];
		}
		std::vector <int> idp, n_idp;
		for(int i = 1; i <= n; ++i) {
			Update(i);
			if(!g[i]) idp.push_back(i);
		}
		memcpy(bg_g, g, sizeof(bg_g));
		for(int i = 1; i <= n; ++i) {
			Update(i);
			if(bg_g[i] && g[i] == bg_g[i]) {
				vis[i] = true;
				idp.push_back(i);
				for(int j : f[i]) --s[j];
			}
		}
		if(idp.size() >= k) {
			for(int i = 0; i < k; ++i)
				printf("%d ", idp[i]);
			printf("\n");
			return 0;
		}
		memset(s, 0, sizeof(s));
		idp.clear();
		for(int i = 1; i <= n; ++i) {
			if(vis[i]) idp.push_back(i);
			else n_idp.push_back(i);
		}
		Div(0, (int)idp.size() - 1, idp, n_idp);
		std::vector <int> ans;
		for(int i = 1; i <= n; ++i)
			if(!n_v[i].empty() && ans.size() + 2 <= k) {
				ans.push_back(n_v[i].back());
				ans.push_back(i);
				n_v[i].pop_back();
				has_n[i] = true;
			}
		for(int i = 1; i <= n; ++i)
			if(has_n[i]) {
				while(ans.size() < k && !n_v[i].empty()) {
					ans.push_back(n_v[i].back());
					n_v[i].pop_back();
				}
			}
		for(int i : ans)
			printf("%d ", i);
		printf("\n");
	} return 0;
}