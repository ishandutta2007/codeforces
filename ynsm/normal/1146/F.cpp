#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)2e5 + 123, inf = 1e9, mod = 998244353;
const ll INF = 1e18;

vector< int > g[N];
int n;
ll dp[N][2];
void dfs(int v){
	if(g[v].size() == 0){
		dp[v][0] = dp[v][1] = 1;
		return;
	}
    if(g[v].size() == 1){
		int u = g[v][0];
		dfs(u);
		dp[v][0] = dp[u][0];
		dp[v][1] = dp[u][1];
		return;
	}
    ll a, b, c;
    a = 1;
    b = 0;
    c = 0;
    for(auto to : g[v]){
		dfs(to);
		c = (b + c) * dp[to][1] + c * dp[to][0];
		b = a * dp[to][1] + b * dp[to][0];
		a = a * dp[to][0];

		a %= mod;
		b %= mod;
		c %= mod;
	}
	dp[v][0] = (a + c) % mod;
	dp[v][1] = (b + c) % mod;
}   	
int main()
{
	scanf("%d", &n);
	for(int i = 2; i <= n; i++){
		int p;
		scanf("%d", &p);
		g[p].pb(i);
	}
	dfs(1);
	printf("%lld", dp[1][0]);
	return 0;
}