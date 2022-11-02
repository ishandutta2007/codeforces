#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
using namespace std;
const int MAX_N = int(1e5) + 10;
int n, m;
vector<int> E[MAX_N];

int l[MAX_N], r[MAX_N], pt;

void dfs(int u, int p) {
	l[u] = pt++;
	for (vector<int>::iterator e = E[u].begin(); e != E[u].end(); ++e) {
		if (*e != p)
			dfs(*e, u);
	}
	r[u] = pt - 1;
}

vector<pair<int, int> > by[MAX_N];

void add(int a, int b) {
	by[l[a]].push_back(make_pair(1, b));
	by[r[a] + 1].push_back(make_pair(-1, b));
}

struct Tree {
	Tree*pl, *pr;
	int l, r;

	Tree(int l, int r) :
			l(l), r(r), add(0) {
		if (l + 1 == r) {
			ret = make_pair(0, 1);
			return;
		}
		pl = new Tree(l, l + r >> 1);
		pr = new Tree(l + r >> 1, r);
		update();
	}

	int add;
	pair<int, int> ret;

	pair<int, int> get(pair<int, int> a,pair<int, int> b) {
		if (b.first != a.first)
			return a.first < b.first ? a : b;
		a.second += b.second;
		return a;
	}

	void update() {
		ret = get(pl->ret, pr->ret);
	}

	void apply(int a) {
		add += a;
		ret.first += a;
	}

	void relax() {
		if (add != 0) {
			pl->apply(add);
			pr->apply(add);
			add = 0;
		}
	}

	void modify(int L, int R, int x) {
		if (L >= r || l >= R)
			return;
		if (L <= l && R >= r) {
			apply(x);
			return;
		}
		relax();
		pl->modify(L, R, x);
		pr->modify(L, R, x);
		update();
	}
}*root;

int ans[MAX_N];

int main() {
	cin >> n >> m;
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		--u, --v;
		E[u].push_back(v), E[v].push_back(u);
	}

	dfs(0, -1);
	for (int i = 0; i < m; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		--a, --b;
		add(a, b), add(a, a), add(b, a), add(b, b);
	}

	root = new Tree(0, n);

	for (int i = 0; i < n; ++i) {
		for (vector<pair<int, int> >::iterator e = by[i].begin(); e != by[i].end(); ++e) {
			root->modify(l[e->second], r[e->second] + 1, e->first);
		}
		ans[i] = n - (root->ret.first == 0 ? root->ret.second : 0);
	}

	for (int i = 0; i < n; ++i) {
		int x = ans[l[i]];
		x = max(0, x - 1);
		printf("%d ", x);
	}
	puts("");
	return 0;
}