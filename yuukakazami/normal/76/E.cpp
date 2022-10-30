/*
 * E. Points.cpp
 *
 *  Created on: 2011-4-12
 *      Author: user
 */

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
using namespace std;

typedef long long int64;

int64 calc(int a[], int n) {
	int64 s2 = 0, s1 = 0;
	int64 ret = 0;
	for (int i = 0; i < n; ++i) {
		ret += 1LL * i * a[i] * a[i] + s2 - s1 * 2LL * a[i];
		s2 += 1LL * a[i] * a[i];
		s1 += a[i];
	}

	return ret;
}

int x[100000], y[100000];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", x + i, y + i);
	}
	int64 ret = 0;
	ret += calc(x, n);
	reverse(x, x + n);
	ret += calc(x, n);

	ret += calc(y, n);
	reverse(y, y + n);
	ret += calc(y, n);

	cout << ret / 2 << endl;
}