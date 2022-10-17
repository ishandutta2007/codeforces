#include <bits/stdc++.h>
using namespace std;
#define fu(i, a, b) for(int i = a, I = (b) + 1; i < I; ++i)
#define fd(i, a, b) for(int i = a, I = (b) - 1; i > I; --i)
template <class T> inline void rd(T &x) {
    x = 0; T f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9') f = ch == '-' ? -1 : 1, ch = getchar();
    while(ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    x *= f;
} 

const int N = 1 << 18;
int n, a, cnt[N];
long long ans;

struct DSU {
	int fa[N], sz[N];
	inline void init() {
		fu(i, 0, N - 1) fa[i] = i, sz[i] = 1;
	} 
	int get(int x) {
		if(x == fa[x]) return x;
		return fa[x] = get(fa[x]);
	}
	inline int merge(int x, int y) {
		x = get(x), y = get(y);
		if(x == y) return 0;
		if(sz[x] < sz[y]) swap(x, y);
		int res = (sz[x] == 1 ? cnt[x] : 1) + (sz[y] == 1 ? cnt[y] : 1) - 1; 
		fa[y] = x, sz[x] += sz[y];
		return res;
	}
} dsu;

int main() {
	rd(n);
	fu(i, 1, n) rd(a), ++cnt[a], ans -= a;
	dsu.init();
	++cnt[0];
	fd(sum, N - 1, 0) 
		for(int u = sum; u; u = (--u) & sum) {
			int v = sum - u;
			if(!cnt[u] || !cnt[v]) continue;
			ans += 1LL * sum * dsu.merge(u, v);
		}
	printf("%lld\n", ans);
}