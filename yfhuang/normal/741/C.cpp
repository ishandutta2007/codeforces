#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

const int maxn = 2e5 + 5;

int n;
int a[maxn],b[maxn];

vector<int> G[maxn];

int col[maxn];

bool dfs(int u){
	for(int i = 0;i < G[u].size();i++){
		int v = G[u][i];
		if(col[u] == col[v]) return false;
		if(!col[v]){
			col[v] = 3 - col[u];
			if(!dfs(v)) return false;
		}
	}
	return true;
}

int main(){
	cin >> n;
	for(int i = 1;i <= n;i++){
		G[i * 2].push_back(2 * i - 1);
		G[2 * i - 1].push_back(2 * i);
	}
	for(int i = 1;i <= n;i++){
		scanf("%d%d",a + i,b + i);
		G[a[i]].push_back(b[i]);
		G[b[i]].push_back(a[i]);
	}
	memset(col,0,sizeof(col));
	for(int i = 1;i <= 2 * n;i++){
		if(col[i] == 0){
			col[i] = 1;
			dfs(i);
		}
	}
	for(int i = 1;i <= n;i++){
		printf("%d %d\n",col[a[i]],col[b[i]]);
	}
	return 0;
}