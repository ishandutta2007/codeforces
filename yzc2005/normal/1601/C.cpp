#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
int n, a[N], m, b[N];
int t, c[N];
void modify(int p) {
	for (; p <= t; p += p & -p)
		++c[p];
}
int query(int p) {
	int res = 0;
	for (; p; p -= p & -p)
		res += c[p];
	return res;
}
long long calc() {
	long long delta = 0;
	priority_queue<int> pq;
	for (int i = 1; i <= n; ++i) {
		int p1 = lower_bound(b + 1, b + m + 1, a[i]) - b - 1;
		int p2 = upper_bound(b + 1, b + m + 1, a[i]) - b - 1;
		delta += p1;
		pq.emplace(p1);
		pq.emplace(p2);
		while (pq.size() > i) pq.pop();
	}
	long long slope = n - int(pq.size()) + 1;
	long long ans = 0;
	while (!pq.empty()) {
		int cur = pq.top();
		pq.pop();
		int prv = pq.empty() ? 0 : pq.top();
		ans -= (cur - prv) * slope;
		++slope;
	}
	ans += delta;
	return ans;
}
void solve() {
	scanf("%d%d", &n, &m);
	vector<int> p;
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]), p.emplace_back(a[i]);
	for (int i = 1; i <= m; ++i)
		scanf("%d", &b[i]), p.emplace_back(b[i]);
	sort(p.begin(), p.end());
	auto g = [&](int x) {
		return lower_bound(p.begin(), p.end(), x) - p.begin() + 1;
	};
	t = int(p.size());
	memset(c + 1, 0, t * 4);
	long long ans = 0;
	for (int i = 1; i <= n; ++i) {
		a[i] = g(a[i]);
		ans += query(t - a[i] + 1 - 1);
		modify(t - a[i] + 1);
	}
	for (int i = 1; i <= m; ++i)
		b[i] = g(b[i]);
	sort(b + 1, b + m + 1);
	ans += calc();
	printf("%lld\n", ans);
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--) solve();
	return 0;
}