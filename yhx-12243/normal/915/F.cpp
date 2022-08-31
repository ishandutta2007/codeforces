#include <bits/stdc++.h>
#define N 1024404
using namespace std;

typedef long long ll;

struct edge{
	int u, v, w;
	edge (int u0 = 0, int v0 = 0): u(u0), v(v0), w(0) {}
	edge * read() {scanf("%d%d", &u, &v); return this;}
	inline bool operator < (const edge &B) const {return w < B.w;}
}e[N];

int n;
int w[N], p[N], sz[N];
ll ans;

int ancestor(int x) {return p[x] == x ? x : (p[x] = ancestor(p[x]));}

ll solve(){
	int u, v, i; ll res = 0;
	for(i = 1; i <= n; ++i) {p[i] = i; sz[i] = 1;}
	for(i = 1; i < n; ++i) e[i].w = max(w[e[i].u], w[e[i].v]);
	sort(e + 1, e + n);
	for(i = 1; i < n; ++i){
		u = ancestor(e[i].u); v = ancestor(e[i].v);
		res += (ll)e[i].w * sz[u] * sz[v];
		if(sz[u] > sz[v]) swap(u, v); p[u] = v; sz[v] += sz[u];
	}
	return res;
}

int main(){
	int i;
	scanf("%d", &n);
	for(i = 1; i <= n; ++i) scanf("%d", w + i);
	for(i = 1; i < n; ++i) e[i].read();
	ans += solve();
	for(i = 1; i <= n; ++i) w[i] = -w[i];
	printf("%I64d\n", ans + solve());
	return 0;
}