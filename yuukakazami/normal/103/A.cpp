/*
 * a.cpp
 *
 *  Created on: 2011-8-7
 *      Author: mac
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define REP(i,n) for(int i=0;i<n;++i)
using namespace std;
typedef long long int64;

int main() {
	int64 a[1000];
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	int64 sum = 0;
	int64 ret = 0;
	for (int i = 0; i < n; ++i) {
		int64 bad = a[i] - 1;
		ret += 1;
		ret += bad * (i + 1);
	}
	cout << ret << endl;
	return 0;
}