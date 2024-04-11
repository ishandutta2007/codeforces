#include <bits/stdc++.h>                                                                                                                                                                                      //YaLoh

#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 

using namespace std;                    

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)1e5 + 123, inf = 2e9 + 100;
const ll INF = 1e18;

vector< int > g[N];
int tin[N], tout[N], timer;
int n, s[N], a[N], t[N << 2], u[N << 2];
ll ans;
void push(int v){     
	u[v << 1] += u[v];
	t[v << 1] += u[v];
	u[v << 1 | 1] += u[v];
	t[v << 1 | 1] += u[v];
	u[v] = 0;
}
void upd(int v, int tl, int tr, int l, int r, int val){
	if(r < tl || tr < l || l > r)
		return;
	if(l <= tl && tr <= r){
		t[v] += val;
		u[v] += val;
		return;
	}
	push(v);
	int tm = (tl + tr) / 2;        
	upd(v << 1, tl, tm ,l, r, val);
	upd(v << 1 | 1, tm + 1, tr ,l, r, val);
	t[v] = min(t[v << 1], t[v << 1 | 1]);
}
int get(int v, int tl, int tr, int l, int r){
    if(r < tl || tr < l || l > r)
		return inf;
	if(l <= tl && tr <= r)
		return t[v];
	push(v);
	int tm = (tl + tr) / 2;        
	return min(get(v << 1, tl, tm ,l, r), get(v << 1 | 1, tm + 1, tr ,l, r));
}

void dfs(int v){
	tin[v] = ++timer;
	for(auto to : g[v])
		dfs(to);
	tout[v] = timer;
}
void solve(int v, int lvl){
	if(lvl){
		a[v] = get(1, 1, n, tin[v], tin[v]);
		upd(1, 1, n, tin[v], tout[v], -a[v]);
		if(get(1, 1, n, tin[v], tout[v]) < 0){
			printf("-1");
			exit(0);
		}
			
		for(auto to : g[v])
			solve(to, lvl ^ 1);
	}else{
		a[v] = get(1, 1, n, tin[v], tout[v]);
		if(a[v] > (int)1e9)
			a[v] = 0;
		upd(1, 1, n, tin[v], tout[v], -a[v]);
		for(auto to : g[v])
			solve(to, lvl ^ 1);
	}
	ans += a[v];
}

int main(){
	scanf("%d", &n);
	for(int i = 2; i <= n; i++){
		int p;
		scanf("%d", &p);
		g[p].pb(i);
	}	
	for(int i = 1; i <= n; i++)
		scanf("%d", &s[i]);
	dfs(1);
	for(int i = 1; i <= n; i++)
		if(s[i] == -1)                         
			upd(1, 1, n, tin[i], tin[i], inf);
		else
			upd(1, 1, n, tin[i], tin[i], s[i]);
	solve(1, 1);
	printf("%lld", ans);
	return 0;
}