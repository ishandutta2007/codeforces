#include <bits/stdc++.h>

#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 

using namespace std;                    

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)3e5 + 123, inf = 1e9;
const ll INF = 1e18;

vector< pii > g[N];
ll dp[N], ans;
int n, w[N];
void dfs(int v, int p){
	dp[v] = w[v];
	for(auto it : g[v]){
		int to = it.f;
		int c = it.s;
		if(to == p)
			continue;
		dfs(to, v);
		ans = max(ans, dp[v] + dp[to] - c);
    	dp[v] = max(dp[v], dp[to] - c + w[v]);
    }
	ans = max(ans, dp[v]);
}
int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &w[i]);
	for(int i = 1; i < n; i++){
		int v, u, w;
		scanf("%d%d%d", &v, &u, &w);
		g[v].pb({u, w});
		g[u].pb({v, w});
	}
	dfs(1, 1);
	printf("%lld", ans);
	return 0;
}