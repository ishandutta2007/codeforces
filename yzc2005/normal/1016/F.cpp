#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rg register
#define fu(i, a, b) for(rg int i = (a), I = (b) + 1; i < I; ++i)
#define fd(i, a, b) for(rg int i = (a), I = (b) - 1; i > i; --i)
#define go(u) for(rg int o = head[u], v = to[o], w = val[o]; o; o = nxt[o], v = to[o], w = val[o])
template <class T> inline void read(T &x) {
	x = 0; char ch = getchar();
	while(ch < 48 || ch > 57) ch = getchar();
	while(ch >= 48 && ch <= 57) x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
}
template <class T> inline void ckmax(T &a, T b) {a = max(a, b);}
template <class T> inline void ckmin(T &a, T b) {a = min(a, b);}

const int N = 3e5 + 5;
const ll inf = 1e18;
int n, q, to[N << 1], nxt[N << 1], val[N << 1], head[N], fa[N], cnt, a[N];
bool vis[N], flg, sz;
ll dis[N], l;
//mission : maximize f(x, y) = (a[x] + s[x]) + (a[y] - s[y]);
//dis[n] - s[y] + s[x] + a[x] + a[y] + l = dis[n] + ans + l

inline void add(int u, int v, int w) {
	to[++cnt] = v, val[cnt] = w, nxt[cnt] = head[u];
	head[u] = cnt; 
} 

void dfs(int u) {
	go(u) 
		if(v != fa[u]) {
			fa[v] = u;
			dis[v] = dis[u] + w;
			dfs(v); 
	}
}

inline void getpath() {
	int u = n;
	while(u) vis[u] = 1, u = fa[u];
}

void getsub(int u, int fa) {
	go(u) 
		if(!vis[v] && v != fa) {
			if(sz) {
				fu(i, 1, q) printf("%lld\n", dis[n]);
				exit(0);
			}
			sz = 1;
			a[u] = w;
			getsub(v, u);
	} 
}

inline void work() {
	int u = n;
	ll mx1 = -inf, mx2 = -inf, lst = -inf, ans = -inf;
	while(u) {
		if(a[u]) {
			ckmax(ans, a[u] + dis[u] + max(mx1, mx2));
			ckmax(mx1, a[u] - dis[u]);
		}
		else {
			ckmax(ans, a[u] + dis[u] + max(mx1, lst));
			lst = mx2, ckmax(mx2, a[u] - dis[u]);
		}
		u = fa[u];
	}
	fu(i, 1, q) read(l), printf("%lld\n", min(dis[n], dis[n] + ans + l));
}

int main() {
	read(n), read(q);
	for(int i = 1, u, v, w; i < n; ++i) {
		read(u), read(v), read(w);
		add(u, v, w), add(v, u, w);
	}
	dfs(1), getpath();
	fu(i, 1, n) if(vis[i]) sz = 0, getsub(i, 0);
	work();
}