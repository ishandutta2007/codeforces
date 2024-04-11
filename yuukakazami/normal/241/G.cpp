/*
 * g.cpp
 *
 *  Created on: 2012-11-2
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
int x[510];
double r[510];

double rex(int a, int b) {
	return (x[a] - x[b]) * (x[a] - x[b]) / (4 * r[a]);
}

int main() {
	int n = 500;
	x[1] = 100000;
	r[1] = 356;
	for (int i = 2; i < n - 1; ++i) {
		int a = x[i - 1] + 1;
		for (;;) {
			double t = 1e10;
			for (int j = 1; j < i; ++j) {
				t = min(t, 1.0 * (a - x[j]) * (a - x[j]) / (4 * r[j]));
			}
			if (t < r[i - 1]) {
				x[i] = a;
				r[i] = t;
			} else
				break;
			++a;
		}
	}

	x[0] = 0;
	r[0] = 1e6;
	for (int i = 2; i < n - 1; ++i) {
		r[i] = 1e6;
	}

	x[n - 1] = x[n - 2] + 100000;
	r[n - 1] = 1e6;

//	for (int i = 0; i < n; ++i) {
//		for (int j = 0; j < i; ++j) {
//			r[i] = min(r[i], 1.0 * (x[i] - x[j]) * (x[i] - x[j]) / (4 * r[j]));
//		}
//	}
//	cout << endl;
//	cout << endl;
	cout << n << endl;
	for (int i = 0; i < n; ++i) {
		cout << x[i] << " " << (int) (r[i] + 0.1) << endl;
	}
	return 0;
}