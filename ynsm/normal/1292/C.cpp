#include <bits/stdc++.h>
 
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
 
const int N = 3010;

vector< int > g[N];
int n;
bool was[N][N], dd[N][N], used[N];
int SZ[N][N];
ll ans, dp[N][N];
 
int sz(int v, int p){
	if(was[v][p])
		return SZ[v][p];
	was[v][p] = 1;
	SZ[v][p] = 1;
	for(auto to : g[v])
		if(to != p)
			SZ[v][p] += sz(to, v);
	return SZ[v][p];
}
void f(int v, int u, int x, int y){
	if(dd[v][u])
		return;
	dd[v][u] = 1;
	for(auto to : g[v]){
		if(!used[to]){
			used[to] = 1;
			f(to, u, sz(to, v), y);
			used[to] = 0;
			dp[v][u] = max(dp[v][u], dp[to][u] + 1ll * sz(to, v) * y);
		}						
	}
	for(auto to : g[u]){
		if(!used[to]){
			used[to] = 1;
			f(v, to, x, sz(to, u));
			used[to] = 0;
			dp[v][u] = max(dp[v][u], dp[v][to] + 1ll * sz(to, u) * x);
		}						
	}
}
int main()
{
	cin >> n;
	for(int i = 1; i < n; i++){
		int v, u;
		cin >> v >> u;
		g[v].pb(u);
		g[u].pb(v);
	}
	for(int v = 1; v <= n; v++)
		for(auto u : g[v]){
			int x = sz(u, v);
			used[v] = used[u] = 1;
			f(v, u, n - x, x);
			used[v] = used[u] = 0;
			ans = max(ans, dp[v][u] + 1ll * x * (n - x));
		}
	cout << ans;
}