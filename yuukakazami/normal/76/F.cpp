/*
 * F. Tourist.cpp
 *
 *  Created on: 2011-4-12
 *      Author: user
 */

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>
#include <utility>
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
using namespace std;

const int MAX_N = 100000 + 10;
int n;
typedef pair<int, int> ipair;

struct TA {
	int a[MAX_N], n;

	void init(int _n) {
		n = _n;
		memset(a, 0, sizeof a);
	}

	void update(int p, int x) {
		for (p++; p <= n; p += p & -p)
			a[p - 1] = max(a[p - 1], x);
	}

	int ask(int p) {
		int ret = 0;
		for (p++; p > 0; p -= p & -p)
			ret = max(ret, a[p - 1]);
		return ret;
	}
};

ipair ps[MAX_N];
int ret[MAX_N];

void solve(int n) {
	static int comp[MAX_N];
	int cnt = 0;
	sort(ps, ps + n);
	for (int i = 0; i < n; ++i) {
		comp[i] = ps[i].second;
	}
	cnt = n;
	sort(comp, comp + cnt);
	cnt = unique(comp, comp + cnt) - comp;

	static TA ta;
	ta.init(cnt);

//	for (int i = 0; i < n; ++i) {
//		cout << ps[i].first << " " << ps[i].second << endl;
//	}

	for (int i = 0; i < n; ++i) {
		int at = lower_bound(comp, comp + cnt, ps[i].second) - comp;
		ret[i] = ta.ask(at) + 1;
//		cout << at << endl;
		ta.update(at, ret[i]);
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int t, x;
		scanf("%d%d", &x, &t);
		ps[i] = make_pair(x, t);
	}
	ps[n] = make_pair(0, 0);
	int V;
	scanf("%d", &V);
	for (int i = 0; i <= n; ++i) {
		ps[i].second *= V;
		int x = ps[i].first, t = ps[i].second;
		ps[i].first = t - x, ps[i].second = t + x;
		ps[i].first *= -1;
		ps[i].second *= -1;
	}
	solve(n);
	int ans2 = *max_element(ret, ret + n);

	int ans1;
	ipair st = ps[n];
	solve(n + 1);
	int at = lower_bound(ps, ps + n + 1, st) - ps;
	ans1 = ret[at] - 1;

	cout << ans1 << " " << ans2 << endl;
}