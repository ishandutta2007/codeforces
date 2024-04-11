#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 1e6 + 7, inf = 1e9;
vi e[N];
int n, m, fa[N], arr[N], mxd[N], hv[N];
void dfs (int x) {
	mxd[x] = 1;
	for (const int &v : e[x]) if(v != fa[x]) {
		fa[v] = x, dfs (v);
		if(mxd[v] + 1 > mxd[x]) {
			mxd[x] = mxd[v] + 1;
			hv[x] = v;
		}
	}
} 
int p[N], tp;
int main () {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m, tp = 0;
	L(i, 1, n - 1) {
		int u, v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs (1);
	L(i, 1, n) if(hv[fa[i]] != i) p[++tp] = mxd[i]; 
	sort(p + 1, p + tp + 1, [&] (int x, int y) { return x > y; }) ;
	int ret = 0;
	ll ns = -1e18;
	L(i, 1, m) {
		if(i <= tp) ret += p[i];
		if(i - (n - ret) > 0) {
			ns = max(ns, (ll) (n - i - (n - ret)) * (i - (n - ret)));
		} else {
			int k = n - ret;
			if(k > n / 2) k = n / 2;
			ns = max(ns, (ll) (n - i - k) * (i - k));
		}
	}
	cout << ns << '\n';
	return 0;
}