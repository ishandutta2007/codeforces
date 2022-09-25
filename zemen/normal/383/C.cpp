#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include <string.h>
#include <math.h>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <complex>
#include <cassert>

using namespace std;

#define INF 1000000001
#define INFL 1000000000000000001ll
#define pb push_back
#define fi first
#define se second
#define mp make_pair

typedef long long ll;
typedef long double ld;
typedef complex <ld> point;

#define NAME "c"
//~ #undef NAME
#ifndef NAME
    #error "Write problem name"
#endif

int a[200001];
vector <int> g[200001];
char sign[200001];
int in[200001];
int out[200001];
int timer = 0;

#define BASE 262144
int t[BASE * 2];

inline void push(int v) {
	t[v * 2] += t[v];
	t[v * 2 + 1] += t[v];
	t[v] = 0;
}

void add(int l, int r, int val, int v = 1, int cl = 0, int cr = BASE) {
	if (l <= cl && cr <= r) {
		t[v] += val;
		return;
	}
	if (r <= cl || cr <= l)
		return;
	push(v);
	int cc = (cl + cr) / 2;
	add(l, r, val, v * 2, cl, cc);
	add(l, r, val, v * 2 + 1, cc, cr);
}

int get(int id, int v = 1, int cl = 0, int cr = BASE) {
	if (cl + 1 == cr)
		return t[v];
	push(v);
	int cc = (cl + cr) / 2;
	if (id >= cc)
		return get(id, v * 2 + 1, cc, cr);
	else
		return get(id, v * 2, cl, cc);
}

void precalc(int u, int prev = -1, char s = 0) {
	sign[u] = s;
	in[u] = timer++;
	for (int i = 0; i < (int) g[u].size(); ++i) {
		int v = g[u][i];
		if (v == prev)
			continue;
		precalc(v, u, s ^ 1);
	}
	out[u] = timer;
}

int main() {
    #ifdef _GEANY
    assert(freopen(NAME ".in", "r", stdin));
    #endif
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; ++i)
		cin >> a[i];
    for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		g[u].pb(v);
		g[v].pb(u);
	}
	precalc(0);
	//~ for (int i = 0; i < n; ++i)
		//~ cerr << int(sign[i]) << ' ';
	for (int i = 0; i < n; ++i)
		if (sign[i])
			t[in[i] + BASE] = -a[i];
		else
			t[in[i] + BASE] = a[i];
	for (int i = 0; i < q; ++i) {
		int op;
		cin >> op;
		if (op == 1) {
			int id, val;
			cin >> id >> val;
			--id;
			if (sign[id])
				val = -val;
			add(in[id], out[id], val);
		} else {
			int id;
			cin >> id;
			--id;
			int res = get(in[id]);
			if (sign[id])
				res = -res;
			cout << res << '\n';
		}
	}
}