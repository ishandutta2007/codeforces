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
	string s;
	cin >> s;
	int q;
	cin >> q;
	vector<vector<int> > v(s.size() + 1, vector<int>(26));
	for (size_t i = 0; i < s.size(); i++)
	{
		v[i + 1] = v[i];
		v[i + 1][s[i] - 'a']++;
	}
	for (size_t i = 0; i < q; i++)
	{
		int l, r;
		cin >> l >> r;
		l--; r;
		bool ok = (l + 1 == r);
		int c = 0;
		for (size_t i = 0; i < 26; i++)
			c += (v[r][i] - v[l][i] == 0);
		ok |= c != 25 && (c != 24 || s[l] != s[r - 1]);

		if (ok)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
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