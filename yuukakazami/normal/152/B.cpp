/*
 * cd.cpp
 *
 *  Created on: 2012-3-1
 *      Author: mac
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define REP(i,n) for(int i=0;i<n;++i)
using namespace std;

typedef long long ll;
ll n, m;

bool in(ll x, ll y) {
	return x >= 1 && x <= n && y >= 1 && y <= m;
}

int main() {
	cin >> n >> m;
	ll cx, cy;
	cin >> cx >> cy;
	ll ans = 0;
	int k;
	cin >> k;
	for (int i = 0; i < k; ++i) {
		ll dx, dy;
		cin >> dx >> dy;
		for (ll step = 1LL << 30; step > 0; step >>= 1) {
			ll nx = cx + dx * step, ny = cy + dy * step;
			if (in(nx, ny)) {
				cx = nx, cy = ny;
				ans += step;
			}
		}
	}
	cout << ans << endl;
	return 0;
}