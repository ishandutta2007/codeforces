#include <bits/stdc++.h>
using namespace std;
bool is_prime[1000005];
int n, e, a[200005];
vector<int> b[200005];
void solve() {
	scanf("%d%d", &n, &e);
	for (int i = 0; i < e; ++i) {
		b[i].clear();
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		b[i % e].emplace_back(a[i]);
	}
	auto solve = [&](vector<int> a) {
		long long res = 0;
		int n = a.size();
		vector<int> pre(n), suf(n);
		pre[0] = (a[0] == 1);
		for (int i = 1; i < n; ++i) {
			pre[i] = (a[i] == 1) ? (pre[i - 1] + 1) : 0;
		} 
		suf[n - 1] = (a[n - 1] == 1);
		for (int i = n - 2; ~i; --i) {
			suf[i] = (a[i] == 1) ? (suf[i + 1] + 1) : 0; 
		}
		for (int i = 0; i < n; ++i) {
			if (a[i] > 1 && is_prime[a[i]]) {
				long long l = (i == 0) ? 1 : (pre[i - 1] + 1);
				long long r = (i == n - 1) ? 1 : (suf[i + 1] + 1);
				res += l * r - 1;
			}
		}
		return res;
	};
	long long ans = 0;
	for (int i = 0; i < e; ++i) {
		ans += solve(b[i]);
	}
	printf("%lld\n", ans);
}
int main() {
	memset(is_prime, true, sizeof is_prime);
	for (int i = 2; i <= 1000000; ++i) {
		for (int j = i + i; j <= 1000000; j += i) {
			is_prime[j] = false;
		}
	}
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}