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

double p[1001];

int main() {
	srand(time(0));
	cout.setf(ios::fixed);
	cout.precision(10);
	#ifdef _GEANY
	assert(freopen(NAME ".in", "r", stdin));
	#endif
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> p[i];
	sort(p, p + n);
	reverse(p, p + n);
	double p0 = 1, p1 = 0;
	for (int i = 0; i < n; ++i) {
		p1 -= p1 * p[i];
		p1 += p0 * p[i];
		p0 -= p0 * p[i];
		if (p0 <= p1)
			break;
	}
	cout << p1 << '\n';
}