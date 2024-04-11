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

#define NAME "a"
#ifndef NAME
	#error "Write problem name"
#endif

int a[100001];

int main() {
	#ifdef _GEANY
	assert(freopen(NAME ".in", "r", stdin));
	#endif
	int n, d;
	cin >> n >> d;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	int lb = 0;
	ll res = 0;
	for (int rb = 1; rb < n; ++rb) {
		while (a[rb] - a[lb] > d)
			++lb;
		ll cnt = (ll) rb - (ll) lb;
		res += (cnt * (cnt - 1)) / 2;
	}
	cout << res;
}