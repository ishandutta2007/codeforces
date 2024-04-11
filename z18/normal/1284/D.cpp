#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5, inf = 1e9 + 7;
int n, tot;

struct thing {
	int a, b, c, d;
} e[maxn + 3];

struct event {
	int t, x, l, r;
	friend bool operator < (const event &a, const event &b) {
		return a.x == b.x ? a.t > b.t : a.x < b.x;
	}
} f[maxn + 3];

bool check() {
	tot = 0;
	for (int i = 1; i <= n; i++) {
		f[++tot].t = 1, f[tot].x = e[i].a, f[tot].l = e[i].c, f[tot].r = e[i].d;
		f[++tot].t = -1, f[tot].x = e[i].b, f[tot].l = e[i].c, f[tot].r = e[i].d;
	}
	multiset<int> L, R;
	sort(f + 1, f + tot + 1);
	L.insert(-inf), R.insert(inf);
	for (int i = 1; i <= tot; i++) {
		if (f[i].t == 1) {
			L.insert(f[i].l), R.insert(f[i].r);
		} else {
			L.erase(L.lower_bound(f[i].l));
			R.erase(R.lower_bound(f[i].r));
		}
		int mn = *R.begin();
		multiset<int>::iterator it = L.end();
		int mx = *--it;
		if (mn < mx) {
			return true;
		}
	}
	return false;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d %d %d", &e[i].a, &e[i].b, &e[i].c, &e[i].d);
	}
	if (check()) {
		puts("NO");
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		swap(e[i].a, e[i].c);
		swap(e[i].b, e[i].d);
	}
	if (check()) {
		puts("NO");
	} else {
		puts("YES");
	}
	return 0;
}