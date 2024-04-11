#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cassert>
#include <set>
#include <unordered_set>
#include <map>

#define ll long long
#define dbl long double

using namespace std;

const long long MOD = 998244353;
const int N = 200000 + 5;
int t;

pair<int, int> ask(int n, int x) {
	cout << "? ";
	for (size_t i = 0; i < n; i++)
	{
		if (i == x)
			continue;
		cout << i + 1 << " ";
	}
	cout << endl;
	fflush(stdout);
	int p, a;
	cin >> p >> a;
	return{ p, a };
}

void solve(int testid) {
	int k, n;
	cin >> n >> k;
	n = k + 1;
	map<pair<int, int>, int> mp;
	for (size_t i = 0; i < n; i++)
		mp[ask(n, i)]++;
	vector<pair<int, int> > sz;
	for (auto p : mp)
		sz.emplace_back(p.first.second, p.second);
	sort(sz.begin(), sz.end());
	cout << "! " << sz[1].second << endl;
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