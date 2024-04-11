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

void solve(int testid) {
	int n;
	cin >> n;
	ll sm = 0, sx = 0;
	for (size_t i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		sm += x;
		sx ^= x;
	}
	vector<ll> ans;
	ans.push_back(sx);
	sm += sx;
	ans.push_back(sm);
	cout << ans.size() << endl;
	sx = 0;
	for (size_t i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << " ";
		sx ^= ans[i];
	}
	cout << endl;
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