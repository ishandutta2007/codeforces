#include <bits/stdc++.h>
#define x second
#define y first

typedef long long ll;
typedef long double ld;
typedef std::pair <ll, ll> pr;
const int N = 300054;

int n, q;
ll K, B, tot;
pr a[N];

inline void reset() {K = B = 0, n = 1, *a = pr(0, 0);}
inline bool fy(const pr &u, const pr &v, ll K) {return u.y - v.y <= (ld)K * (v.x - u.x);}
inline bool fy(const pr &u, const pr &v, const pr &w) {return (ld)(u.y - v.y) * (w.x - v.x) <= (ld)(v.y - w.y) * (v.x - u.x);}
inline void push(const pr &t) {for (; n > 1 && fy(a[n - 2], a[n - 1], t); --n); a[n++] = t;}
inline void adjust(ll K) {for (; n > 1 && fy(a[n - 2], a[n - 1], K); --n);}

int main() {
	int op, k, d; reset();
	for (scanf("%lld%d", &tot, &q); q; adjust(K), printf("%lld %lld\n", a[n - 1].x + 1, a[n - 1].x * K + B + a[n - 1].y), --q)
		switch (scanf("%d%d", &op, &k), op) {
			case 1: reset(), tot += k; break;
			case 2: push(pr(-K * tot - B, tot)), tot += k; break;
			case 3: scanf("%d", &d), B += k, K += d; break;
		}
	return 0;
}