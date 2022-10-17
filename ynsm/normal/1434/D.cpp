#include <bits/stdc++.h>
 
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
 
const int N = (int)1e6 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;
 
int n;
vector< pii > g[N];
int w[N], V[2], L[2][N], R[2][N], timer[2], lvl[N], val[N];

pii t[N << 2];
bool u[N << 2];

void build(int v, int tl, int tr){
	if(tl == tr){
		t[v] = {val[tl], 0};
		if(u[v])
			swap(t[v].f, t[v].s);
		return;
	}
	int tm = (tl + tr) >> 1;
	build(v << 1, tl, tm);
	build(v << 1  | 1, tm + 1, tr);            
	t[v].f = max(t[v << 1].f, t[v << 1 | 1].f);
	t[v].s = max(t[v << 1].s, t[v << 1 | 1].s);
	if(u[v])
		swap(t[v].f, t[v].s);
}
void upd(int v, int tl, int tr, int l, int r){
	if(r < tl || tr < l)
		return;
	if(l <= tl && tr <= r){
		u[v] ^= 1;
		swap(t[v].f, t[v].s);
		return;
	}
	int tm = (tl + tr) >> 1;
	upd(v << 1, tl, tm, l, r);
	upd(v << 1 | 1, tm + 1, tr, l, r);
	t[v].f = max(t[v << 1].f, t[v << 1 | 1].f);
	t[v].s = max(t[v << 1].s, t[v << 1 | 1].s);
	if(u[v])
		swap(t[v].f, t[v].s);
}
pii f(int v, int p, int d){
	pii ans = {d, v};
	for(auto to : g[v])
		if(to.f != p)
			ans = max(ans, f(to.f, v, d + 1));		
	return ans;
}
void dfs(int v, int p, int col, int k){
	if(v == p)
		lvl[v] = 0, ++timer[k];
    else
    	lvl[v] = lvl[p] + 1;
	val[timer[k]] = lvl[v];
	if(col)
		upd(2 | k, 1, n, timer[k], timer[k]);
	for(auto to : g[v])
		if(to.f != p){
			L[k][to.s] = ++timer[k];
			dfs(to.f, v, col ^ w[to.s], k);
			R[k][to.s] = timer[k];
		}
}
int main()
{
	scanf("%d", &n);
	for(int i = 1; i < n; i++){
		int v, u;
		scanf("%d%d%d", &v, &u, &w[i]);
		g[v].pb({u, i});
		g[u].pb({v, i});
	}
    V[0] = f(1, 1, 0).s;
    V[1] = f(V[0], V[0], 0).s;
	    
    
	dfs(V[0], V[0], 0, 0);
	build(2, 1, n);
    
    dfs(V[1], V[1], 0, 1);
	build(3, 1, n);
	
	int q;
	scanf("%d", &q);
	while(q--){
		int x;
		scanf("%d", &x);
		upd(2, 1, n, L[0][x], R[0][x]); 
		upd(3, 1, n, L[1][x], R[1][x]); 
		printf("%d\n", max(t[2].f, t[3].f));
	}
}