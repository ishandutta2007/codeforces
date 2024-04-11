#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define sz(a) ((int) (a).size())
#define vi vector < int > 
#define me(a, x) memset(a, x, sizeof(a))
#define ull unsigned long long
#define ld __float128
using namespace std;
const int N = 4e5 + 7;
int n, k, fa[N], a[N];
ll s[N];
map < int, ll > mp[N];
vi e[N];
ll f[N];
int stk[N], xn;
void dfs(int x) {
	map < int, ll > cur;
	int k = sz(e[x]);
	if(k) {
		for(auto u : mp[x]) 
			cur[u.first / k] = 0, cur[(u.first + k - 1) / k] = 0;
	}
		
	for(const int &v : e[x]) {
		mp[v] = cur, dfs(v);
	}
	
	cur.clear();
	for(auto u : mp[x]) {
		ll ns = (ll) u.first * s[x];
		if(k) {
			int a = u.first / k, b = (u.first + k - 1) / k, t = u.first % k;
			xn = 0;
			for(const int &v : e[x]) 
				ns += mp[v][a], stk[++xn] = mp[v][b] - mp[v][a];
			sort(stk + 1, stk + xn + 1);
			L(i, xn - t + 1, xn) ns += stk[i];
		}
		cur[u.first] = ns;
	}
	mp[x] = cur;
}
void Main() {
	cin >> n >> k;
	L(i, 2, n) cin >> fa[i], e[fa[i]].emplace_back(i);
	L(i, 1, n) cin >> s[i];
	mp[1][k] = 0;
	dfs(1);
	cout << mp[1][k] << '\n';
	L(i, 1, n) mp[i].clear(), e[i].clear();
}
int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--) Main(); 
	return 0;
}