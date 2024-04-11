/*
 * a.cpp
 *
 *  Created on: 2012-4-28
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

int n;
const int MAX_N = int(1e5) + 10;
int a[MAX_N];

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	long long ans = 0;
	for (int i = 0; i < n - 1; ++i) {
		int pw = 1;
		while (i + (pw << 1) < n)
			pw <<= 1;
		ans += a[i];
		a[i + pw] += a[i];
		a[i] = 0;
		cout << ans << endl;
	}
	return 0;
}