/*
 * E.cpp
 *
 *  Created on: 2013-4-23
 *      Author: mac
 */
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>
using namespace std;

const int MAX_N = int(1e5) + 10;

struct Edge {
	int t, c;
	Edge(int t, int c) :
			t(t), c(c) {
	}
};

vector<Edge> E[MAX_N];

bool del[MAX_N];

int n, l, w;

typedef long long int64;
int64 ans;

vector<pair<int, int> > allp;

void dfs(int u, int par, int dep, int sum, vector<pair<int, int> >&ret) {
	ret.push_back(make_pair(sum, dep));
	allp.push_back(make_pair(sum, dep));

	for (vector<Edge>::iterator e = E[u].begin(); e != E[u].end(); ++e) {
		if (e->t != par && !del[e->t]) {
			dfs(e->t, u, dep + 1, sum + e->c, ret);
		}
	}
}

int size[MAX_N], opt[MAX_N];
vector<int> all;

void dfs(int u, int par) {
	all.push_back(u);
	size[u] = 1;
	opt[u] = 0;

	for (vector<Edge>::iterator e = E[u].begin(); e != E[u].end(); ++e) {
		if (e->t != par && !del[e->t]) {
			dfs(e->t, u);
			size[u] += size[e->t];
			opt[u] = max(opt[u], size[e->t]);
		}
	}
}

vector<pair<int, int> > chs[MAX_N];
int nCh;
int ch[MAX_N];

struct TA {
	int a[MAX_N];
	int n;
	void init(int n) {
		this->n = n;
		memset(a, 0, sizeof(int) * n);
	}
	void add(int p, int x) {
		for (p++; p <= n; p += p & -p)
			a[p - 1] += x;
	}
	int get(int p) {
		p = min(p, n - 1);
		int r = 0;
		for (p++; p; p -= p & -p)
			r += a[p - 1];
		return r;
	}
};

int64 solve(vector<pair<int, int> > a) {

//	int64 ans = 0;
//	for (int i = 0; i < a.size(); ++i) {
//		for (int j = 0; j < a.size(); ++j) {
//			if (a[i].first + a[j].first <= w && a[i].second + a[j].second <= l)
//				++ans;
//		}
//	}
//sum,dep
	static TA ta;
	int mxDeep = 0;
	for (int i = 0; i < a.size(); ++i) {
		mxDeep = max(mxDeep, a[i].second);
	}
	ta.init(mxDeep + 1);

	sort(a.begin(), a.end());
	int j = 0;

	int64 ans = 0;
	for (int i = a.size() - 1; i >= 0; --i) {
		while (j < (int) a.size() && a[i].first + a[j].first <= w) {
			ta.add(a[j].second, 1);
			++j;
		}
		if (l >= a[i].second) {
			ans += ta.get(l - a[i].second);
		}
	}

	return ans;
}

void solve(int rt) {

	all.clear();
	dfs(rt, -1);
	int total = size[rt];

	int minOpt = int(1e9), who = -1;

	for (int i = 0; i < all.size(); ++i) {
		int u = all[i];
		opt[u] = max(opt[u], size[rt] - size[u]);
		if (opt[u] < minOpt) {
			minOpt = opt[u];
			who = u;
		}
	}

	rt = who;
	nCh = 0;

	allp.clear();
	chs[0].clear();

	allp.push_back(make_pair(0, 0));
	chs[nCh++].push_back(make_pair(0, 0));

	for (vector<Edge>::iterator e = E[rt].begin(); e != E[rt].end(); ++e) {
		if (!del[e->t]) {
			ch[nCh] = e->t;
			chs[nCh].clear();
			dfs(e->t, rt, 1, e->c, chs[nCh++]);
		}
	}

	ans += solve(allp);
	for (int i = 0; i < nCh; ++i) {
		ans -= solve(chs[i]);
	}

	del[rt] = true;

	for (vector<Edge>::iterator e = E[rt].begin(); e != E[rt].end(); ++e) {
		if (!del[e->t]) {
			solve(e->t);
		}
	}
}

int main() {
	cin >> n >> l >> w;
	for (int i = 0; i < n - 1; ++i) {
		int p, c;
		scanf("%d%d", &p, &c);
		int a = i + 1, b = p - 1;
		E[a].push_back(Edge(b, c));
		E[b].push_back(Edge(a, c));
	}

	solve(0);
	cout << ans / 2 << endl;
}