#include <bits/stdc++.h>
#define N 1024404
#define M 2048808
using namespace std;

int n, q, e, r;
int u, v, i;
int op, res, last;
int to[M], first[N], next[M];
int f[N];

inline int min(const int x, const int y) {return x < y ? x : y;}
inline void down(int &x, const int y) {x > y ? x = y : 0;}
inline void addedge(int u, int v){
	to[++e] = v; next[e] = first[u]; first[u] = e;
	to[++e] = u; next[e] = first[v]; first[v] = e;
}

void dfs(int x, int px){
	int i, y;
	for(i = first[x]; i; i = next[i])
		if((y = to[i]) != px){
			f[y] = min(f[x], y);
			dfs(y, x);
		}
}

int main(){
	scanf("%d%d", &n, &q);
	for(i = 1; i < n; ++i){
		scanf("%d%d", &u, &v);
		addedge(u, v);
	}
	scanf("%*d%d", &r); res = ++(r %= n);
	f[r] = r; dfs(r, 0);
	for(last = 0; --q; )
		if(scanf("%d%d", &op, &v), v = (v + last) % n + 1, op == 1) down(res, f[v]);
		else printf("%d\n", last = min(res, f[v]));
	return 0;
}