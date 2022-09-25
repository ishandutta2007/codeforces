/*		b.cpp
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

pair <int, pair <int, int> > a[100001];
int res[100001];
int cres[100001];
int cresc;

void solve() {
	int n, k, h;
	cin >> n >> k >> h;
	for (int i = 0; i < n; ++i)
		cin >> a[i].first;
	for (int i = 0; i < n; ++i)
		cin >> a[i].second.first;
	for (int i = 0; i < n; ++i)
		a[i].second.second = i;
	sort(a, a + n);
	ld mintime = 0;
	ld maxtime = h * n;
	for (int ii = 0; ii < 90; ++ii) {
		ld t = (maxtime + mintime) / 2;
		cresc = 0;
		for (int i = n - 1; i >= 0; --i) {
			ld len = (ld) ((k - cresc) * h);
			if (len <= t * a[i].second.first) {
				//YES!
				cres[cresc++] = a[i].second.second;
				if (cresc == k)
					break;
			}
		}
		if (cresc == k) {
			maxtime = t;
			memcpy(res, cres, sizeof(int) * k);
		} else
			mintime = t;
	}
	for (int i = k - 1; i >= 0; --i)
		cout << res[i] + 1 << ' ';
}