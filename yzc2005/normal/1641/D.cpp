#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int N = 1e5 + 5;
int n, m, a[N][5], w[N], b[N];
vector<vector<int>> c[6];
pair<ull, int> mp[N * 12];
long long calc1(int mid) {
	long long ans = 0;
	for (int i = 1, j = n; i <= j; ++i) {
		for (; j && b[i] + b[j] > mid; --j);
		if (i > j) break;
		ans += j - i;
	}
	return ans;
}
long long calc2(int mid) {
	long long ans = 0;
	for (int s = 1; s <= m; ++s) {
		long long cur = 0;
		for (auto &vec : c[s]) {
			int m = vec.size();
			for (int i = 0, j = m - 1; i <= j; ++i) {
				for (; ~j && vec[i] + vec[j] > mid; --j);
				if (i > j) break;
				cur += j - i;
			}
		}
		ans += (s & 1) ? cur : -cur;
	}
	return ans;
}
int main() {
//	freopen("1.in", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < m; ++j)
			cin >> a[i][j];
		cin >> w[i], b[i] = w[i];
		sort(a[i], a[i] + m);
	}
//	cerr << clock() - st << "\n";
	ull coef[5];
	for (int i = 0; i < m; ++i)
		coef[i] = (ull)rnd() << 32 | rnd();
	sort(b + 1, b + n + 1);
	for (int sz = 1; sz <= m; ++sz) {
		int p[12], tot = 0, cnt = 0;
		for (int s = 0; s < 1 << m; ++s)
			if (__builtin_popcount(s) == sz) p[tot++] = s; 
		for (int i = 1; i <= n; ++i) {
			int x = w[i];
			for (int t = 0; t < tot; ++t) {
				ull sum = 0; 
				int s = p[t], cur = 0;
				for (int j = 0; j < m; ++j)
					if (s >> j & 1) sum += coef[cur++] * a[i][j];
				mp[++cnt] = make_pair(sum, x);
			}
		}
		sort(mp + 1, mp + cnt + 1);
		for (int i = 1, j; i <= cnt; i = j + 1) {
			vector<int> v;
			for (j = i; j < cnt && mp[j + 1].first == mp[i].first; ++j);
			for (int x = i; x <= j; ++x)
				v.emplace_back(mp[x].second);
			c[sz].emplace_back(v);
		}
	}
//	cerr << clock() - st << "\n";
	int l = 0, r = 2e9, ans = -1;
	while (l <= r) {
		int mid = (1ll * l + 1ll * r) >> 1;
		if (calc1(mid) > calc2(mid))
			ans = mid, r = mid - 1;
		else
			l = mid + 1;
	}
	cout << ans << "\n";
	return 0;
}