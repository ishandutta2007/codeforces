#include <bits/stdc++.h>
using namespace std;

typedef multiset <int> mset;

const int N = 100034;

int V, V2, E, q;
int u, v;
int w[N << 1];
mset s[N];

inline void down(int &x, const int y) {x > y ? x = y : 0;}

namespace ST{
	#define segc int M = L + R - 1 >> 1, lc = id << 1, rc = lc | 1
	const int N = ::N << 3;
	int x[N], pre[N];

	void build(int id, int L, int R){
		if(L == R) {x[id] = pre[L]; return;}
		segc; build(lc, L, M); build(rc, M + 1, R);
		x[id] = min(x[lc], x[rc]);
	}

	void adj(int id, int L, int R, int h, int v){
		if(L == R) {x[id] = v; return;}
		segc; h <= M ? adj(lc, L, M, h, v) : adj(rc, M + 1, R, h, v);
		x[id] = min(x[lc], x[rc]);
	}

	int range(int id, int L, int R, int ql, int qr){
		if(ql <= L && R <= qr) return x[id];
		segc, s = INT_MAX;
		if(ql <= M) down(s, range(lc, L, M, ql, min(qr, M)));
		if(qr > M) down(s, range(rc, M + 1, R, max(ql, M + 1), qr));
		return s;
	}
}

namespace Tree{
	const int N = ::N << 1, M = N << 1;
	int V = 0, E, to[M], first[N], next[M];
	int p[N], dep[N], size[N];
	int id[N], prf[N], top[N];

	inline void addedge(int u, int v){
		to[++E] = v; next[E] = first[u]; first[u] = E;
		to[++E] = u; next[E] = first[v]; first[v] = E;
	}

	void dfs_wt(int x){
		int i, y, &z = prf[x]; size[x] = 1;
		for(i = first[x]; i; i = next[i])
			if((y = to[i]) != p[x]){
				p[y] = x; dep[y] = dep[x] + 1;
				dfs_wt(y);
				size[y] > size[z] ? z = y : 0;
				size[x] += size[y];
			}
	}

	void dfs_hld(int x, int r){
		int i, y;
		id[x] = ++V; top[x] = r;
		if(!prf[x]) return;
		dfs_hld(prf[x], r);
		for(i = first[x]; i; i = next[i])
			if(!top[y = to[i]])
				dfs_hld(y, y);
	}

	int solve(int u, int v){
		int x = top[u], y = top[v], res = INT_MAX;
		for(; x != y; u = p[x], x = top[u]){
			if(dep[x] < dep[y]) {swap(u, v); swap(x, y);}
			down(res, ST::range(1, 1, V, id[x], id[u]));
		}
		if(dep[u] > dep[v]) swap(u, v);
		down(res, ST::range(1, 1, V, id[u], id[v]));
		if(u > ::V) down(res, w[p[u]]);
		return res;
	}
}

namespace Graph{
	#define stack scx
	const int N = ::N, M = N << 1;
	int V, E, to[M], first[N], next[M];
	int cnt = 0, id[N], low[N];
	int top = 0, stack[N];
	int bcc_cnt = 0;

	inline void addedge(int u, int v){
		to[++E] = v; next[E] = first[u]; first[u] = E;
		to[++E] = u; next[E] = first[v]; first[v] = E;
	}

	void dfs_vbcc(int x, int px){
		int i, y, z;
		id[x] = low[x] = ++cnt; stack[top++] = x;
		for(i = first[x]; i; i = next[i])
			if(!id[y = to[i]]){
				dfs_vbcc(y, x);
				down(low[x], low[y]);
				if(id[x] <= low[y])
					for(Tree::addedge(++bcc_cnt + V, x), z = 0; z != y; )
						Tree::addedge(bcc_cnt + V, z = stack[--top]);
			}else if(y != px)
				low[x] = min(low[x], id[y]);
	}
}

inline void update(int x) {w[x + V] = *s[x].begin();}

int main(){
	int i, j;
	scanf("%d%d%d", &V, &E, &q);
	for(i = 1; i <= V; ++i) scanf("%d", w + i); Graph::V = V;
	for(i = 1; i <= E; ++i) {scanf("%d%d", &u, &v); Graph::addedge(u, v);}
	Graph::dfs_vbcc(1, 0); V2 = Graph::bcc_cnt;
	Tree::dfs_wt(1); Tree::dfs_hld(1, 1);
	for(i = 1; i <= V; ++i)
		if(Tree::p[i] > V) s[Tree::p[i] - V].insert(w[i]);
	for(i = 1; i <= V2; ++i) update(i);
	for(i = 1; i <= Tree::V; ++i) ST::pre[Tree::id[i]] = w[i];
	ST::build(1, 1, Tree::V);
	for(j = 0; q; --q)
		if(scanf("%s%d%d", &j, &u, &v), j == 67){
			if(w[u] == v) continue;
			if((i = Tree::p[u] - V) > 0){
				mset::iterator it = s[i].find(w[u]);
				s[i].erase(it); s[i].insert(v); update(i);
				ST::adj(1, 1, Tree::V, Tree::id[i + V], w[i + V]);
			}
			w[u] = v;
			ST::adj(1, 1, Tree::V, Tree::id[u], v);
		}else
			printf("%d\n", Tree::solve(u, v));
	return 0;
}