#include <bits/stdc++.h>
#define len(x) ((int)(x).size())
#define x first
#define y second
using namespace std;

const int N = 2e5 + 10, K = 10;

int n, k, sz[N];
vector<int> adj[N];
int qtd[N][K];
long long many[K], ans;

void dfs(int u, int p){
	sz[u] = 1;
	for(int v : adj[u]) if(v != p){
		dfs(v, u);
		sz[u] += sz[v];
	}
	ans += (n - sz[u])*1LL*sz[u];
	qtd[u][0] = 1;
	for(int v : adj[u]) if(v != p){
		for(int i = 0; i < k; i++){
			for(int j = 0; j < k; j++){
				many[(i + j + 1)%k] += qtd[u][i]*1LL*qtd[v][j];
			}
		}
		for(int i = 0; i < k; i++){
			qtd[u][(i + 1)%k] += qtd[v][i];
		}
	}
}

int main(){
	scanf("%d %d", &n, &k);
	for(int i = 1; i < n; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1, 1);
	for(int i = 1; i < k; i++){
		ans += (k - i)*many[i];
	}
	printf("%lld\n", ans/k);
	return 0;
}