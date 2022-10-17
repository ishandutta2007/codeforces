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

const int N = 1e5 + 5;
int n, q, cnt, head[N], to[N << 1], nxt[N << 1], val[N << 1], rt, id[N], mp[N], fa[N], siz[N];
ll f[N], d[N], qd;

inline void add(int u, int v, int w) {
	to[++cnt] = v, val[cnt] = w;
	nxt[cnt] = head[u], head[u] = cnt;
}  

void dfs1(int u, int fa) {
	go(u) 
		if(v != fa) {
			f[v] = f[u] + w;
			dfs1(v, u); 
		}
}

void dfs2(int u, int fa) {
	go(u) 
		if(v != fa) {
			d[v] = d[u] + w;
			dfs2(v, u);
		}
}

void dfs(int u, int fa) {
	ckmax(d[u], f[u]);
	go(u)
		if(v != fa) {
			f[v] = f[u] + w;
			dfs(v, u);
		}
}

int get(int x) {
	return x == fa[x] ? x : fa[x] = get(fa[x]);
}

inline void merge(int u, int v) {
	if(u == v) return;
	if(siz[u] > siz[v]) swap(u, v);
	siz[v] += siz[u], fa[u] = v;
} 

inline bool cmp(const int &a, const int &b) {return d[a] > d[b];}

int main() {
	read(n);
	for(int i = 1, u, v, w; i < n; ++i) {
		read(u), read(v), read(w);
		add(u, v, w), add(v, u, w);
	}
	dfs1(1, 0); fu(i, 1, n) if(f[rt] < f[i]) rt = i; dfs2(rt, 0); 
	rt = 0; fu(i, 1, n) if(d[rt] < d[i]) rt = i; f[rt] = 0; dfs(rt, 0);
	fu(i, 1, n) id[i] = i; sort(id + 1, id + n + 1, cmp);
	fu(i, 1, n) mp[id[i]] = i;
	read(q); while(q--) {
		read(qd); int ans = 1;
		fu(i, 1, n) fa[i] = i, siz[i] = 1;
		for(rg int i = 1, l = 1; i <= n; ++i) {
			while(d[id[l]] - qd > d[id[i]]) --siz[get(id[l++])];
			go(id[i]) if(l <= mp[v] && mp[v] <= i) merge(get(id[i]), get(v));
			ckmax(ans, siz[get(id[i])]);
		}
		printf("%d\n", ans);
	}
	return 0;
}