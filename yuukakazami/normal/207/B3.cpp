#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
using namespace std;
int n;
const int MAX_N = 250000 + 10, INF = ~0U >> 1;
int a[MAX_N * 2], v[MAX_N * 2];
int nxt[MAX_N * 2];

int get(int i, int j) {
	return v[i] < v[j] ? i : j;
}

struct Tree {
	Tree*pl, *pr;
	int l, r, minv;
	Tree(int l, int r) :
			l(l), r(r) {
		if (l + 1 == r) {
			minv = l;
			return;
		}
		pl = new Tree(l, l + r >> 1);
		pr = new Tree(l + r >> 1, r);
		minv = get(pl->minv, pr->minv);
	}
	int query(int L, int R) {
		if (L >= r || l >= R)
			return n + n;
		if (L <= l && R >= r) {
			return minv;
		}
		return get(pl->query(L, R), pr->query(L, R));
	}
}*rt;

const int MAX_LOG = 20;
int nxt2k[MAX_N * 2][MAX_LOG];

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = n; i < n + n; ++i) {
		a[i] = a[i - n];
	}
	for (int i = 0; i < n + n; ++i) {
		v[i] = i - a[i];
	}
	v[n + n] = INF;
	rt = new Tree(0, n + n);
	for (int i = 0; i < n + n; ++i) {
		nxt[i] = rt->query(max(v[i], 0), i);
		if (nxt[i] == n + n)
			nxt[i] = -1;
//		cout << nxt[i] << endl;
	}
	for (int i = 0; i < n + n; ++i) {
		nxt2k[i][0] = nxt[i];
	}
	for (int pw = 0; pw + 1 < MAX_LOG; ++pw) {
		for (int i = 0; i < n + n; ++i) {
			int go = nxt2k[i][pw];
			if (go != -1)
				go = nxt2k[go][pw];
			nxt2k[i][pw + 1] = go;
		}
	}
	long long ans = 0;
	for (int i = n - 1; i < n + n - 1; ++i) {
		int u = i;
		int dst = i - n + 1;
		for (int pw = MAX_LOG - 1; pw >= 0; --pw) {
			int nu = nxt2k[u][pw];
			if (nu != -1 && v[nu] > dst)
				u = nu, ans += 1 << pw;
		}
		if (v[u] > dst)
			ans += 2;
		else
			ans += 1;
	}
	cout << ans << endl;
	return 0;
}