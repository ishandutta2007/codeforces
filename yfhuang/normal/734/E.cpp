#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

const int maxn = 200000 + 5;
const int INF = 0x3f3f3f3f;

int col[maxn];
int dis[maxn];

vector<int> G[maxn];

void dfs(int u,int fa){
	for(int i = 0;i < G[u].size();i++){
		int v = G[u][i];
		if(v == fa) continue;
		dis[v] = dis[u] + (col[u] ^ col[v]);
		dfs(v,u);
	}
}

int n;

int main(){
	cin >> n;
	for(int i = 1;i <= n;i++){
		scanf("%d",&col[i]);
	}
	for(int i = 1;i < n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	memset(dis,INF,sizeof(dis));
	dis[1] = 0;
	dfs(1,-1);
	int u = 1;
	for(int i = 1;i <= n;i++){
		if(dis[i] > dis[u]) u = i;
	}
	memset(dis,INF,sizeof(dis));
	dis[u] = 0;
	dfs(u,-1);
	for(int i = 1;i <= n;i++){
		if(dis[i] > dis[u]) u = i;
	}
	cout << (dis[u] + 1) / 2 << endl;
	return 0;
}