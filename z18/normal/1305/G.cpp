#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

typedef long long ll;
const int maxn = 2e5, maxm = 1 << 18;
int n, a[maxn + 3], fa[maxn + 3];

int find(int x) {
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}

bool check() {
	for (int i = 2; i <= n; i++) if (find(1) != find(i)) return false;
	return true;
}

struct thing {
	pair<int, int> mx[2];
	thing(pair<int, int> t = make_pair(-1, -1)) { mx[0] = t, mx[1] = make_pair(-1, -1); }
	thing operator + (const thing &t) const {
		thing r = t;
		for (int i = 0; i < 2; i++) {
			if (mx[i] > r.mx[0]) {
				if (mx[i].se != r.mx[0].se) r.mx[1] = r.mx[0];
				r.mx[0] = mx[i];
			} else if (mx[i] > r.mx[1] && mx[i].se != r.mx[0].se) {
				r.mx[1] = mx[i];
			}
		}
		return r;
	}
	void operator += (const thing &t) {
		*this = *this + t;
	}
} best[maxm + 3];

pair<int, int> pr[maxn + 3];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	a[++n] = 0;
	for (int i = 1; i <= n; i++) fa[i] = i;
	ll ans = 0;
	while (!check()) {
		for (int i = 0; i < 1 << 18; i++) best[i] = thing();
		for (int i = 1; i <= n; i++) best[a[i]] += thing(make_pair(a[i], find(i)));
		for (int i = 0; i < 18; i++) {
			for (int msk = 0; msk < 1 << 18; msk++) {
				if (msk >> i & 1) best[msk] += best[msk ^ (1 << i)];
			}
		}
		for (int i = 1; i <= n; i++) pr[i] = make_pair(-1, -1);
		for (int i = 1; i <= n; i++) {
			int x = a[i] ^ (maxm - 1), y = find(i);
			for (int j = 0; j < 2; j++) {
				if (best[x].mx[j].fi != -1 && best[x].mx[j].se != y) {
					pr[y] = max(pr[y], make_pair(best[x].mx[j].fi + a[i], best[x].mx[j].se));
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			int x = find(i);
			if (pr[x].fi == -1) continue;
			int y = find(pr[x].se);
			if (x != y) {
				fa[x] = y, ans += pr[x].fi;
			}
		}
	}
	for (int i = 1; i <= n; i++) ans -= a[i];
	printf("%lld\n", ans);
	return 0;
}