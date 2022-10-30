#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

const int MAX_N = 200000 + 10;
double w[MAX_N];

struct Edge {
	int t, c;
	Edge(int t, int c) :
			t(t), c(c) {
	}
};

vector<Edge> E[MAX_N];
int n;

bool del[MAX_N];
int size[MAX_N];

int seq[MAX_N], pt, opt[MAX_N];

void dfs(int u, int par) {
	size[u] = 1, seq[pt++] = u;
	opt[u] = 0;
	for (vector<Edge>::iterator e = E[u].begin(); e != E[u].end(); ++e)
		if (e->t != par && !del[e->t]) {
			dfs(e->t, u), size[u] += size[e->t];
			opt[u] = max(opt[u], size[e->t]);
		}
}

double cur;
void dfs3(int u, int par, int d) {
	cur += w[u] * d * sqrt(d);
	for (vector<Edge>::iterator e = E[u].begin(); e != E[u].end(); ++e) {
		if (e->t != par)
			dfs3(e->t, u, d + e->c);
	}
}

double calcAns(int u) {
	cur = 0;
	dfs3(u, -1, 0);
	return cur;
}

double DEV[MAX_N];

void dfs4(int u, int par, int br, int d) {
	if (br == -1 && par != -1) {
		br = u;
	}
	if (br != -1) {
		DEV[br] += sqrt(d) * w[u];
	}
	for (vector<Edge>::iterator e = E[u].begin(); e != E[u].end(); ++e) {
		if (e->t != par)
			dfs4(e->t, u, br, d + e->c);
	}
}

void calcD(int u) {
	memset(DEV, 0, sizeof DEV);
	dfs4(u, -1, -1, 0);
}

double ans = 1e100;
int at;

void solve(int rt) {
	pt = 0, dfs(rt, -1);
	int tot = size[rt];
	int minOpt = tot + 1, by = -1;
	for (int i = 0; i < tot; ++i) {
		int u = seq[i];
		opt[u] = max(opt[u], tot - size[u]);
		if (opt[u] < minOpt)
			minOpt = opt[u], by = u;
	}

	rt = by;
	del[rt] = true;

	double here = calcAns(rt);
	if (here < ans) {
		ans = here;
		at = rt;
	}

	calcD(rt);

	double S = 0, mx = -1;
	int go = -1;

	for (vector<Edge>::iterator e = E[rt].begin(); e != E[rt].end(); ++e) {
		S += DEV[e->t];
		if (DEV[e->t] > mx) {
			mx = DEV[e->t];
			go = e->t;
		}
	}

	if (del[go])
		return;
	if (mx * 2 >= S)
		solve(go);
}

double bf() {
	double ret = 1e100;
	for (int i = 0; i < n; ++i) {
		ret = min(ret, calcAns(i));
	}
	return ret;
}

void gen(int _n) {
	n = _n;
	for (int i = 0; i < n; ++i) {
		w[i] = rand() % 100 + 10;
	}
	for (int i = 2; i <= n; ++i) {
		int a = i - 1 - rand() % 10;
		if (a < 1)
			a = 1;
		int b = i;
		int c = rand() % 100;
		--a, --b;
		E[a].push_back(Edge(b, c));
		E[b].push_back(Edge(a, c));
	}
}

int main() {
//	gen(1000);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		scanf("%lf", w + i);
	}
	for (int i = 0; i < n - 1; ++i) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		--a, --b;
		E[a].push_back(Edge(b, c));
		E[b].push_back(Edge(a, c));
	}
	solve(0);
	printf("%d %0.10lf\n", at + 1, ans);
//	printf("%0.10lf\n", bf());
}