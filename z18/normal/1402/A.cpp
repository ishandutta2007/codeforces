#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= int(b); i++)
#define per(i, a, b) for (int i = (a); i >= int(b); i--)
#define fir first
#define sec second
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
const int maxn = 1e6, maxm = 1 << 20, maxk = 20;
int n, m, k, f[maxk + 5], g[maxk + 5], a[maxn + 5], b[maxn + 5], p[maxk + 5];
int h[maxk + 5], mn[maxk + 5][maxm + 5], res[maxn + 5];

template<class type> inline void cmax(type &x, type y) { x < y ? x = y : 0; }
template<class type> inline void cmin(type &x, type y) { x > y ? x = y : 0; }

void bfs() {
	rep(i, 1, k) rep(msk, 0, (1 << k) - 1) {
		cmin(mn[i][msk], mn[i - 1][msk]);
		rep(j, 0, k - 1) cmin(mn[i][msk ^ (1 << j)], mn[i - 1][msk]);
	}
}

int main() {
	scanf("%d %d %d", &n, &m, &k);
	rep(i, 1, k) scanf("%1d", &f[i]);
	rep(i, 1, k) scanf("%1d", &g[i]);
	rep(i, 1, n) scanf("%d %d", &a[i], &b[i]);
	rep(i, 1, k) p[i] = i;
	memset(mn, 0x3f, sizeof(mn));
	rep(i, 0, n - m) {
		if (i) swap(p[a[i]], p[b[i]]);
		int msk = 0;
		rep(j, 1, k) msk |= f[j] << (p[j] - 1);
		cmin(mn[0][msk], i);
	}
	bfs();
	rep(i, 1, k) p[i] = i;
	rep(i, 1, n) {
		swap(p[a[i]], p[b[i]]);
		int msk = 0;
		rep(j, 1, k) msk |= g[j] << (p[j] - 1);
		res[i] = msk;
	}
	rep(x, 0, k) {
		int p = 0;
		rep(i, m, n) if (mn[x][res[i]] <= i - m) { p = i; break; }
		if (p) printf("%d\n%d %d\n", k - x, mn[x][res[p]] + 1, p), exit(0);
	}
	return 0;
}