#include <bits/stdc++.h>
using namespace std;
const int N = 5005;
int n, a[N];
long long solve(vector<int> a) {
	long long last = 0, ans = 0;
	for (auto x : a) {
		long long cur = (last / x + 1) * x;
		ans += last / x + 1;
		last = cur;
	}
	return ans;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	long long ans = 1e18;
	for (int i = 1; i <= n; ++i) {
		long long cur = 0;
		vector<int> b;
		for (int j = i - 1; j; --j)
			b.emplace_back(a[j]);
		cur += solve(b);
		b.clear();
		for (int j = i + 1; j <= n; ++j)
			b.emplace_back(a[j]);
		cur += solve(b);
		ans = min(ans, cur);
	}
	cout << ans << "\n";
	return 0;
}