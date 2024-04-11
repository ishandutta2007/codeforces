#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
int n, m, k, d1[N], dn[N], a[N];
vector<int> g[N];
queue<int> q;

inline bool cmp (const int &u, const int &v) {
	return d1[u] - dn[u] < d1[v] - dn[v];
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m >> k;
	for(int i = 1; i <= k; ++i) cin >> a[i];
	for(int i = 1, u, v; i <= m; ++i) {
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	q.push(1);
	while(!q.empty()) {
		int u = q.front(); q.pop();
		for(int i = 0; i < g[u].size(); ++i) {
			int v = g[u][i];
			if(d1[v] || v == 1) continue;
			d1[v] = d1[u] + 1;
			q.push(v);
		}		
	}
	q.push(n); 
	while(!q.empty()) {
		int u = q.front(); q.pop();
		for(int i = 0; i < g[u].size(); ++i) {
			int v = g[u][i];
			if(dn[v] || v == n) continue;
			dn[v] = dn[u] + 1;
			q.push(v);
		}		
	}
	sort(a + 1, a + k + 1, cmp);
	int ans = 0, mx = 0;
	for(int i = k; i; --i) {
		if(i != k) ans = max(ans, d1[a[i]] + mx + 1);
		mx = max(mx, dn[a[i]]);
	}
	cout << min(ans, d1[n]);
	return 0;
}