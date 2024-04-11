#include <bits/stdc++.h>
using namespace std;
vector<int> a[200005], b[200005];
void exgcd(int a, int b, int &x, int &y) {
	if (b == 0) {
		x = 1;
		y = 0;
		return;
	}
	exgcd(b, a % b, y, x);
	y -= (a / b) * x;
}
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	int g = __gcd(n, m);
	n /= g;
	m /= g;
	if (g > (int) 2e5) {
		puts("-1");
		return 0;
	}
	int in, im;
	exgcd(n, m, in, im);
	in = (in % m + m) % m;
	im = (im % n + n) % n;
	int t;
	scanf("%d", &t);
	while (t--) {
		int x;
		scanf("%d", &x);
		a[x % g].emplace_back(x / g);
	}
	scanf("%d", &t);
	while (t--) {
		int x;
		scanf("%d", &x);
		b[x % g].emplace_back(x / g);
	}
	auto pos = [&](int x, bool type) {
		if (!type) {
			return 1ll * x * im % n;
		} else {
			return 1ll * x * in % m;
		}
	};
	auto solve = [&](vector<int> a, vector<int> b) {
		long long ans = 0;
		vector<pair<int, int>> pa, pb;
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		set<int> sa, sb;
		for (auto x : a) {
			pa.emplace_back(pos(x, false), x);
			sa.insert(x);
		}
		for (auto x : b) {
			pb.emplace_back(pos(x, true), x);
			sb.insert(x);
		}
		for (auto x : a) {
			if (!sb.count(x % m)) {
				pb.emplace_back(pos(x % m, true), x);
				ans = max(ans, (long long) x);
				sb.insert(x % m);
			}
		}
		for (auto x : b) {
			if (!sa.count(x % n)) {
				pa.emplace_back(pos(x % n, false), x);
				ans = max(ans, (long long) x);
				sa.insert(x % n);
			}
		}
		sort(pa.begin(), pa.end());
		sort(pb.begin(), pb.end());
		for (int i = 0; i < (int) pa.size(); ++i) {
			int nxt = (i == (int) pa.size() - 1) ? pa[0].first + n : pa[i + 1].first;
			int dis = nxt - pa[i].first - 1;
			if (dis > 0) {
				ans = max(ans, 1ll * dis * m + pa[i].second);
			}
		}
		for (int i = 0; i < (int) pb.size(); ++i) {
			int nxt = (i == (int) pb.size() - 1) ? pb[0].first + m : pb[i + 1].first;
			int dis = nxt - pb[i].first - 1;
			if (dis > 0) {
				ans = max(ans, 1ll * dis * n + pb[i].second);
			}
		}
		return ans;
	};
	long long ans = 0;
	for (int i = 0; i < g; ++i) {
		if (a[i].empty() && b[i].empty()) {
			puts("-1");
			return 0;
		}
		if ((int) a[i].size() == n && (int) b[i].size() == m) {
			continue;
		} 
		ans = max(ans, solve(a[i], b[i]) * g + i);
	}
	printf("%lld\n", ans);
	return 0;
}