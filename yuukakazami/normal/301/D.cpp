#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include <vector>
using namespace std;

const int MAX_N = int(2e5) + 10;
int n;
int p[MAX_N];

struct TA {
	int a[MAX_N], n;

	void init(int n) {
		this->n = n;
		memset(a, 0, sizeof a);
	}

	void upd(int p, int x) {
		for (p++; p <= n; p += p & -p)
			a[p - 1] += x;
	}

	int get(int p) {
		int r = 0;
		for (p++; p > 0; p -= p & -p)
			r += a[p - 1];
		return r;
	}
} ta;

vector<int> by[MAX_N];

int at[MAX_N];

int ans[MAX_N];

vector<pair<int, int> > qry[MAX_N];

int m;

int main() {
	cin >> n >> m;
	ta.init(n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", p + i);
		at[p[i]] = i;
	}

	for (int i = 0; i < n; ++i) {
		for (int x = p[i]; x <= n; x += p[i]) {
			int j = at[x];
			if (i < j)
				by[j].push_back(i);
			else
				by[i].push_back(j);
		}
	}

	for (int i = 0; i < m; ++i) {
		int l, r;
		scanf("%d%d", &l, &r);
		--l, --r;
		qry[r].push_back(make_pair(l, i));
	}

	for (int i = 0; i < n; ++i) {
		for (vector<int>::iterator e = by[i].begin(); e != by[i].end(); ++e) {
			ta.upd(0, 1);
			ta.upd(*e + 1, -1);
		}
		for (vector<pair<int, int> >::iterator e = qry[i].begin();
				e != qry[i].end(); ++e) {
			ans[e->second] += ta.get(e->first);
		}
	}

	for (int i = 0; i < m; ++i) {
		printf("%d\n", ans[i]);
	}
}