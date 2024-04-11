#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
using namespace std;

const int INF = ~0U >> 2;
const int MAX_N = int(1e5) + 10;

int x[MAX_N], y[MAX_N], n, m;
int vx[MAX_N], vy[MAX_N];

struct Point {
	int x, y, id;
	bool operator<(const Point&o) const {
		return x < o.x;
	}
};

Point ps[MAX_N];

void doit(int x[], int vx[], int n) {
	static pair<int, int> ps[MAX_N];
	for (int i = 0; i < n; ++i) {
		ps[i] = make_pair(x[i], i);
	}
	sort(ps, ps + n);
	for (int i = 0; i < n; ++i) {
		vx[i] = ps[i].first;
		x[ps[i].second] = i;
	}
}

struct SegmentTree {
	int*a;
	int n, pw;

	void init(int n) {
		this->n = n;
		pw = 1;
		while (pw <= n + 3)
			pw <<= 1;
		a = new int[pw * 2];
		for (int i = 0; i < pw * 2; ++i) {
			a[i] = INF;
		}
	}

	void change(int p, int w) {
		p += pw + 1;
		a[p] = w;
		for (p >>= 1; p; p >>= 1)
			a[p] = min(a[p + p], a[p + p + 1]);
	}

	int ask(int l, int r) { //[l,r)
		if (l >= r)
			return INF;
		int ret = INF;
		for (l += pw, r += pw + 1; l ^ r ^ 1; l >>= 1, r >>= 1) {
			if (~l & 1)
				ret = min(ret, a[l ^ 1]);
			if (r & 1)
				ret = min(ret, a[r ^ 1]);
		}
		return ret;
	}
};

struct Target {
	int xl, xr, yl, yr, z, id;
	void read() {
		scanf("%d%d%d%d%d", &xl, &xr, &yl, &yr, &z);
	}
	bool operator<(const Target&o) const {
		return z < o.z;
	}
};

Target ts[MAX_N];

struct Tree {
	int l, r;
	SegmentTree t;

	vector<int> idy;

	Tree*pl, *pr;

	Tree(int _l, int _r) :
			l(_l), r(_r) {
		for (int k = l; k < r; ++k) {
			idy.push_back(ps[k].y);
		}
		sort(idy.begin(), idy.end());
		t.init(idy.size());
		for (int k = l; k < r; ++k) {
			int at = lower_bound(idy.begin(), idy.end(), ps[k].y) - idy.begin();
			t.change(at, ps[k].id);
		}

		if (l + 1 < r) {
			pl = new Tree(l, l + r >> 1);
			pr = new Tree(l + r >> 1, r);
		}
	}

	int ask(int L, int R, int ly, int ry) { //[ly,ry)
		if (L >= r || l >= R)
			return INF;
		if (L <= l && R >= r) {
			ly = lower_bound(idy.begin(), idy.end(), ly) - idy.begin();
			ry = lower_bound(idy.begin(), idy.end(), ry) - idy.begin();
			return t.ask(ly, ry);
		}
		return min(pl->ask(L, R, ly, ry), pr->ask(L, R, ly, ry));
	}

	void change(int x, int y, int v) {
		int at = lower_bound(idy.begin(), idy.end(), y) - idy.begin();
		t.change(at, v);
		if (l + 1 < r) {
			int m = l + r >> 1;
			if (x < m)
				pl->change(x, y, v);
			else
				pr->change(x, y, v);
		}
	}
}*root;

int ans[MAX_N];

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		ts[i].read();
		ts[i].id = i;
	}
	cin >> m;
	for (int i = 0; i < m; ++i) {
		scanf("%d%d", x + i, y + i);
	}

	doit(x, vx, m);
	doit(y, vy, m);

	for (int i = 0; i < m; ++i) {
		ps[i].x = x[i];
		ps[i].y = y[i];
		ps[i].id = i;
	}

	sort(ps, ps + m);

	sort(ts, ts + n);

	root = new Tree(0, m);

	memset(ans, -1, sizeof ans);

	for (int i = 0; i < n; ++i) {
		int lx = lower_bound(vx, vx + m, ts[i].xl) - vx;
		int rx = upper_bound(vx, vx + m, ts[i].xr) - vx;

		int ly = lower_bound(vy, vy + m, ts[i].yl) - vy;
		int ry = upper_bound(vy, vy + m, ts[i].yr) - vy;

		int who = root->ask(lx, rx, ly, ry);
		if (who != INF) {
			ans[who] = ts[i].id;
			root->change(x[who], y[who], INF);
		}
	}

	for (int i = 0; i < m; ++i) {
		printf("%d\n", ans[i] + 1);
	}
	return 0;
}