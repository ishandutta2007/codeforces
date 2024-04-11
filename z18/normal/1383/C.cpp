#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= int(b); i++)
#define per(i, a, b) for (int i = (a); i >= int(b); i--)
#define fir first
#define sec second
#define tct template<class type>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
const int maxn = 1e5, lim = 20, maxm = 1 << 20, mod = 1e9 + 7;
int T, n, fa[lim + 5], a[lim + 5];
bool ok[maxm + 5];
char s[maxn + 5], t[maxn + 5];

inline void red(int &x) { x += x >> 31 & mod; }
tct inline void cmax(type &x, type y) { x < y ? x = y : 0; }
tct inline void cmin(type &x, type y) { x > y ? x = y : 0; }

int find(int x) {
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}

int main() {
	scanf("%d", &T);
	while (T --> 0) {
		scanf("%d %s %s", &n, s + 1, t + 1);
		rep(i, 1, lim) fa[i] = i, a[i] = 0;
		rep(i, 1, n) {
			int u = s[i] ^ 96, v = t[i] ^ 96;
			fa[find(u)] = find(v);
			a[u] |= 1 << (v - 1);
		}
		int res = lim * 2;
		rep(i, 1, lim) res -= find(i) == i;
		ok[0] = true;
		int mx = 0;
		for (int msk = 1; msk < 1 << lim; msk++) {
			ok[msk] = false;
			int c = 0;
			rep(i, 1, lim) if (msk >> (i - 1) & 1) {
				c++, ok[msk] |= ok[msk ^ (1 << (i - 1))] && !(a[i] & (msk ^ (1 << (i - 1))));
			}
			if (ok[msk]) mx = max(mx, c);
		}
		printf("%d\n", res - mx);
	}
	return 0;
}