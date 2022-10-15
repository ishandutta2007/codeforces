#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cassert>
#include <set>
#include <map>

#define ll long long
#define dbl long double

using namespace std;
int t;


const long long MOD = 998244353;

void solve(int testid) {
	int n;
	cin >> n;
	vector<int> a(n);
	for (size_t i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	ll ans = 0;
	vector<int> v;
	for (size_t i = 0; i < a.size(); i++)
	{
		if (v.empty() || (v.back() - a[i]) % 2) {
			v.push_back(a[i]);
		}
		else {
			ans += (a[i] + v.back()) / 2;
			v.pop_back();
		}
	}
	reverse(v.begin(), v.end());
	for (size_t i = 0; i < v.size(); i += 2)
	{
		if (i + 1 == v.size()) {
			ans += v.back() / 2;
		}
		else {
			ans += (v[i] + v[i + 1]) / 2;
		}
	}
	cout << ans << endl;
}

int main() {
	t = 1;
	// cin >> t;
	for (size_t i = 0; i < t; i++)
	{
		solve(i + 1);
	}
	return 0;
}
/*

*/