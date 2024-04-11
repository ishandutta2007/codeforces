/*
 * e.cpp
 *
 *  Created on: 2013-4-12
 *      Author: 
 */

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

int n, nQ;
vector<int> x;

struct Query {
	int t, a1, a2;
	void read() {
		scanf("%d%d%d", &t, &a1, &a2);
	}
};

vector<Query> qs;

typedef long long int64;

vector<int> cx;

vector<int> allx;
vector<bool> has;

struct Data {
	bool exist;
	int cnt;
	int64 sum, op;
	Data() {
		sum = op = cnt = 0;
		exist = false;
	}
	Data(int v) {
		sum = v;
		op = 0;
		cnt = 1;
		exist = true;
	}
};

Data operator+(const Data&a, const Data&b) {
	if (!a.exist)
		return b;
	if (!b.exist)
		return a;
	Data ret;
	ret.exist = true;
	ret.sum = a.sum + b.sum;
	ret.op = a.op + b.op - b.cnt * a.sum + a.cnt * b.sum;
	ret.cnt = a.cnt + b.cnt;
	return ret;
}

struct Tree {
	Data data;
	Tree*pl, *pr;
	int l, r;

	void update() {
		data = pl->data + pr->data;
	}

	Tree(int l, int r) :
			l(l), r(r) {
		if (l + 1 == r) {
			if (has[l]) {
				data = Data(allx[l]);
			} else {
				data = Data();
			}
			return;
		}
		pl = new Tree(l, (l + r) >> 1);
		pr = new Tree((l + r) >> 1, r);
		update();
	}

	Data calc(int L, int R) {
		if (L <= l && R >= r)
			return data;
		if (L >= r || l >= R)
			return Data();
		return pl->calc(L, R) + pr->calc(L, R);
	}

	void change(int i) {
		if (i < l || i >= r)
			return;
		if (l + 1 == r) {
			if (has[i]) {
				has[i] = false;
				data = Data();
			} else {
				data = Data(allx[i]);
				has[i] = true;
			}
			return;
		}
		pl->change(i);
		pr->change(i);
		update();
		return;
	}
}*rt;

int get(int x) {
	return lower_bound(allx.begin(), allx.end(), x) - allx.begin();
}

int main() {
	cin >> n;
	x.assign(n, 0);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &x[i]);
	}

	allx = x;
	cx = x;

	cin >> nQ;
	qs.resize(nQ);
	for (int i = 0; i < nQ; ++i) {
		qs[i].read();
	}

	for (int i = 0; i < nQ; ++i) {
		if (qs[i].t == 1) {
			int p = qs[i].a1, d = qs[i].a2;
			--p;
			cx[p] += d;
			allx.push_back(cx[p]);
		}
	}

	sort(allx.begin(), allx.end());
	allx.erase(unique(allx.begin(), allx.end()), allx.end());

	//start
	has.assign(allx.size(), false);
	for (int i = 0; i < n; ++i) {
		has[get(x[i])] = true;
	}

	rt = new Tree(0, allx.size());
	cx = x;

	for (int i = 0; i < qs.size(); ++i) {
		Query q = qs[i];
		if (q.t == 1) {
			int p = q.a1, d = q.a2;
			--p;
			int x = cx[p];
			int nx = cx[p] += d;
			rt->change(get(x));
			rt->change(get(nx));
		} else {
			int l = q.a1, r = q.a2;

//			for (int i = 0; i < n; ++i) {
//				if (cx[i] >= l && cx[i] <= r)
//					cout << cx[i] << " ";
//			}
//			cout << endl;
			l = lower_bound(allx.begin(), allx.end(), l) - allx.begin();
			r = upper_bound(allx.begin(), allx.end(), r) - allx.begin();

			Data ret = rt->calc(l, r);
			cout << ret.op << endl;
		}
	}

	return 0;
}