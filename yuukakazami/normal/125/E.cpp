#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
using namespace std;
const int MAX_N = 5000 + 10;

struct DisJoinSet {
	int fa[MAX_N], n;
	void init(int _n) {
		n = _n;
		for (int i = 0; i < n; ++i) {
			fa[i] = i;
		}
	}

	int find(int x) {
		if (fa[x] == x)
			return x;
		return fa[x] = find(fa[x]);
	}

	bool unite(int a, int b) {
		a = find(a), b = find(b);
		fa[a] = b;
		return a != b;
	}
} djs;

struct Edge {
	int a, b, id;
	double c;
	Edge() {
	}
	Edge(int _a, int _b, double _c, int _id) :
			a(_a), b(_b), c(_c), id(_id) {
	}
	bool operator<(const Edge&e) const {
		return c < e.c;
	}
	bool isCaptial() {
		return !a || !b;
	}
};

vector<Edge> ce, ne;
const int MAX_M = int(1e5) + 10;
int n, m, k;
vector<Edge> mst;

int eval(double delta, int nCnt = -1) {
	static Edge es[MAX_M];
	for (vector<Edge>::iterator e = ce.begin(); e != ce.end(); ++e) {
		e->c += delta;
	}
	merge(ce.begin(), ce.end(), ne.begin(), ne.end(), es) - es;
	djs.init(n);
	int cnt = 0;
	mst.clear();
	for (int i = 0; i < m; ++i) {
		if (es[i].isCaptial() && cnt == nCnt)
			continue;
		if (djs.unite(es[i].a, es[i].b)) {
			mst.push_back(es[i]);
			if (es[i].isCaptial()) {
				++cnt;
			}
		}
	}
	for (vector<Edge>::iterator e = ce.begin(); e != ce.end(); ++e) {
		e->c -= delta;
	}
	return cnt;
}

int main() {
	cin >> n >> m >> k;
	for (int i = 0; i < m; ++i) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c), --a, --b;
		Edge e(a, b, c, i + 1);
		if (e.isCaptial()) {
			ce.push_back(e);
		} else {
			ne.push_back(e);
		}
	}
	sort(ce.begin(), ce.end());
	sort(ne.begin(), ne.end());
	double L = -1e6, R = 1e6;
	eval(0);
	if (mst.size() < n - 1) {
		cout << "-1" << endl;
		return 0;
	}
	int mx = eval(L), mi = eval(R);
	if (mx < k || mi > k) {
		puts("-1");
		return 0;
	}
	for (int i = 0; i < 100; ++i) {
		double M = (L + R) / 2;
		if (eval(M) >= k) {
			L = M;
		} else {
			R = M;
		}
	}
	eval(L, k);
	cout << mst.size() << endl;
	for (vector<Edge>::iterator e = mst.begin(); e != mst.end(); ++e) {
		printf("%d ", e->id);
	}
	printf("\n");
	return 0;
}