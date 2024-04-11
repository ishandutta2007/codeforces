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
ll dist(pair<ll, ll> a, pair<ll, ll> b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}
void solve(int testid) {
	ll x0, y0, ax, bx, ay, by;
	cin >> x0 >> y0 >> ax >> ay >> bx >> by;
	ll xs, ys, t;
	cin >> xs >> ys >> t;
	ll E16 = E9 / 100 * E9;
	vector<pair<ll, ll> > ns;
	for (size_t i = 0; i < 61; i++)
	{
		ns.emplace_back(x0, y0);
		x0 = x0 * ax + bx;
		y0 = y0 * ay + by;
		if (x0 > E16 * 2 || y0 > E16 * 2)
			break;
	}
	vector<vector<ll> > f, b;
	for (size_t i = 0; i < ns.size(); i++)
	{
		ll c = 0;
		f.emplace_back();
		f.back().push_back(c);
		for (int j = i + 1; j < ns.size(); j++) {
			c += dist(ns[j], ns[j - 1]);
			f.back().push_back(c);
		}
		c = 0;
		b.emplace_back();
		b.back().push_back(c);
		for (int j = i - 1; j >= 0; j--) {
			c += dist(ns[j], ns[j + 1]);
			b.back().push_back(c);
		}
	}
	int mc = 0;
	pair<ll, ll> st(xs, ys);
	for (size_t i = 0; i < ns.size(); i++)
	{
		for (size_t j = mc; j < f[i].size(); j++)
		{
			if (dist(st, ns[i]) + f[i][j] <= t) {
				mc = j + 1;
			}
		}
		for (size_t j = mc; j < b[i].size(); j++)
		{
			if (dist(st, ns[i]) + b[i][j] <= t) {
				mc = j + 1;
			}
		}
	}
	cout << mc << endl;
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