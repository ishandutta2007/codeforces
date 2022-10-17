#include <bits/stdc++.h>
using namespace std;
void solve(vector<int> v) {
	int n = v.size();
	assert(n % 2 == 1);
	vector<int> v1, v2;
	for (int i = 0; i < n; ++i) {
		if (i < n / 2) v1.emplace_back(v[i]);
		else v2.emplace_back(v[i]);
	}
	for (int i = 0; i < (int) v1.size(); ++i)
		cout << v1[i] << " " << v1[(int) v1.size() - 1 - i] << "\n";
	for (int i = 0; i < (int) v2.size(); ++i)
		cout << v2[i] << " " << v2[(int) v2.size() - 1 - i] << "\n";
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	if (n == 1) {
		cout << "1\n" << "1 1\n";
		return 0;
	}
	int k = (2 * n + 1) / 3;
	cout << k << "\n";
	int a = (k - 1) / 2 + 1, b = k / 2 + 1;
	if (n - a == n - b) {
		vector<int> v;
		for (int i = a + 1; i <= n; ++i)
			v.emplace_back(i);
		if (k > n - a) {
			v.pop_back();
			solve(v);
			cout << n << " " << n - k / 2 << "\n";
			cout << n - k / 2 << " " << n << "\n";	
		} else {
			solve(v);
		}
	} else {
		assert((n - b) % 2 == 1);
		vector<int> v;
		for (int i = b + 1; i <= n; ++i)
			v.emplace_back(i);
		solve(v);
		cout << b << " " << b + k / 2 << "\n";
	}
	return 0;
}