#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
int n, r[N], id[N];
long long a[N], sum[N];
int c[N];
void modify(int p, int x) {
	p = n - p + 1;
	while (p <= n + 1) {
		c[p] += x;
		p += p & -p;
	}
}
int query(int p) {
	p = n - p + 1;
	int res = 0;
	while (p) {
		res += c[p];
		p -= p & -p;
	} 
	return res;
}
void solve() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", &a[i]);
		if (i & 1) {
			sum[i] = sum[i - 1] + a[i];
		} else {
			sum[i] = sum[i - 1] - a[i];
		}
		a[i] -= a[i - 1];
	}
	fill(r, r + n + 1, n + 1);
	iota(id, id + n + 1, 0);
	sort(id, id + n + 1, [&](int i, int j) {
		return a[i] < a[j];
	});
	set<int> s[2];
	s[0].insert(n + 1);
	s[1].insert(n + 1);
	for (int o = 0, t = 0; o <= n; ++o) {
		int i = id[o];
		while (t <= n && a[id[t]] < a[i]) {
			s[id[t] & 1].insert(id[t]);
			++t;
		} 
		int j = *s[i & 1].upper_bound(i);
		r[i] = min(r[i], j);
	}
	s[0].clear();
	s[0].insert(n + 1);
	s[1].clear();
	s[1].insert(n + 1);
	for (int o = n, t = 0; o >= 0; --o) {
		int i = id[o];
		while (t <= n && a[i] + a[id[t]] < 0) {
			s[id[t] & 1].insert(id[t]);
			++t;
		}
		int j = *s[!(i & 1)].upper_bound(i);	
		r[i] = min(r[i], j);		
	}
	map<long long, vector<int>> mp;
	for (int i = n; i >= 0; --i) {
		mp[sum[i]].emplace_back(i);
	}
	long long ans = 0;
	for (auto &p : mp) {
		auto &v = p.second;
		for (auto x : v) {
			ans += query(x) - query(r[x]);
			modify(x, 1);
		} 
		for (auto x : v) {
			modify(x, -1);
		}
	}
	printf("%lld\n", ans);
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}