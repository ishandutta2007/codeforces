#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cassert>
#include <memory.h>

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <list>
#include <complex>

using namespace std;

#define INF 1000000001
#define INFL 1000000000000000001ll
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef long double ld;
typedef complex <ld> point;

#define NAME "b"
#define mod 1000000007

int d[2001][2001];
int p[2001];
int n;

inline int calc(int l, int r) {
	if (d[l][r] != -1)
		return d[l][r];
	if (l == r)
		return d[l][r] = 0;
	if (p[l] == l)
		return d[l][r] = (2 + calc(l + 1, r)) % mod;
	return d[l][r] = (2 + calc(p[l], l) + calc(l + 1, r)) % mod;
}

int main() {
	srand(time(0));
	cout.setf(ios::fixed);
	cout.precision(10);
	#ifdef _GEANY
	assert(freopen(NAME ".in", "r", stdin));
	#endif
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> p[i];
		--p[i];
	}
	for (int i = 0; i <= n; ++i)
		for (int j = 0; j <= n; ++j)
			d[i][j] = -1;
	cout << calc(0, n) << '\n';
}