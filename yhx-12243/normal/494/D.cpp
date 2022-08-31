#include <bits/stdc++.h>
#define N 100034
#define M 256101
#define LN 18
#define lg2(x) (31 - __builtin_clz(x))
using namespace std;

typedef long long ll;
const ll mod = 1000000007;

struct edge{
	int u, v, w;
	edge (int u0 = 0, int v0 = 0, int w0 = 0): u(u0), v(v0), w(w0) {}
}e[M];

int n, q, E;
int first[N], next[M];
int p[N], dep[N], f0[N], g0[N];
ll deep[N], f1[N], f2[N], g1[N], g2[N];
int cnt = 0, id[N], st[LN][M], *o = *st;

inline void add(int &x, const int y) {(x += y) >= mod ? x -= mod : 0;}
inline void add(ll &x, const ll y) {(x += y) >= mod ? x -= mod : 0;}
inline int min(const int x, const int y) {return x < y ? x : y;}
inline int dmin(const int x, const int y) {return dep[x] < dep[y] ? x : y;}
inline void addedge(int u, int v, int w){
	e[++E] = edge(u, v, w); next[E] = first[u]; first[u] = E;
	e[++E] = edge(v, u, w); next[E] = first[v]; first[v] = E;
}

void build_sparse_table(){
	int *f, *g = o, i, j, k = cnt;
	for(j = 0; 1 << j + 1 <= cnt; ++j){
		f = g; g = st[j + 1]; k -= 1 << j;
		for(i = 0; i < k; ++i)
			g[i] = dmin(f[i], f[i + (1 << j)]);
	}
}

inline int LCA(int x, int y){
	int L = min(id[x], id[y]), R = (id[x] ^ id[y] ^ L) + 1, D = R - L, c = lg2(D);
	return dmin(st[c][L], st[c][R - (1 << c)]);
}

void dfs_basis(int x){
	int i, y;
	f0[x] = 1; f1[x] = f2[x] = 0;
	id[x] = cnt; o[cnt++] = x;
	for(i = first[x]; i; i = next[i])
		if((y = e[i].v) != p[x]){
			p[y] = x; dep[y] = dep[x] + 1;
			deep[y] = deep[x] + e[i].w;
			dfs_basis(y);
			add(f0[x], f0[y]);
			add(f1[x], (f1[y] + (ll)f0[y] * e[i].w) % mod); 
			add(f2[x], (f2[y] + ((f1[y] << 1) + (ll)f0[y] * e[i].w) % mod * e[i].w) % mod);
			/*
			f0[x] = f0[x] + f0[y]
			f1[x] = f1[x] + f1[y] + w f0[y]
			f2[x] = f2[x] + f2[y] + 2 w f1[y] + w^2 f0[y]
			*/
			assert(0 <= f0[x] && f0[x] < mod);
			assert(0 <= f1[x] && f1[x] < mod);
			assert(0 <= f2[x] && f2[x] < mod);
			o[cnt++] = x;
		}

}

void dfs_calc(int x){
	int i, y; ll t;
	for(i = first[x]; i; i = next[i])
		if((y = e[i].v) != p[x]){
			g0[y] = g0[x];
			t = ((ll)g0[x] - ((ll)f0[y] << 1)) * e[i].w % mod;
			add(g1[y] = g1[x], t < 0 ? t + mod : t);
			t = ((g1[y] - (f1[y] << 1) << 1) - (ll)g0[x] * e[i].w) % mod * e[i].w % mod;
			add(g2[y] = g2[x], t < 0 ? t + mod : t);
			/*
			g0[y] = g0[x]
			g1[y] = g1[x] + w (g0[x] - 2 f0[y])
			g2[y] = g2[x] + 2 w (g1[x] - 2 f1[y]) + w^2 (g0[x] - 4 f0[y])
			      = g2[x] + 2 w (g1[y] - 2 f1[y]) - w^2 g0[x]
			*/
			assert(g0[y] == n);
			assert(0 <= g1[y] && g1[y] < mod);
			assert(0 <= g2[y] && g2[y] < mod);
			dfs_calc(y);
		}
}

int main(){
	int u, v, w, l, i; ll D, R, c0, c1, c2;
	scanf("%d", &n);
	for(i = 1; i < n; ++i){
		scanf("%d%d%d", &u, &v, &w);
		addedge(u, v, w);
	}
	dfs_basis(1);
	build_sparse_table();
	g0[1] = f0[1]; g1[1] = f1[1]; g2[1] = f2[1];
	dfs_calc(1);
	for(scanf("%d", &q); q; --q){
		scanf("%d%d", &u, &v);
		l = LCA(u, v);
		D = (deep[u] + deep[v] - (deep[l] << 1)) % mod;
		if(l == v){
			c0 = g0[v] - f0[v]; c1 = g1[v] - f1[v]; c2 = g2[v] - f2[v];
			R = (c0 * D + (c1 << 1)) % mod * D + c2;
			// R = D^2 c0[v] + 2 D c1[v] + c2[v]
			R = (g2[u] - (R << 1)) % mod;
			// R = (g2[u] - R) - R
		}else{
			R = (f0[v] * D + (f1[v] << 1)) % mod * D + f2[v];
			// R = D^2 f0[v] + 2 D f1[v] + f2[v]
			R = ((R << 1) - g2[u]) % mod;
			// R = R - (g2[u] - R)
		}
		R < 0 ? R += mod : 0;
		printf("%d\n", (int)R);
	}
	return 0;
}