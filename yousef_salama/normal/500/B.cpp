#include <bits/stdc++.h>
using namespace std;

const int MAXN = 305;

int n, p[MAXN];
char g[MAXN][MAXN];

bool vis[MAXN];
vector <int> pos, val;

void dfs(int u){
	vis[u] = true;
	pos.push_back(u);
	val.push_back(p[u]);
	
	for(int v = 0; v < n; v++)
		if(g[u][v] == '1' && !vis[v])dfs(v);
}

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &p[i]);
	for(int i = 0; i < n; i++)
		scanf("%s", g[i]);
	
	for(int i = 0; i < n; i++){
		pos.clear();
		val.clear();
		dfs(i);
		
		sort(pos.begin(), pos.end());
		sort(val.begin(), val.end());
		
		for(int j = 0; j < (int)pos.size(); j++)
			p[pos[j]] = val[j];
	}
	
	for(int i = 0; i < n; i++){
		if(i > 0)printf(" ");
		printf("%d", p[i]);
	}
	printf("\n");
		
	return 0;
}