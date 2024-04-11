#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
const int MAX_N = int(1e5) + 10;
typedef long long int64;

int a[MAX_N], n;

int get(int x, int y) {
	if (x == -1 || y == -1)
		return x == -1 ? y : x;
	return a[x] > a[y] ? x : y;
}

struct Tree {
	Tree*pl, *pr;
	int l, r, mx;
	int64 sum;

	void update() {
		mx = get(pl->mx, pr->mx);
		sum = pl->sum + pr->sum;
	}

	Tree(int l, int r) :
			l(l), r(r) {
		if (l + 1 == r) {
			sum = a[l];
			mx = l;
			return;
		}
		pl = new Tree(l, l + r >> 1);
		pr = new Tree(l + r >> 1, r);
		update();
	}

	void change(int p, int x) {
		if (p < l || p >= r)
			return;
		if (l + 1 == r) {
			sum = x;
			a[l] = x;
			return;
		}
		pl->change(p, x);
		pr->change(p, x);
		update();
	}

	int queryMax(int L, int R) {
		if (L <= l && R >= r) {
			return mx;
		}
		if (L >= r || l >= R)
			return -1;
		return get(pl->queryMax(L, R), pr->queryMax(L, R));
	}

	int64 querySum(int L, int R) {
		if (L <= l && R >= r) {
			return sum;
		}
		if (L >= r || l >= R)
			return 0;
		return pl->querySum(L, R) + pr->querySum(L, R);
	}
}*rt;
int nQ;

int main() {
	cin >> n >> nQ;
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
	}
	rt = new Tree(0, n);
	while (nQ--) {
		int cmd, l, r, k, x;
		scanf("%d", &cmd);
		if (cmd == 1) {
			scanf("%d%d", &l, &r), --l;
			cout << rt->querySum(l, r) << endl;
		} else if (cmd == 2) {
			scanf("%d%d%d", &l, &r, &x), --l;
			for (;;) {
				int at = rt->queryMax(l, r);
				if (a[at] >= x) {
					rt->change(at, a[at] % x);
				} else
					break;
			}
		} else {
			scanf("%d%d", &k, &x), --k;
			rt->change(k, x);
		}
	}
}