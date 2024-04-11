/*
 * b.cpp
 *
 *  Created on: 2012-3-11
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

int n, k;
const int MAX_N = int(1e3) + 10;
vector<pair<int, int> > stool, pencil;

int main() {
	cin >> n >> k;
	vector<double> v;
	for (int i = 0; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		v.push_back(a);
		if (b == 1)
			stool.push_back(make_pair(a, i));
		else
			pencil.push_back(make_pair(a, i));
	}
	sort(stool.begin(), stool.end());
	reverse(stool.begin(), stool.end());
	sort(pencil.begin(), pencil.end());
	vector<int> who[MAX_N];
	int cnt = 0;
	for (int i = 0; i < stool.size() && i < k; ++i) {
		who[i].push_back(stool[i].second);
		++cnt;
	}
	if (stool.size() < k) {
		int at = stool.size();
		for (int i = 0; i < pencil.size(); ++i) {
			who[at].push_back(pencil[i].second);
			++at;
			if (at >= k)
				--at;
		}
	} else {
		for (int i = k; i < stool.size(); ++i) {
			who[k - 1].push_back(stool[i].second);
		}
		for (int i = 0; i < pencil.size(); ++i) {
			who[k - 1].push_back(pencil[i].second);
		}
	}

	double ans = accumulate(v.begin(), v.end(), 0.0);
	for (int i = 0; i < k; ++i) {
		if (i < cnt) {
			double minv = 1e100;
			for (vector<int>::iterator e = who[i].begin(); e != who[i].end(); ++e) {
				minv = min(minv, v[*e]);
			}
			ans -= minv / 2;
		}
	}

	printf("%0.1lf\n", ans);
	for (int i = 0; i < k; ++i) {
		cout << who[i].size();
		for (vector<int>::iterator e = who[i].begin(); e != who[i].end(); ++e) {
			cout << " " << *e + 1;
		}
		cout << endl;
	}
	return 0;
}