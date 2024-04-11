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

char s[1000001];

#define BASE 1048576
int p[BASE * 2];

int get(int l, int r, int v = 1, int cl = 0, int cr = BASE) {
	if (l <= cl && cr <= r)
		return p[v];
	if (r <= cl || cr <= l)
		return INF;
	int cc = (cl + cr) / 2;
	return min(get(l, r, v * 2, cl, cc), get(l, r, v * 2 + 1, cc, cr));
}

int main() {
    #ifdef _GEANY
    assert(freopen(NAME ".in", "r", stdin));
    #endif
    gets(s);
    int n = strlen(s);
    for (int i = 0; i < n; ++i)
		p[BASE + i + 1] = p[BASE + i] + (s[i] == '(' ? 1 : -1);
	for (int i = BASE - 1; i > 0; --i)
		p[i] = min(p[i * 2], p[i * 2 + 1]);
	int m;
	cin >> m;
	for (int i = 0; i < m; ++i) {
		int l, r;
		cin >> l >> r;
		--l;
		if (r - l < 2) {
			cout << 0 << '\n';
		} else {
			int lp = p[BASE + l];
			int rp = p[BASE + r];
			int mp = get(l + 1, r + 1);
			int res = r - l;
			if (mp < lp)
				res -= lp - mp, lp = mp;
			if (lp < rp)
				res -= rp - lp;
			cout << res << '\n';
		}
	}
}