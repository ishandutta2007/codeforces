/*
 * e.cpp
 *
 *  Created on: 2011-9-11
 *      Author: mac
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <utility>
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define REP(i,n) for(int i=0;i<n;++i)
using namespace std;
int H, M, K;
typedef long long int64;
int64 calc2(int a, int k) {
	for (int i = 0; i < k - 1; ++i) {
		a /= 10;
	}
	return a;
}
int calcDigit(int a) {
	int ret = 0;
	while (a) {
		if (a % 10)
			++ret;
		a /= 10;
	}
	return ret;
}
int64 calc(int h, int m) {
	int d = calcDigit(M - 1);
	int64 ret = calc2(h, K - d);
	ret += calc2(m, K) + h * calc2(M - 1, K);
	return ret;
}

int main() {
	cin >> H >> M >> K;
	int h1, m1, h2, m2;
	cin >> h1 >> m1 >> h2 >> m2;
	if (make_pair(h1, m1) <= make_pair(h2, m2))
		cout << calc(h2, m2) - calc(h1, m1) << endl;
	else
		cout << (calc(H - 1, M - 1) + ((calcDigit(H - 1) + calcDigit(M - 1)) >= K) - calc(h1, m1) + calc(h2, m2)) << endl;
	return 0;
}