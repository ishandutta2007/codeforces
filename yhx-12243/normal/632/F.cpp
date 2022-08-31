#include <bits/stdc++.h>
#define N 2618
#define M 6829360
using namespace std;

struct edge{
	int u, v, w;
	edge (int u0 = 0, int v0 = 0, int w0 = 0): u(u0), v(v0), w(w0) {}
	inline bool operator < (const edge &B) const {return w < B.w;}
}e[N << 1], ek[M];

struct UFind{
	int sz, *p;
	UFind (): sz(0) {p = NULL;}
	~UFind () {if(p) delete [] (p);}
	void resize(int size){
		if(p) delete [] (p); p = new int[(sz = size) + 1];
		for(int i = 0; i <= sz; i++) p[i] = i;
	}
	int ancestor(int x) {return x == p[x] ? x : p[x] = ancestor(p[x]);}
	bool test(int x, int y, bool un = false){
		if((x = ancestor(x)) == (y = ancestor(y))) return true;
		if(un) p[x] = y; return false;
	}
}uf;

int n, E = 0, Ek = 0, i, j;
int a[N][N], d[N];
int first[N], next[N << 1];

inline void up(int &x, const int y) {x < y ? x = y : 0;}
inline void ensure(bool cond) {if(!cond) {puts("NOT MAGIC"); exit(0);}}
inline void addedge(int u, int v, int w){
	e[++E] = edge(u, v, w); next[E] = first[u]; first[u] = E;
	e[++E] = edge(v, u, w); next[E] = first[v]; first[v] = E;
}

void Kruskal(){
	int i, es = 0;
	uf.resize(n);
	sort(ek + 1, ek + (Ek + 1));
	for(i = 1; i <= Ek; ++i)
		if(!uf.test(ek[i].u, ek[i].v, true)){
			addedge(ek[i].u, ek[i].v, ek[i].w);
			if(++es >= n - 1) return;
		}
}

void dfs(int x, int px){
	int i, y;
	for(i = first[x]; i; i = next[i])
		if((y = e[i].v) != px){
			up(d[y] = d[x], e[i].w);
			dfs(y, x);
		}
}

int main(){
	scanf("%d", &n);
	for(i = 1; i <= n; ++i)
		for(j = 1; j <= n; ++j)
			scanf("%d", a[i] + j);
	for(i = 1; i <= n; ++i) ensure(!a[i][i]);
	for(i = 1; i < n; ++i)
		for(j = i + 1; j <= n; ++j){
			ensure(a[i][j] == a[j][i]);
			ek[++Ek] = edge(i, j, a[i][j]);
		}
	Kruskal();
	for(i = 1; i <= n; ++i){
		memset(d, 0, sizeof d);
		dfs(i, 0);
		for(j = 1; j <= n; ++j)
			ensure(a[i][j] == d[j]);
	}
	return puts("MAGIC"), 0;
}