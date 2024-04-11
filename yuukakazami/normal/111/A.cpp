/*
 * a.cpp
 *
 *  Created on: 2011-9-3
 *      Author: mac
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define REP(i,n) for(int i=0;i<n;++i)
using namespace std;

int main() {
	int n;
	long long x, y;
	cin >> n >> x >> y;
	long long me = y - (n - 1);
	if (me <= 0) {
		cout << -1 << endl;
		return 0;
	}
	if ((n - 1) + me * me < x) {
		cout << -1 << endl;
		return 0;
	}
	for (int i = 0; i < n - 1; ++i) {
		cout << 1 << endl;
	}
	cout << me << endl;
	return 0;
}