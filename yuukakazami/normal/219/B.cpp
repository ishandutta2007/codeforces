/*
 * b.cpp
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
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define REP(i,n) for(int i=0;i<n;++i)
using namespace std;
typedef long long int64;

int main() {
	int64 p, d;
	cin >> p >> d;
	for (int n9 = 18 - 1; n9 >= 0; --n9) {
		int64 v = 0, pw = 1;
		for (int j = 0; j < n9; ++j) {
			v = v * 10 + 9;
			pw = pw * 10;
		}
		//max A*pw+v <= p
		if (p - v < 0)
			continue;
		int64 A = (p - v) / pw;
		int64 x = A * pw + v;
		if (x >= p - d) {
			cout << x << endl;
			return 0;
		}
	}
	return 0;
}