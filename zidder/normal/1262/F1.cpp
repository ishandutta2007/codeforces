#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int t;
void yes() {
	cout << "Yes" << endl;
	if (t == 1)
		exit(0);
}

void no() {
	cout << "No" << endl;
	if (t == 1)
		exit(0);
}

const long long MOD = 998244353;

void solve(int test_id) {
	int n, k;
	cin >> n >> k;
	vector<int> h(n);
	for (size_t i = 0; i < n; i++)
		cin >> h[i];
	if (k == 1) {
		cout << 0 << endl;
		return;
	}
	vector<vector<long long > > ans;
	for (size_t i = 0; i < n + 1; i++)
		ans.emplace_back(2 * n + 1);
	// n X n
	ans[0][n] = 1;
	for (size_t i = 0; i < n; i++)
	{
		if (h[i] == h[(i + 1) % n]) {
			for (size_t j = 0; j < 2 * n + 1; j++)
			{
				ans[i + 1][j] = (ans[i][j] * k) % MOD;
			}
		}
		else {
			for (size_t j = 1; j < 2 * n + 1; j++)
			{
				(ans[i + 1][j - 1] += ans[i][j]) %= MOD;
			}
			for (size_t j = 0; j < 2 * n; j++)
			{
				(ans[i + 1][j + 1] += ans[i][j]) %= MOD;
			}
			for (size_t j = 0; j < 2 * n + 1; j++)
			{
				(ans[i + 1][j] += ans[i][j] * (k - 2) % MOD) %= MOD;
			}
		}
	}
	long long answer = 0;
	for (size_t i = n + 1; i < 2 * n + 1; i++)
	{
		(answer += ans[n][i]) %= MOD;
	}
	cout << answer << endl;
}

int main() {
	t = 1;
	//cin >> t;
	for (size_t i = 0; i < t; i++)
	{
		solve(i + 1);
	}
	return 0;
}
/*
1
10 5
()((()()))
*/