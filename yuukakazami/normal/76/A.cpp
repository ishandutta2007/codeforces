/*
 * A. Gift.cpp
 *
 *  Created on: 2011-4-12
 *      Author: user
 */

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
using namespace std;

typedef long long int64;

const int MAX_N = 200 + 10;
const int MAX_E = 50000 + 10;

struct Edge {
	int g, s, a, b;
	void read() {
		scanf("%d%d%d%d", &a, &b, &g, &s);
		--a;
		--b;
	}

	bool operator<(const Edge&e) const {
		return g < e.g;
	}
};
Edge es[MAX_E];
int nV, nE;

struct UF {
	int F[MAX_N];
	int cnt;

	void init(int n) {
		for (int i = 0; i < n; ++i) {
			F[i] = i;
		}
		cnt = n;
	}

	int find(int x) {
		if (x == F[x])
			return x;
		return F[x] = find(F[x]);
	}

	void unite(int a, int b) {
		a = find(a);
		b = find(b);
		F[a] = b;
		if (a != b)
			--cnt;
	}

	void operator=(const UF&u) {
		memcpy(F, u.F, sizeof F);
	}
};

int mergeCnt = 0;
//void merge(UF&ret, UF&a, UF&b) {
//	++mergeCnt;
//	for (int i = 0; i < nV; ++i) {
//		int to = a.find(i);
//		ret.unite(i, to);
//		to = b.find(i);
//		ret.unite(i, to);
//	}
//}

void merge(UF&ret, UF&a) {
	for (int i = 0; i < nV; ++i) {
		int to = a.find(i);
		ret.unite(i, to);
	}
}

struct TA {
	UF u[MAX_E];
	int n;

	void init(int _n) {
		n = _n;
		for (int i = 0; i < n; ++i) {
			u[i].init(nV);
		}
	}

	void add(int p, int a, int b) {
		for (p++; p <= n; p += p & -p)
			u[p - 1].unite(a, b);
	}

	bool check(int p) {
		static UF ret;
		ret.init(nV);
		for (p++; p > 0; p -= p & -p)
			merge(ret, u[p - 1]);
		return ret.cnt == 1;
	}
};

//struct Tree {
//	UF u;
//	int left, right;
//	Tree*cL, *cR;
//	Tree(int _left, int _right) :
//		left(_left), right(_right) {
//		u.init(nV);
//
//		cL = cR = 0;
//		if (left + 1 == right)
//			return;
//
//		int mid = left + right >> 1;
//		cL = new Tree(left, mid);
//		cR = new Tree(mid, right);
//	}
//
//	int ask(UF&ret) {
//		static UF tmp;
//		tmp.init(nV);
//		merge(tmp, ret, u);
//		if (tmp.cnt == 1) {
//			if (left + 1 == right)
//				return left;
//			int a = cL->ask(ret);
//			if (a != -1)
//				return a;
//			return cR->ask(ret);
//		} else {
//			ret = tmp;
//			return -1;
//		}
//	}
//
//	void change(int at, int a, int b) {
//		if (at < left || at >= right)
//			return;
//		u.unite(a, b);
//		if (left + 1 == right)
//			return;
//		cL->change(at, a, b);
//		cR->change(at, a, b);
//	}
//};

void genData() {
	nV = 200;
	nE = 50000;
	for (int i = 0; i < nE; ++i) {
		es[i].a = rand() % nV;
		es[i].b = rand() % nV;
		es[i].g = rand();
		es[i].s = rand();
	}
}

int G, S;

TA ta;

void work() {
	sort(es, es + nE);

	static int comp[MAX_E];
	int cnt = 0;
	for (int i = 0; i < nE; ++i) {
		comp[cnt++] = es[i].s;
	}
	sort(comp, comp + cnt);
	cnt = unique(comp, comp + cnt) - comp;

	//	Tree*root = new Tree(0, cnt);

	ta.init(cnt);
	int64 ans = LONG_LONG_MAX;
	int R = cnt;
	for (int i = 0; i < nE; ++i) {
		int64 tmp = 1LL * G * es[i].g;
		int at = lower_bound(comp, comp + cnt, es[i].s) - comp;
		//		cout << at << endl;
		//		cout << "hi" << endl;

		ta.add(at, es[i].a, es[i].b);
		if (at < R) {
			while (R > 0 && ta.check(R - 1))
				--R;
		}

		//		cout << i << " " << R << endl;

		if (R != cnt) {
			tmp += 1LL * S * comp[R];
			if (tmp < ans)
				ans = tmp;
		}
	}

	if (ans == LONG_LONG_MAX)
		ans = -1;
	cout << ans << endl;
	//	cout << mergeCnt << endl;
}

void solve() {
	scanf("%d%d", &nV, &nE);
	scanf("%d%d", &G, &S);

	for (int i = 0; i < nE; ++i) {
		es[i].read();
	}
	work();
}

int main() {
	//	genData();
	//	work();
	solve();
}