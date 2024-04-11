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

#define NAME "e"

double get(double a, double b) {
	double c = sqrt((a * a) / 4.0 + b * b);
	double s = (a * b) / 2;
	return s / c;
}

int main() {
	srand(time(0));
	cout.setf(ios::fixed);
	cout.precision(10);
	#ifdef _GEANY
	assert(freopen(NAME ".in", "r", stdin));
	#endif
	double x;
	cin >> x;
	//~ cerr << get(9, 9) << '\n';
	for (int a = 1; a <= 10; ++a)
		for (int b = 1; b <= 10; ++b) {
			if (fabs(get(a, b) - x) < 1e-4) {
				cout << a << ' ' << b << '\n';
				return 0;
			}
		}
}