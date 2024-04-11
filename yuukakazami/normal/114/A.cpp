/*
 * a.cpp
 *
 *  Created on: 2011-9-15
 *      Author: mac
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define REP(i,n) for(int i=0;i<n;++i)
using namespace std;

int main() {
	long long a, b;
	cin >> a >> b;
	long long cur = 1;
	for (int i = 1;; ++i) {
		cur *= a;
		if (cur == b) {
			cout << "YES" << endl;
			cout << i - 1 << endl;
			return 0;
		}
		if (cur > b)
			break;
	}
	cout << "NO" << endl;
	return 0;
}