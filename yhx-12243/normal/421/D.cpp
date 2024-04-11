#include <bits/stdc++.h>
#define N 341468
#define M 682936
using namespace std;

typedef long long ll;

struct edge{
	int u, v, w;
	edge (int u0 = 0, int v0 = 0): u(u0), v(v0), w(1) {}
	bool operator < (const edge &B) const {return u < B.u || (u == B.u && v < B.v);}
	bool operator == (const edge &B) const {return u == B.u && v == B.v;}
}e[M];

int n, p, E, Es = 0;
int u, v, w, r, i;
int first[N], next[M];
int deg[N], ord[N];
ll ans;

inline bool cmp(const int x, const int y) {return deg[x] > deg[y];}
inline void addedge(int id) {next[id] = first[e[id].u]; first[e[id].u] = id;}

int main(){
	scanf("%d%d", &n, &p);
	for(i = 1; i <= n; ++i){
		scanf("%d%d", &u, &v);
		e[(i << 1) - 1] = edge(u, v);
		e[i << 1] = edge(v, u);
		++deg[u]; ++deg[v]; ord[i] = i;
	}
	sort(ord + 1, ord + (n + 1), cmp);
	sort(e + 1, e + (n << 1 | 1));
	for(i = 1; i <= n << 1; ++i) e[i] == e[i - 1] ? ++e[E].w : (e[++E] = e[i]);
	for(i = 1; i <= E; ++i) addedge(i);
	for(u = 1; u <= n; ++u){
		*deg = p - deg[u];
		r = upper_bound(ord + 1, ord + (n + 1), 0, cmp) - (ord + 1);
		r -= deg[u] << 1 >= p;
		for(i = first[u]; i; i = next[i]){
			v = e[i].v;
			r -= (deg[u] + deg[v] >= p && deg[u] + deg[v] - e[i].w < p);
		}
		ans += r;
	}
	printf("%I64d\n", ans >> 1);
	return 0;
}