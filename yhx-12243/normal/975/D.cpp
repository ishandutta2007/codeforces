#include <bits/stdc++.h>
#define N 200005
using namespace std;

typedef long long ll;

int n, a, b;

struct ghost {
	int x, vx, vy;
	ll y, Nx, Ny, rem;
	ghost * init() {scanf("%d%d%d", &x, &vx, &vy);
		y = (ll)a * x + b; Nx = x + vx; Ny = y + vy;
		rem = Ny - a * Nx;
		return this;
	}
	inline bool operator < (const ghost &B) const {return rem < B.rem || rem == B.rem && vx < B.vx;}
} g[N];

inline ll scx(int x) {return (ll)x * (x - 1);}

int main() {
	int i, j = 0, k, l; ll ans = 0;
	scanf("%d%d%d", &n, &a, &b);
	for (i = 0; i < n; ++i) g[i].init();
	sort(g, g + n);
	for (i = 0; i < n; i = j) {
		for (; j < n && g[i].rem == g[j].rem; ++j);
		ans += scx(j - i);
		for (l = k = i; k < j; k = l) {
			for (; l < j && g[k].vx == g[l].vx; ++l);
			ans -= scx(l - k);
		}	
	}
	printf("%lld\n", ans);
	return 0;
}