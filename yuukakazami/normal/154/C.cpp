/*
 * c.cpp
 *
 *  Created on: 2012-2-24
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
const int SEED = 13331;
const int MAX_N = int(1e6) + 10;
ll pw[MAX_N];
ll my[MAX_N];
int n, m, cnt;
ll all[MAX_N * 2];

int calc(ll x) {
	return upper_bound(all, all + cnt, x) - lower_bound(all, all + cnt, x);
}

int main() {
	cin >> n >> m;
	pw[0] = 1;
	for (int i = 1; i < n; ++i) {
		pw[i] = pw[i - 1] * SEED;
	}
	memset(my, 0, sizeof my);
	for (int i = 0; i < m; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		--a, --b;
		my[a] += pw[b];
		my[b] += pw[a];
	}
	cnt = 0;
	for (int i = 0; i < n; ++i) {
		all[cnt++] = my[i] + pw[i];
		all[cnt++] = my[i];
	}
	sort(all, all + cnt);
	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		ans += calc(my[i]) - 1;
		ans += calc(my[i] + pw[i]) - 1;
	}
	cout << ans / 2 << endl;
	return 0;
}