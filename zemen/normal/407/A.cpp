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

inline int gcd(int a, int b) {
	while (a && b)
		if (a >= b)
			a %= b;
		else
			b %= a;
	return a ? a : b;
}

int main() {
	srand(time(0));
	cout.setf(ios::fixed);
	cout.precision(10);
	#ifdef _GEANY
	assert(freopen(NAME ".in", "r", stdin));
	#endif
	int a, b;
	cin >> a >> b;
	a *= a;
	b *= b;
	for (int x = 1; x * x < a; ++x) {
		int ys = a - x * x;
		int y = round(sqrt(ys));
		if (y * y != ys)
			continue;
		assert(x * x + y * y == a);
		int g = gcd(x, y);
		int x1 = x / g;
		int y1 = y / g;
		int d = x1 * x1 + y1 * y1;
		if (b % d != 0)
			continue;
		int b2 = b / d;
		int b1 = round(sqrt(b2));
		if (b1 * b1 != b2)
			continue;
		int x2 = y1 * b1;
		int y2 = x1 * b1;
		//~ cerr << x << ' ' << y << ' ' << x2 << ' ' << y2 << '\n';
		if (x == x2 && y == y2)
			continue;
		int cx, cy;
		if (x == x2) {
			cx = x + x2;
			cy = y - y2;
		} else {
			cx = x - x2;
			cy = y + y2;
		}
		cout << "YES\n";
		cout << 0 << ' ' << 0 << '\n';
		cout << x << ' ' << y << '\n';
		cout << cx << ' ' << cy << '\n';
		return 0;
	}
	cout << "NO\n";
}