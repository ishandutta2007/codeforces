/*
 * a.cpp
 *
 *  Created on: 2012-8-31
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
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	vector<int> b = a;
	sort(b.begin(), b.end());
	int cntDiff = 0;
	for (int i = 0; i < n; ++i) {
		if (a[i] != b[i])
			++cntDiff;
	}
	if (cntDiff <= 2)
		puts("YES");
	else
		puts("NO");
	return 0;
}