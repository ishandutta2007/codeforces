#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
#include <queue>
using namespace std;
const int MAX_N = 250000 + 10, INF = ~0U >> 1;
int x, y, p, r, n;
typedef long long int64;

int64 sqr(int64 x) {
	return x * x;
}

struct Gripper {
	int64 d, r;
	int m, p, id;
	void read() {
		int x, y, rr;
		scanf("%d%d%d%d%d", &x, &y, &m, &p, &rr);
		d = sqr(x - ::x) + sqr(y - ::y);
		r = sqr(rr);
	}
	bool operator<(const Gripper&o) const {
		return d < o.d;
	}
};

Gripper gs[MAX_N];
int64 ds[MAX_N];

Gripper BIG;
Gripper* get(Gripper*a, Gripper*b) {
	return a->m < b->m ? a : b;
}
struct Tree {
	Tree*pl, *pr;
	int l, r;
	int64 ld, rd;

	Gripper*g;

	void update() {
		g = get(pl->g, pr->g);
	}

	Tree(int l, int r) :
			l(l), r(r) {
		ld = ds[l];
		rd = ds[r - 1];
		if (l + 1 == r) {
			g = gs + l;
			return;
		}
		pl = new Tree(l, l + r >> 1);
		pr = new Tree(l + r >> 1, r);
		update();
	}

	Gripper* calc(int64 mxd) {
		if (ld > mxd)
			return &BIG;
		if (mxd >= rd) {
			return g;
		}
		return get(pl->calc(mxd), pr->calc(mxd));
	}

	void remove(int i) {
		if (i < l || i >= r)
			return;
		if (l + 1 == r) {
			g = &BIG;
			return;
		}
		pl->remove(i);
		pr->remove(i);
		update();
	}
}*root;

int cnt;
queue<Gripper*> que;

void doit(int p, int64 r) {
	for (;;) {
		Gripper*a = root->calc(r);
		if (a->m <= p) {
			++cnt;
			que.push(a);
			root->remove(a->id);
		} else
			break;
	}
}

int main() {
	cin >> x >> y >> p >> r >> n;
	for (int i = 0; i < n; ++i) {
		gs[i].read();
	}
	sort(gs, gs + n);
	for (int i = 0; i < n; ++i) {
		ds[i] = gs[i].d;
		gs[i].id = i;
	}
	BIG.m = INF;
	root = new Tree(0, n);
	doit(p, sqr(r));
	while (!que.empty()) {
		Gripper*a = que.front();
		que.pop();
		doit(a->p, a->r);
	}
	cout << cnt << endl;
	return 0;
}