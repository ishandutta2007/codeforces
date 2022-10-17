#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = 3000500, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;

vector< int > g[N];
int n, m, k, c[N], pp[N], p[N], t[N], pos[N], ord[N];
bool ok;
void dfs(int v){
	if(c[v] == 2)
		return;
	if(c[v] == 1){
		ok = 0;
		return;
	}
	c[v] = 1;
	for(auto to : g[v])
		dfs(to);
	c[v] = 2;
	ord[k++] = v;
}
void build(int v, int tl, int tr){
	t[v] = m++;
	if(tl == tr){
		p[tl] = t[v];
		return;
	}
	int tm = (tl + tr) >> 1;
	build(v << 1, tl, tm);
	build(v << 1 | 1, tm + 1, tr);
	g[t[v << 1]].pb(t[v]);
	g[t[v << 1 | 1]].pb(t[v]);
}
void upd(int v, int tl, int tr, int l, int r, int i){
	if(r < tl || tr < l || l > r)
		return;
	if(l <= tl && tr <= r){
		g[t[v]].pb(p[i]);
		return;
	}
	int tm = (tl + tr) >> 1;
	upd(v << 1, tl, tm, l, r, i);
	upd(v << 1 | 1, tm + 1, tr, l, r, i);
} 
void solve(){
	scanf("%d", &n);
	build(1, 1, n);
	for(int i = 1; i <= n; i++){
		int x;
		scanf("%d", &x);
		if(x == -1)
			continue;
		upd(1, 1, n, i + 1, x - 1, i);
		if(x != n + 1)
			g[p[i]].pb(p[x]);
	}
	ok = 1;
	for(int i = 0; i < m; i++)
		c[i] = -1;
	for(int i = 0; i < m; i++)
		if(c[i] == -1)
			dfs(i);
	for(int i = 0; i < m; i++)
		pos[ord[i]] = i;
	if(ok){
		for(int i = 1; i <= n; i++)
			pp[i] = pos[p[i]];
		sort(pp + 1, pp + 1 + n);
		for(int i = 1; i <= n; i++)
			printf("%d ", n - (lower_bound(pp + 1, pp + 1 + n, pos[p[i]]) - pp) + 1);
		printf("\n");	
	}else{
		printf("-1\n");
	}
	for(int i = 0; i < m; i++)
		g[i].clear();
	ok = 0;
	m = k = 0;
}
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
		solve();
	return 0;
}