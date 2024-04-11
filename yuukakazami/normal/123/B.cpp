/*
 * code2.cpp
 *
 *  Created on: 2011-11-3
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

int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}

typedef long long int64;

int64 ABS(int64 x) {
	return x > 0 ? x : -x;
}

int main() {
	int64 a, b, x1, y1, x2, y2;
	cin >> a >> b >> x1 >> y1 >> x2 >> y2;
	int64 ans = 0;
	{
		int64 A = x1 + y1, B = x2 + y2;
		A += int64(1e9) * (2 * a);
		B += int64(1e9) * (2 * a);
		A /= 2 * a;
		B /= 2 * a;
		ans = max(ans, ABS(A - B));
	}
	{
		int64 A = x1 - y1, B = x2 - y2;
		A += int64(1e9) * (2 * b);
		B += int64(1e9) * (2 * b);
		A /= 2 * b;
		B /= 2 * b;
		ans = max(ans, ABS(A - B));
	}
	cout << ans << endl;
	return 0;
}