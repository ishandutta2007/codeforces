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

vector<ll> vx, vy;

void solve(int testid) {
	cin >> n;
	vx = vector<ll>(n);
	vy = vector<ll>(n);
	set<pair<ll, ll> > st;
	for (size_t i = 0; i < n; i++)
		cin >> vx[i] >> vy[i];
	ll sx = 0, sy = 0;
	for (size_t i = 0; i < n; i++)
	{
		st.emplace(vx[i], vy[i]);
		sx += vx[i];
		sy += vy[i];
	}
	bool ok = true;
	if (2 * sx % n != 0 || 2 * sy % n != 0)
		ok = false;
	ll mx = 2 * sx / n, my = 2 * sy / n;

	for (size_t i = 0; ok && i < n; i++)
	{
		pair<ll, ll> p(mx - vx[i], my - vy[i]);
		if (st.count(p) == 0)
			ok = false;
	}
	if (ok)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
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