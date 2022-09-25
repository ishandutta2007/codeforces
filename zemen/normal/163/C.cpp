/*		c.cpp
 *		Created on: 25.03.2012
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

ll buf[200005];
ld ver[100001];
ll *a = buf + 1;

void solve() {
	fill(ver, ver + 100001, 0);
	ll n, l, v1, v2;
	cin >> n >> l >> v1 >> v2;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	for (int i = n; i < 2 * n; ++i)
		a[i] = a[i - n] + 2 * l;
	a[2 * n] = INF;
	a[-1] = a[n] - 2 * l;
	ld l1 = (ld) (v2 * l) / (ld) (v1 + v2);
	int b = 0, e = 1;
	ld c = a[0];
	while ((a[e] - a[b]) < l1)
		++e;
	while (c < a[n]) {
		if ((ld) a[e] - c - l1 < (ld) a[b] - c) {
			//ADD
			ver[e - b] += ((ld) a[e] - c - l1) / (ld) (2 * l);
			c = (ld) a[e] - l1;
			while ((ld) a[b] < c)
				++b;
			++e;
		} else {
			//REMOVE
			ver[e - b] += ((ld) a[b] - c) / (ld) (2 * l);
			c = (ld) a[b];
			while ((ld) a[e] < c + l1)
				++e;
			++b;
		}
	}
	cout.precision(15);
	for (int i = 0; i <= n; ++i)
		cout << ver[i] << endl;
}