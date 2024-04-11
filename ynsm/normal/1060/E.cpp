#include <bits/stdc++.h>

#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 

using namespace std;                    

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)2e5 + 123, mod = (int)1e9 + 7, inf = (int)1e9, LOG = 18;

vector<int> g[N];
int n;
ll ans, sz[N], depth[N], cnt[2];
void dfs(int v, int p){
	sz[v] = 1;
	cnt[depth[v]]++;
	for(auto to : g[v]){
		if(to == p)
			continue;
		depth[to] = (depth[v] ^ 1);
		dfs(to, v);
		ans += sz[to] * ( n - sz[to]);
		sz[v] += sz[to];
    }
}
int main(){
	scanf("%d", &n);
	for(int i = 1; i < n; i++){
		int v, u;
		scanf("%d%d", &v, &u);
		g[v].pb(u);
		g[u].pb(v);
	}
	dfs(1, 1);
	ans = (ans - cnt[0] * cnt[1]) / 2 + cnt[0] * cnt[1]; 
	printf("%lld", ans);
}