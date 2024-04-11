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
	cin >> n;
	v = vector<ll>(n);
	li = vector<ll>(n);
	pv.push_back(0);
	ll s = 0;
	for (size_t i = 0; i < n; i++) {
		scanf("%ld", &v[i]);
		pv.push_back(s += v[i]);
	}
	for (int i = n - 1; i >= 0; --i) {
		li[i] = i + 1;
		while (li[i] < n) {
			int r = li[li[i]];
			if ((pv[li[i]] - pv[i]) * (r - li[i]) > (pv[r] - pv[li[i]]) * (li[i] - i)) {
				li[i] = r;
			}
			else
				break;
		}
	}
	int r = 0, l = 0;;
	for (size_t i = 0; i < n; i++)
	{
		if (i == r) {
			r = li[i];
			l = i;
		}
		dbl d = (pv[r] - pv[l]) * (dbl)1. / (r - l);
		printf("%.9LF\n", d);
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
10
1 9 5 7 6 1 3 4 1 1

*/