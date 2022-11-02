/*
 * c.cpp
 *
 *  Created on: 2012-3-25
 *      Author: mac
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
#include <utility>
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define REP(i,n) for(int i=0;i<n;++i)
using namespace std;

int n;
double len, v1, v2;

int main() {
	cin >> n >> len >> v1 >> v2;
	double p = v2 / (v1 + v2);

	vector<pair<double, int> > es;

	for (int i = 0; i < n; ++i) {
		int a;
		scanf("%d", &a);
		double t = a;
		double l = t - len * p, r = t;
		if (l >= 0) {
			es.push_back(make_pair(l, 1));
			es.push_back(make_pair(r, -1));
		} else {
			es.push_back(make_pair(l + 2 * len, 1));
			es.push_back(make_pair(2 * len, -1));
			es.push_back(make_pair(0, 1));
			es.push_back(make_pair(r, -1));
		}
	}

	es.push_back(make_pair(0, 0));
	es.push_back(make_pair(2 * len, 0));

	int cnt = 0;
	sort(es.begin(), es.end());

	vector<double> ans(n + 1, 0);

	for (int i = 0; i < es.size(); ++i) {
		if (i > 0) {
			ans[cnt] += es[i].first - es[i - 1].first;
		}
		cnt += es[i].second;
	}

	for (int i = 0; i <= n; ++i) {
		ans[i] /= len * 2;
	}

	for (int i = 0; i <= n; ++i) {
		printf("%0.10lf\n", ans[i]);
	}
	return 0;
}