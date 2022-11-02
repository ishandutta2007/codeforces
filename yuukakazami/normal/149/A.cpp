/*
 * a.cpp
 *
 *  Created on: 2012-2-17
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

int main() {
	int k;
	cin >> k;
	int a[12];
	for (int i = 0; i < 12; ++i) {
		cin >> a[i];
	}
	sort(a, a + 12);
	int cnt = 0;
	for (int i = 12 - 1; i >= 0; --i) {
		if (k <= 0) {
			cout << cnt << endl;
			return 0;
		}
		k -= a[i];
		++cnt;
	}
	if (k <= 0) {
		cout << cnt << endl;
	} else {
		cout << -1 << endl;
	}
	return 0;
}