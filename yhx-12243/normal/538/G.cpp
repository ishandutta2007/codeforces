#include <bits/stdc++.h>

typedef long long ll;
const int N = 200054, MAXL = 2000054;
const char mask[4] = {76, 85, 68, 82};

int n, T;
int ansX[MAXL], ansY[MAXL];
ll buf[MAXL];

struct node {
	ll period, pos; int phase;
	node (ll _t = 0, ll _pos = 0) : period(_t / T), pos(_pos), phase(_t % T) {}
	inline bool operator < (const node &B) const {return phase < B.phase || (phase == B.phase && period < B.period);}	
} gX[N], gY[N];

inline void up(ll &x, const ll y) {x < y ? x = y : 0;}
inline void down(ll &x, const ll y) {x > y ? x = y : 0;}

inline ll fd(ll x, ll y) {auto r = lldiv(x, y); return r.quot + (r.rem >> 63);}
inline ll cd(ll x, ll y) {auto r = lldiv(x, y); return r.quot + (r.rem > 0);}

bool solve(node *g, int *ans) {
	int i, la = 0, cur; ll dT, dt, ds, inf = 0, sup = T, incr;
	g[n].period = -1, g[n].phase = T, g[n].pos = 0;
	std::sort(g, g + (n + 1));
	for (i = 1; i <= n && inf <= sup; ++i) {
		dT = g[i].period - g[i - 1].period;
		dt = g[i].phase - g[i - 1].phase;
		ds = g[i].pos - g[i - 1].pos;
		if (!dT) {
			if (ds < 0 || ds > dt) return false;
		} else if (dT > 0) {
			if (ds < 0) return false;
			up(inf, cd(ds - dt, dT)), down(sup, fd(ds, dT));
		} else {
			if (ds > 0) return false;
			up(inf, cd(-ds, -dT)), down(sup, fd(-ds + dt, -dT));
		}
	}
	if (inf > sup) return false;
	incr = (inf + sup) >> 1, *buf = 0;
	for (i = 0; i <= n; ++i, la = cur) {
		cur = g[i].phase;
		buf[cur] = g[i].pos - incr * g[i].period;
		assert(0 <= buf[cur] - buf[la] && buf[cur] - buf[la] <= cur - la);
		auto mid = buf + cur - int(buf[cur] - buf[la]);
		std::fill(buf + la, mid, buf[la]);
		std::iota(mid, buf + cur, buf[la]);
	}
	return std::adjacent_difference(buf + 1, buf + (T + 1), ans), true;
}

int main() {
	int i; ll t, x, y;
	scanf("%d%d", &n, &T), ++n;
	for (i = 1; i < n; ++i) {
		scanf("%lld%lld%lld", &t, &x, &y);
		if ((t ^ x ^ y) & 1) return puts("NO"), 0;
		gX[i] = node(t, (t + x + y) / 2);
		gY[i] = node(t, (t + x - y) / 2);
	}
	if (!(solve(gX, ansX) && solve(gY, ansY))) return puts("NO"), 0;
	for (i = 0; i < T; ++i) putchar(mask[ansX[i] | ansY[i] << 1]);
	return putchar(10), 0;
}