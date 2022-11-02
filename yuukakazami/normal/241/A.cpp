/*
 * cd.cpp
 *
 *  Created on: 2012-11-1
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
int m, k;
const int MAX_N = 1000 + 10;
int d[MAX_N], s[MAX_N];

int main() {
	cin >> m >> k;
	for (int i = 0; i < m; ++i) {
		cin >> d[i];
	}
	for (int i = 0; i < m; ++i) {
		cin >> s[i];
	}
	int maxS = 0;
	int have = 0;
	int ans = 0;
	for (int i = 0; i < m; ++i) {
		have += s[i];
		maxS = max(maxS, s[i]);
		while (have < d[i]) {
			have += maxS;
			ans += k;
		}
		ans += d[i];
		have -= d[i];
		maxS = max(maxS, s[i]);
	}
	cout << ans << endl;
	return 0;
}