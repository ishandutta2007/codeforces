#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include <string.h>
#include <math.h>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <complex>
#include <cassert>

using namespace std;

#define INF __INT_MAX__
#define INFL __LONG_LONG_MAX__
#define pb push_back
#define mp make_pair
#define fi first
#define se second

typedef long long ll;
typedef complex <double> point;

#define NAME "c"
#ifndef NAME
	#error "Write problem name"
#endif

ll gcd(ll a, ll b) {
	while (a != 0 && b != 0)
		if (a > b)
			a %= b;
		else
			b %= a;
	return a ? a : b;
}

int d[1000001];

int calc(int from, int to, int k) {
	fill(d, d + 1000001, INF);
	d[from] = 0;
	for (int i = (int) from; i > to; --i) {
		d[i - 1] = min(d[i] + 1, d[i - 1]);
		for (int j = 2; j <= (int) k; ++j)
			d[i - i % j] = min(d[i - i % j], d[i] + 1);
	}
	return d[to];
}

int main() {
	#ifdef _GEANY
	assert(freopen(NAME ".in", "r", stdin));
	#endif
	ll a, b, k;
	cin >> a >> b >> k;
	ll mod = 1;
	for (int i = 1; i <= k; ++i)
		mod = (mod * i) / gcd(mod, i);
	//~ cerr << mod;
	
	if (a / mod == b / mod) {
		cout << calc(a % mod, b % mod, (int) k);
		return 0;
	}
	
	ll ost = a % mod;
	ll res = calc(a % mod, 0, (int) k);
	a -= ost;
	if (b % mod) {
		res += calc(mod, b % mod, (int) k);
		b = (b / mod + 1) * mod;
	}
	res += (a / mod - b / mod) * calc(mod, 0, (int) k);
	cout << res;
}