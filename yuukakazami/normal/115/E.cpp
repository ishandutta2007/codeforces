/*
 * e.cpp
 *
 *  Created on: 2011-9-15
 *      Author: mac
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define REP(i,n) for(int i=0;i<n;++i)
using namespace std;
const int MAX_N = int(2e5) + 10;
typedef long long int64;
const int64 INF = 1LL << 60;

struct Tree {
	int64 v, add;
	Tree*pl, *pr;
	int l, r, m;
	Tree(int l, int r) {
		this->l = l, this->r = r;
		add = 0;
		m = (l + r) >> 1;
		v = -INF;
		if (l + 1 == r) {
			pl = pr = 0;
			return;
		}
		pl = new Tree(l, m);
		pr = new Tree(m, r);
	}
	void apply(int64 a) {
		add += a;
		v += a;
	}
	void relax() {
		if (!add)
			return;
		pl->apply(add);
		pr->apply(add);
		add = 0;
	}
	void update() {
		v = max(pl->v, pr->v);
	}
	int64 ask(int L, int R) {
		if (L >= R)
			return -INF;
		if (L == l && R == r)
			return v;
		relax();
		if (L >= m)
			return pr->ask(L, R);
		else if (R <= m)
			return pl->ask(L, R);
		else
			return max(pl->ask(L, m), pr->ask(m, R));
	}
	void addRange(int L, int R, int64 a) {
		if (L >= R)
			return;
		if (L == l && R == r) {
			apply(a);
			return;
		}
		relax();
		if (L >= m)
			pr->addRange(L, R, a);
		else if (R <= m)
			pl->addRange(L, R, a);
		else {
			pl->addRange(L, m, a);
			pr->addRange(m, R, a);
		}
		update();
	}
	void change(int at, int64 to) {
		if (l + 1 == r) {
			v = to;
			return;
		}
		relax();
		if (at < m)
			pl->change(at, to);
		else
			pr->change(at, to);
		update();
	}
}*root;

struct Pay {
	int l;
	int64 c;
	Pay(int _l, int64 _c) :
			l(_l), c(_c) {
	}
};

vector<Pay> at[MAX_N];
int nRoads, nPays;
int64 cost[MAX_N];

int main() {
	cin >> nRoads >> nPays;
	for (int i = 1; i <= nRoads; ++i) {
		int x;
		scanf("%d", &x);
		cost[i] = x;
	}
	for (int i = 0; i < nPays; ++i) {
		int l, r, c;
		scanf("%d%d%d", &l, &r, &c);
		at[r].push_back(Pay(l, c));
	}
	root = new Tree(0, nRoads + 1);
	root->change(0, 0);
	for (int i = 1; i <= nRoads; ++i) {
		int64 me = root->ask(0, i);
		root->change(i, me);
		root->addRange(0, i, -cost[i]);
		foreach(e,at[i]) {
			root->addRange(0, e->l, e->c);
		}
	}
	int64 ans = root->v;
	cout << ans << endl;
	return 0;
}