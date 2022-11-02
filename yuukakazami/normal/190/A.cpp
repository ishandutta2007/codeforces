/*
 * a.cpp
 *
 *  Created on: 2012-6-2
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

int main() {
	int n, m;
	cin >> n >> m;
	if (!n) {
		if (!m)
			cout << 0 << " " << 0 << endl;
		else
			cout << "Impossible" << endl;
	} else {
		cout << max(n, m) << " ";
		if (!m)
			cout << n << endl;
		else
			cout << n + m - 1 << endl;
	}
	return 0;
}