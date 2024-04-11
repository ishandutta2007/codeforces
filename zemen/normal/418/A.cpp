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

#define NAME "a"

int main() {
	srand(time(0));
	cout.setf(ios::fixed);
	cout.precision(10);
	#ifdef _GEANY
	assert(freopen(NAME ".in", "r", stdin));
	#endif
	int n, k;
	cin >> n >> k;
	if (k * 2 > n - 1) {
		cout << -1 << '\n';
		return 0;
	}
	cout << k * n << '\n';
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < k; ++j) {
			cout << i + 1 << ' ' << (i + j + 1) % n + 1 << '\n';
		}
}