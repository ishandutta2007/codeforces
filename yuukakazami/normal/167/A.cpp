/*
 * a.cpp
 *
 *  Created on: 2012-3-27
 *      Author: mac
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <cmath>
#include <vector>
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define REP(i,n) for(int i=0;i<n;++i)
using namespace std;

double a, d;
int n;

int main() {
	cin >> n >> a >> d;
	vector<double> ans(n);
	for (int i = 0; i < n; ++i) {
		double t, v;
		scanf("%lf%lf", &t, &v);
		double p = v / a;
		double done = v / 2 * p;
		if (done >= d) {
			ans[i] = t + sqrt(d * 2 / a);
		} else {
			ans[i] = t + p + (d - done) / v;
		}
	}
	for (int i = 1; i < n; ++i) {
		ans[i] = max(ans[i], ans[i - 1]);
	}
	for (int i = 0; i < n; ++i) {
		printf("%0.10lf\n", ans[i]);
	}
	return 0;
}