/*		a.cpp
 *		Created on: 27.03.2012
 *      Author: zemen
 */

#include <algorithm>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

#define mp make_pair
#define INF __INT_MAX__
#define PI M_PIl

typedef long long ll;
typedef long double ld;
typedef complex <ld> point;

void solve();

int main() {
#ifndef LOCAL_BUILD
	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	int n = 1;
	for (int i = 0; i < n; ++i)
		solve();
}

void solve() {
	int n;
	ld v, t, a, d;
	cin >> n >> a >> d;
	ld tmax = -INF;
	cout.precision(15);
	for (int i = 0; i < n; ++i) {
		cin >> t >> v;
		ld tres = t;
		ld t1 = v / a;
		ld s1 = a * t1 * t1 / 2;
		if (s1 >= d)
			tres += sqrtl(2 * d / a);
		else {
			tres += t1 + (d - s1) / v;
		}
		tmax = max(tmax, tres);
		cout << tmax << endl;
	}
}