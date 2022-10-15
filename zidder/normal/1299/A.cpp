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

int n;

vector<ll> v, pv, li;

void solve(int testid) {
	int n;
	cin >> n;
	v = vector<ll>(n);
	for (size_t i = 0; i < n; i++)
		cin >> v[i];
	vector<int> Q(35, 0);
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < 33; j++)
		{
			ll x = (1 << j);
			if (v[i] & x)
				Q[j]++;
		}
	}
	ll maxn = 0, maxv = 0;
	for (size_t i = 0; i < n; i++)
	{
		ll val = v[i];
		for (size_t j = 0; j < 33; j++)
		{
			ll x = (1 << j);
			if ((v[i] & x) > 0 && Q[j] > 1)
				val ^= x;
		}
		if (val > maxv)
		{
			maxv = val;
			maxn = i;
		}
	}
	cout << v[maxn] << " ";
	for (size_t i = 0; i < n; i++)
	{
		if (i == maxn)
			continue;
		cout << v[i] << " ";
	}
	cout << endl;
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
10
1 9 5 7 6 1 3 4 1 1

*/