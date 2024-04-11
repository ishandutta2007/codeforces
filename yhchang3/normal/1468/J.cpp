#include<bits/stdc++.h>
using namespace std;

struct DSU {
	vector<int> sz, p;
	DSU(int n) {
		sz.resize(n + 1), p.resize(n + 1);
		for(int i=0;i<=n;i++)
			sz[p[i] = i] = 1;
	};
	int F(int x) {
		return x == p[x] ? x : p[x] = F(p[x]);
	}
	bool U(int x,int y) {
		x = F(x), y = F(y);
		if(x == y)	return false;
		if(sz[x] < sz[y])	swap(x, y);
		sz[x] += sz[y];
		p[y] = x;
		return true;
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--) {
		int n, m, k;
		cin >> n >> m >> k;
		vector<tuple<int,int,int>> e;
		long long ans = 0;
		int diff = 2e9;
		for(int i=0,u,v,w;i<m;i++) {
			cin >> u >> v >> w;
			e.emplace_back(w, u, v);
		}
		sort(e.begin(), e.end());
		DSU D(n);
		for(auto [w, u, v]:e) {
			diff = min(diff, abs(w - k));
			if(D.U(u, v) && w >= k)
				ans += w - k;
		}
		if(ans == 0)	ans = diff;
		cout << ans << '\n';
	}
}