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
	int x;
	cin >> x;
	string s;
	cin >> s;
	vector<int> v(x + 1);
	for (size_t i = 0; i < s.size() && i < v.size(); i++)
	{
		v[i] = s[i] - '0';
	}
	int st = 0;
	ll cnt = s.size(), ans = s.size();
	ll mod = 1000000007;
	while (st < x)
	{
		st++;
		if (v[st - 1] == 1)
			continue;
		ll csz = cnt;
		if (cnt < v.size())
			cnt += (cnt - st) * (v[st - 1] - 1);
		(ans += (mod + ans - st) % mod * (v[st - 1] - 1)) %= mod;
		int sz = min(cnt, (ll)v.size());
		if (csz > sz)
			continue;
		for (int tms = 0; tms < v[st - 1] - 1; tms++) {
			for (size_t j = st; j < csz && csz < sz; j++)
			{
				v[csz++] = v[j];
			}
		}
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