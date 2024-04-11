/*
 * b.cpp
 *
 *  Created on: 2011-8-23
 *      Author: mac
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define REP(i,n) for(int i=0;i<n;++i)
using namespace std;
const int MAX_N = 1000 + 10;
int s[MAX_N];

int main() {
	int n, m, h;
	int A = 0;
	cin >> n >> m >> h;
	for (int i = 1; i <= m; ++i) {
		cin >> s[i];
		A += s[i];
	}
	int B = A - s[h];
	--A;
	int x = n - 1;
	double ans = 1;
	if (A < x) {
		cout << -1 << endl;
		return 0;
	}
	if (B < x) {
		cout << 1 << endl;
		return 0;
	}
	for (int i = B + 1; i <= A; ++i) {
		ans /= i;
	}
	for (int i = B - x + 1; i <= A - x; ++i) {
		ans *= i;
	}
	printf("%0.10lf\n", 1 - ans);
	return 0;
}