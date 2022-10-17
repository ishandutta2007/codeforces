#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
int n, m, fa[N];
struct edge {
	int u, v, w;
	inline bool operator < (const edge &e1) const {
		return w < e1.w;
	}
} e[N];
int get(int x) {return x == fa[x] ? x : fa[x] = get(fa[x]);}

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; ++i) scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
	sort(e + 1, e + m + 1);
	for(int i = 1; i <= n; ++i) fa[i] = i;
	long long ans = 0;
	for(int l = 1, r = 0; l <= m; l = r + 1) {
		while(r < m && e[r + 1].w == e[l].w) ++r;
		for(int i = l; i <= r; ++i) {
			int u = get(e[i].u), v = get(e[i].v);
			ans += (u != v);
		}
		for(int i = l; i <= r; ++i) {
			int u = get(e[i].u), v = get(e[i].v);
			if(u != v) --ans, fa[u] = v; 
		}
	}
	printf("%lld", ans);
	return 0;
}