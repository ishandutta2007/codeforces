#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = 200500, mod = 998244353 ;
      
vector< int > g[N];
int n;
ll dp[N];
void dfs(int v, int p){
	dp[v] = 1;
	int cnt = 1;
	if(v != 1)
		cnt++;
	for(auto to : g[v]){
		if(to == p)
			continue;
		dfs(to, v);
		dp[v] = dp[v] * dp[to] % mod;
		dp[v] = dp[v] * cnt % mod;
		cnt++;		
	}
}
int main()
{
	scanf("%d", &n);
	for(int i = 1; i < n; i++){
		int v, u;
		scanf("%d%d", &v, &u);
		g[v].pb(u);
		g[u].pb(v);
	}
	dfs(1, 1);
	printf("%lld", dp[1] * n % mod);
	return 0;
}