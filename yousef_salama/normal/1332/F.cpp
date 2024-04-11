#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int MAXN = 300005;

int n, ui, vi;
vector <int> g[MAXN];

long long dp[MAXN][2][2];
long long solve(int u, int a, int b, int parent = -1){
	if(dp[u][a][b] != -1)return dp[u][a][b];
	
	long long r0 = 1, r1 = 1 - b, rn = 1 - b;
	
	for(int v : g[u]){
		if(v == parent)continue;
		
		r0 = r0 * (solve(v, 0, 0, u) + solve(v, 1, 0, u)) % MOD;
		r1 = r1 * (solve(v, 0, 0, u) + solve(v, 1, 1, u)) % MOD;
		rn = rn * solve(v, 0, 0, u) % MOD;
	}
	
	if(a == 0){
		r1 = (r1 - rn + MOD) % MOD;
	}
	
	return dp[u][a][b] = (r0 + r1) % MOD;
}

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n - 1; i++){
		scanf("%d %d", &ui, &vi);
		ui--, vi--;
		
		g[ui].push_back(vi);
		g[vi].push_back(ui);
	}
	
	memset(dp, -1, sizeof dp);
	printf("%lld\n", (solve(0, 0, 0) - 1 + MOD) % MOD);
	
	return 0;
}