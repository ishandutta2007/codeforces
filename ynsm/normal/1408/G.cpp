#include <bits/stdc++.h>
 
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
 
const int N = 3050, inf = 1e9, mod = 998244353;
const ll INF = 1e18;
 
vector< int > g[N];
int n, m, a[N][N], p[N][N], pr[N], sz[N], id[N][N], cnt[N], edges[N];
ll dp[N][N], tmp[N];
pii b[N];
bool used[N][N], was[N][N];

int get_p(int v){
	return (v == pr[v] ? v : pr[v] = get_p(pr[v]));
}
void unite(int v, int u, int k){
	v = get_p(v);
	u = get_p(u);
	if(v != u){
		pr[u] = v;
		sz[v] += sz[u];
		edges[v] += edges[u];
	}
	edges[v]++;
	if(edges[v] == sz[v] * (sz[v] - 1) / 2 && sz[v] == k + 1){
		for(int i = 0; i < n; i++)
			if(get_p(i) == v)
				id[i][sz[v] - 1] = m;
		m++;
	}
}
void add_edge(int v, int to){
	if(!was[v][to])
		g[v].pb(to);
	was[v][to] = 1;
}
void dfs(int v){
	if(v < n){
		cnt[v] = 1;
		dp[v][1] = 1;
		return;
	}
	dp[v][0] = 1;
	for(auto to : g[v]){
		dfs(to);
	    for(int i = 0; i <= cnt[v] + cnt[to]; i++)
	    	tmp[i] = 0;
		for(int i = 0; i <= cnt[v]; i++)
			for(int j = 0; j <= cnt[to]; j++)
				tmp[i + j] = (tmp[i + j] + dp[v][i] * dp[to][j]) % mod;
	    for(int i = 0; i <= cnt[v] + cnt[to]; i++)
	    	dp[v][i] = tmp[i];
		cnt[v] += cnt[to];
	}
	dp[v][1] = (dp[v][1] + 1) % mod;
}
int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			scanf("%d", &a[i][j]);
			b[j] = {a[i][j], j};
		}
		sort(b, b + n);
		for(int j = 0; j < n; j++)
			p[i][j] = b[j].s;
	}
	for(int i = 0; i < n; i++){
		pr[i] = i;
		sz[i] = 1;
		id[i][0] = m++;
		for(int j = 1; j < n; j++)
			id[i][j] = -1;
	}
	for(int j = 1; j < n; j++){
		for(int i = 0; i < n; i++){
			used[i][p[i][j]] = 1;
			if(used[p[i][j]][i])
				unite(i, p[i][j], j);
		}			
	}
	
	for(int i = 0; i < n; i++){
		int last = id[i][n - 1];
		for(int j = n - 2; j >= 0; j--){
			if(id[i][j] == -1)
				continue;
			add_edge(last, id[i][j]);
			last = id[i][j];
		}
	}
	int root = id[0][n - 1];
	dfs(root);
	for(int i = 1; i <= n; i++)
		printf("%lld ", dp[root][i]);
}