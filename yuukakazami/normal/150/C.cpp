/*
 * c.cpp
 *
 *  Created on: 2012-2-17
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
const int MAX_N = 150000 + 10;
int n, m, c;
int x[MAX_N], p[MAX_N];
double v[MAX_N];

struct Info {
	double sum;
	double op, mxl, mxr;
	bool empty;
	Info(double x) {
		empty = false;
		sum = x;
		op = mxl = mxr = max(x, 0.0);
	}
	Info() {
		empty = true;
	}
};

Info operator+(Info L, Info R) {
	if (L.empty)
		return R;
	if (R.empty)
		return L;
	Info r;
	r.empty = false;
	r.sum = L.sum + R.sum;
	r.mxl = max(L.mxl, L.sum + R.mxl);
	r.mxr = max(R.mxr, R.sum + L.mxr);
	r.op = max(max(L.op, R.op), L.mxr + R.mxl);
	return r;
}

struct Tree {
	int l, r;
	Tree*pl, *pr;
	Info i;

	void update() {
		i = pl->i + pr->i;
	}

	Tree(double v[], int _l, int _r) :
			l(_l), r(_r) {
		if (l + 1 == r) {
			i = Info(v[l]);
			return;
		}
		int m = (l + r) >> 1;
		pl = new Tree(v, l, m);
		pr = new Tree(v, m, r);
		update();
	}

	Info ask(int L, int R) {
		if (L >= r || l >= R)
			return Info();
		if (L <= l && R >= r)
			return i;
		return pl->ask(L, R) + pr->ask(L, R);
	}
};

int main() {
	cin >> n >> m >> c;
	for (int i = 0; i < n; ++i) {
		scanf("%d", x + i);
	}
	for (int i = 0; i < n - 1; ++i) {
		scanf("%d", p + i);
		v[i] = (x[i + 1] - x[i]) / 2.0 - p[i] / 100.0 * c;
	}
	Tree*root = new Tree(v, 0, n - 1);
	double ans = 0;
	for (int i = 0; i < m; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		--a, --b;
		Info r = root->ask(a, b);
		ans += r.op;
	}
	printf("%0.10lf\n", ans);
	return 0;
}