#include <bits/stdc++.h>
using namespace std;
const int P = 998244353;
int n, m, ans, p2[150005];
int get(int x, int y) {
	int ans = p2[x + y];
	ans = (ans - p2[x] - p2[y] + 1) % P;
	return (ans + P) % P;
}
int solve(vector<int> a, vector<int> b, int k) {
	if (a.size() > b.size()) {
		swap(a, b);
	}
	if (a.empty()) {
		return p2[b.size()] - 1;
	}
	if (k == -1) {
		return p2[a.size() + b.size()] - 1;
	}
	vector<int> a0, a1;
	for (auto x : a) {
		if (x >> k & 1) {
			a1.emplace_back(x);
		} else {
			a0.emplace_back(x);
		}
	}	
	vector<int> b0, b1;
	for (auto x : b) {
		if (x >> k & 1) {
			b1.emplace_back(x);
		} else {
			b0.emplace_back(x);
		}
	}
	if (m >> k & 1) {
		int x = solve(a0, b1, k - 1), y = solve(a1, b0, k - 1);
		return (1ll * x * y + x + y) % P;
	} else {
		int ans = (solve(a0, b0, k - 1) + solve(a1, b1, k - 1)) % P;
		ans = (ans + get(a0.size(), a1.size())) % P;
		ans = (ans + get(b0.size(), b1.size())) % P;
		return ans;
	}
}
void solve(vector<int> a, int k) {
	if (a.empty()) {
		return;
	}
	if (k == -1) {
		ans = (ans + p2[a.size()] - 1) % P;
		return;
	}
	vector<int> a0, a1;
	for (auto x : a) {
		if (x >> k & 1) {
			a1.emplace_back(x);
		} else {
			a0.emplace_back(x);
		}
	}
	if (m >> k & 1) {
		ans = (ans + solve(a0, a1, k - 1)) % P;
	} else {
		solve(a0, k - 1);
		solve(a1, k - 1);
	}
}
int main() {
	cin >> n >> m;
	vector<int> a(n);
	p2[0] = 1;
	for (int i = 1; i <= n; ++i) {
		p2[i] = p2[i - 1] * 2 % P;
	}
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	solve(a, 29);
	cout << ans << "\n";
	return 0;
}