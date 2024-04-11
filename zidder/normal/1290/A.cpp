#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cassert>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>

#define ll long long
#define dbl long double

using namespace std;

const long long MOD = 998244353;
const int N = 200000 + 5;
const ll E9 = 1000 * 1000ll * 1000;
int t;

void solve(int testid) {
	int n, m, k;
	cin >> n >> m >> k;
	k = min(k, m - 1);
	vector<int> a(n);
	for (size_t i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int ans = 0;
	for (size_t i = 0; i <= k; i++)
	{
		int x = E9;
		for (size_t j = 0; j < m - k; j++)
		{
			x = min(x, max(a[i + j], a[n - m + i + j]));
		}
		ans = max(x, ans);
	}
	cout << ans << endl;
}

int main() {
	t = 1;
	cin >> t;
	for (size_t i = 0; i < t; i++)
	{
		solve(i + 1);
	}
	return 0;
}
/*

*/