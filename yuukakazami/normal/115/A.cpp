/*
 * a.cpp
 *
 *  Created on: 2011-9-15
 *      Author: mac
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define REP(i,n) for(int i=0;i<n;++i)
using namespace std;

int p[3000], d[3000];

int get(int x) {
	if (d[x] != -1)
		return d[x];
	if (p[x] == -1)
		return d[x] = 1;
	return d[x] = get(p[x]) + 1;
}

int main() {
	int n;
	cin >> n;
	memset(d, -1, sizeof d);
	for (int i = 0; i < n; ++i) {
		cin >> p[i], --p[i];
	}
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		ans = max(ans, get(i));
	}
	cout << ans << endl;
	return 0;
}