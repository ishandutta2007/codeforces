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
	if (n / 2 > k) {
		cout << -1 << '\n';
		return 0;
	}
	if (n == 1) {
		if (k == 0)
			cout << 1 << '\n';
		else
			cout << -1 << '\n';
		return 0;
	}
	int x = k - n / 2 + 1;
	cout << x << ' ' << 2 * x << ' ';
	int rem = n - 2;
	for (int i = 2 * x + 1; rem > 0; ++i) {
		cout << i << ' ';
		--rem;
	}
	cout << '\n';
}