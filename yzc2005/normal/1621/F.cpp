#include <bits/stdc++.h>
using namespace std;
int n, a, b, c, x[100005];
char s[100005];
void solve() {
	scanf("%d%d%d%d", &n, &a, &b, &c);
	scanf("%s", s + 1);
	int cnt1 = 0, cur = 0, m = 0;
	for (int i = 1; i <= n; ++i) {
		if (s[i] == '1') {
			if (s[i - 1] != '1') {
				x[++m] = cur;
				cur = 0;
			} else {
				++cnt1;
			}
		} else {
			++cur;
		}
	}
	x[++m] = cur;
	int cnt0 = 0;
	for (int i = 1; i <= m; ++i)
		cnt0 += max(0, x[i] - 1);
	auto solve = [&]() {
		int cnt = min(cnt0, cnt1);
		long long ans = 1ll * cnt * (a + b);
		if (b > c) {
			int rest = cnt1 - cnt;
			vector<int> v;
			for (int i = 2; i < m; ++i)
				v.emplace_back(x[i]);
			sort(v.begin(), v.end());
			priority_queue<int, vector<int>, greater<int>> pq;
			for (auto x : v) {
				int val = min(x - 1, cnt);
				cnt -= val;
				pq.emplace(x - val);
			}
			while (!pq.empty()) {
				int x = pq.top();
				pq.pop();
				if (x == 1) {
					++rest;
				} else {
					pq.emplace(x - 1);
				}
				if (!rest) break;
				ans += b - c;
				--rest;
			}
			ans += 1ll * (b - c) * min(rest, min(x[1], 1) + min(x[m], 1));
		}
		if (cnt0 > cnt1) ans += a;
		return ans;
	};
	long long ans = solve();
	if (cnt1) {
		--cnt1;
		ans = max(ans, solve() + b);
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