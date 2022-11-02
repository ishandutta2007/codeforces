#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

const int maxn = 3e5 + 5;

vector<int> G[maxn];
int s,t;
int n;

int sz[maxn];
bool vis[maxn];

void dfs(int u,int fa){
	sz[u] = 1;
	if(u == t) vis[u] = 1;
	for(auto v:G[u]){
		if(v == fa) continue;
		dfs(v,u);
		sz[u] += sz[v];
		vis[u] |= vis[v];
	}
}


int main(){
	cin >> n >> s >> t;
	for(int i = 1;i < n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(s,s);
	long long ans = 1LL * n * (n - 1);
	for(auto v: G[s]){
		if(vis[v]){
			ans -= 1LL * (n - sz[v]) * sz[t];
		}
	}
	cout << ans << endl;
	return 0;
}