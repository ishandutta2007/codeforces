#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

int n, pi;
vector <int> G[MAXN];

int sz[MAXN];
void calcsz(int u){
	sz[u] = 1;
	for(int v : G[u]){
		calcsz(v);
		sz[u] += sz[v];
	}
}

double e[MAXN];
void dfs(int u){
	for(int v : G[u]){
		e[v] = e[u] + 1 + (sz[u] - sz[v] - 1) / 2.0;
		dfs(v);
	}
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i < n; i++){
		scanf("%d", &pi);
		G[pi - 1].push_back(i);
	}

	calcsz(0);

	e[0] = 1.0;
	dfs(0);

	for(int i = 0; i < n; i++){
		if(i > 0)printf(" ");
		printf("%.9f", e[i]);
	}
	printf("\n");

	return 0;
}