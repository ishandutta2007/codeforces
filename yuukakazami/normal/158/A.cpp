/*
 * a.cpp
 *
 *  Created on: 2012-3-4
 *      Author: mac
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define REP(i,n) for(int i=0;i<n;++i)
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		if (a[i] > 0 && a[i] >= a[k - 1])
			++cnt;
	}

	cout << cnt << endl;
	return 0;
}