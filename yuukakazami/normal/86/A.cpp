/*
 * A. Reflection.cpp
 *
 *  Created on: 2011-5-23
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
int64 POW10[20];

int64 calc(int64 x) {
	int len = 0;
	int am = x;
	while (am)
		am /= 10, ++len;
	return 1LL * x * (POW10[len] - 1 - x);
}

int64 solve(int64 L, int64 R) {
	while (R - L > 5) {
		int unit = (R - L) / 3;
		int64 M1 = L + unit, M2 = R - unit;
		if (calc(M1) < calc(M2))
			L = M1;
		else
			R = M2;
	}

	int64 ret = 0;
	for (int i = L; i <= R; ++i) {
		ret = max(ret, calc(i));
	}
	return ret;
}

int main() {
	POW10[0] = 1;
	for (int i = 1; i < 20; ++i) {
		POW10[i] = POW10[i - 1] * 10;
	}
	int64 l, r;
	cin >> l >> r;
	int64 ret = 0;
	for (int len = 0; len <= 10; ++len) {
		int64 L = POW10[len], R = POW10[len + 1] - 1;
		L = max(l, L);
		R = min(R, r);
		if (L <= R) {
			ret = max(ret, solve(L, R));
		}
	}
	cout << ret << endl;
}