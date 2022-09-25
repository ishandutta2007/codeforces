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

#define NAME "c"

int a[101][101];

void solve(int n, int *a) {
	if (n == 1) {
		a[0] = 1;
		return;
	}
	if (n == 2) {
		a[0] = 3;
		a[1] = 4;
		return;
	}
	for (int i = 0; i <= n; ++i)
		for (int j = 0; i + j <= n; ++j) {
			int s = i + 4 * j + 9 * (n - i - j); 
			int ss = round(sqrt(s));
			if (ss * ss == s) {
				for (int k = 0; k < i; ++k)
					a[k] = 1;
				for (int k = i; k < i + j; ++k)
					a[k] = 2;
				for (int k = i + j; k < n; ++k)
					a[k] = 3;
				return;
			}
		}
	
	cerr << n << '\n';
	//~ assert(0);
}

int main() {
	srand(time(0));
	cout.setf(ios::fixed);
	cout.precision(10);
	#ifdef _GEANY
	assert(freopen(NAME ".in", "r", stdin));
	#endif
	for (int i = 1; i <= 100; ++i)
		solve(i, a[i]);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j)
			cout << a[n][i] * a[m][j] << ' ';
		cout << '\n';
	}
}