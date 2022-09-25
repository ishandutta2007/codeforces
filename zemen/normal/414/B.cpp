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

inline void add(int &a, int b) {
	a += b;
	if (a >= b)
		a %= mod;
}

int main() {
	srand(time(0));
	cout.setf(ios::fixed);
	cout.precision(10);
	#ifdef _GEANY
	assert(freopen(NAME ".in", "r", stdin));
	#endif
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; ++i)
		d[1][i] = 1;
	for (int i = 1; i < k; ++i) {
		for (int j = 1; j <= n; ++j)
			for (int k = j; k <= n; k += j)
				add(d[i + 1][k], d[i][j]);
	}
	int res = 0;
	for (int i = 1; i <= n; ++i)
		add(res, d[k][i]);
	cout << res << '\n';
}