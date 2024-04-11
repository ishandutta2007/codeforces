#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;

int n, m, k, a, b;
vector <int> G[MAXN];

bool vis[MAXN];
vector <int> e;
void eulertour(int u){
	vis[u] = true;
	e.push_back(u + 1);

	for(int v : G[u]){
		if(vis[v])continue;

		eulertour(v);
		e.push_back(u + 1);
	}
}
int main(){
	scanf("%d %d %d", &n, &m, &k);
	for(int i = 0; i < m; i++){
		scanf("%d %d", &a, &b);
		a--, b--;

		G[a].push_back(b);
		G[b].push_back(a);
	}

	eulertour(0);

	int r = e.size(), x = 0;
	for(int i = 0; i < k; i++){
		int c = min(r - (k - i - 1), (2 * n + k - 1) / k);

		printf("%d", c);
		for(int j = 0; j < c; j++, x++)
			printf(" %d", e[x]);
		printf("\n");

		r -= c;
	}
	return 0;
}