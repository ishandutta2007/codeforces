#include <bits/stdc++.h>
#define N 256101
#define M 426835
#define LN 18
#define INF 0x3e3e3e3e
using namespace std;

struct edge{
	int u, v, w, id; bool mst;
	edge (int u0 = 0, int v0 = 0, int w0 = 0, int id0 = 0): u(u0), v(v0), w(w0), id(id0), mst(false) {}
	edge * read(int id0) {scanf("%d%d%d", &u, &v, &w); id = id0; return this;}
	bool operator < (const edge &B) const {return w < B.w;}
}e[M];

int V, E;
int first[N], next[M];
int p[N], dep[N], ans[N];
int P[LN + 1][N], *pa = *P;
int W[LN + 1][N], *we = *W;
int C[LN + 1][N], *cx = *C;

inline void up(int &x, const int y) {x < y ? x = y : 0;}
inline void down(int &x, const int y) {x > y ? x = y : 0;}
inline int ancestor(int x) {return p[x] == x ? x : (p[x] = ancestor(p[x]));}
inline bool test(int x, int y, bool un = false){
	if((x = ancestor(x)) == (y = ancestor(y))) return true;
	if(un) p[x] = y; return false;
}
inline void addedge(int id){
	next[id] = first[e[id].u]; first[e[id].u] = id; e[id].mst = true; id += E;
	next[id] = first[e[id].u]; first[e[id].u] = id; e[id].mst = true;
}

void Kruskal(){
	int i, Es = 0;
	for(i = 1; i <= V; ++i) p[i] = i;
	sort(e + 1, e + (E + 1));
	for(i = 1; i <= E; ++i) e[E + i] = edge(e[i].v, e[i].u, e[i].w, e[i].id);
	for(i = 1; i <= E; ++i)
		if(!test(e[i].u, e[i].v, true)){
			addedge(i);
			if(++Es >= V - 1) return;
		}
}

void dfs(int x){
	int i, y;
	for(i = 0; i < LN && P[i][x]; ++i){
		P[i + 1][x] = P[i][P[i][x]];
		W[i + 1][x] = max(W[i][x], W[i][P[i][x]]);
	}
	for(i = first[x]; i; i = next[i])
		if(e[i].mst && (y = e[i].v) != pa[x]){
			pa[y] = x; we[y] = e[i].w;
			dep[y] = dep[x] + 1; dfs(y);
		}
}

int query(int x, int y){
	int i, w = 0;
	if(dep[x] < dep[y]) swap(x, y);
	for(i = LN; i >= 0; --i)
		if(dep[x] - (1 << i) >= dep[y]){
			up(w, W[i][x]); x = P[i][x];
		}
	if(x == y) return w;
	for(i = LN; i >= 0; --i)
		if(P[i][x] != P[i][y]){
			up(w, W[i][x]); x = P[i][x];
			up(w, W[i][y]); y = P[i][y];
		}
	up(w, we[x]); up(w, we[y]);
	return w;
}

void adj(int x, int y, int v){
	int i;
	if(dep[x] < dep[y]) swap(x, y);
	for(i = LN; i >= 0; --i)
		if(dep[x] - (1 << i) >= dep[y]){
			down(C[i][x], v); x = P[i][x];
		}
	if(x == y) return;
	for(i = LN; i >= 0; --i)
		if(P[i][x] != P[i][y]){
			down(C[i][x], v); x = P[i][x];
			down(C[i][y], v); y = P[i][y];
		}
	down(cx[x], v); down(cx[y], v);
}

int main(){
	int i, j;
	scanf("%d%d", &V, &E);
	for(i = 1; i <= E; ++i) e[i].read(i);
	Kruskal();
	dep[1] = 1; dfs(1);
	memset(C, 63, sizeof C);
	for(i = 1; i <= E; ++i)
		if(!e[i].mst){
			ans[e[i].id] = query(e[i].u, e[i].v) - 1;
			adj(e[i].u, e[i].v, e[i].w);
		}
	for(i = LN - 1; i >= 0; --i)
		for(j = 1; j <= V; ++j){
			down(C[i][j], C[i + 1][j]); down(C[i][P[i][j]], C[i + 1][j]);
		}
	for(i = 1; i <= E; ++i)
		if(e[i].mst){
			j = (dep[e[i].u] < dep[e[i].v] ? e[i].v : e[i].u);
			ans[e[i].id] = cx[j] - 1;
		}
	for(i = 1; i <= E; ++i)
		printf("%d%c", ans[i] >= INF ? -1 : ans[i], i == E ? 10 : 32);
	return 0;
}