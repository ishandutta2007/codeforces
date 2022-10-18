#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

int n;
vector <int> g[MAXN];

int sz[MAXN];
vector <int> cent;

void dfs(int u, int parent = -1){
	sz[u] = 1;
	
	bool ok = true;
	for(int v : g[u]){
		if(v == parent)continue;
		
		dfs(v, u);
		sz[u] += sz[v];
	
		if(sz[v] * 2 > n)ok = false;
	}
	
	if(ok && 2 * sz[u] >= n){
		cent.push_back(u);
	}
}

pair <int, int> findleaf(int u, int parent){
	for(int v : g[u]){
		if(v == parent)continue;
		return findleaf(v, u);
	}
	
	return make_pair(u, parent);
}

int main(){
	int t;
	scanf("%d", &t);
	
	while(t--){
		scanf("%d", &n);
		for(int i = 0; i < n; i++)g[i].clear();
		
		for(int i = 0; i < n - 1; i++){
			int xi, yi;
			scanf("%d %d", &xi, &yi);
			xi--, yi--;
			
			g[xi].push_back(yi);
			g[yi].push_back(xi);
		}
		
		cent.clear();
		dfs(0);
		
		if((int)cent.size() == 1){
			printf("%d %d\n", 1, g[0][0] + 1);
			printf("%d %d\n", 1, g[0][0] + 1);
		}else{
			//cout << "2 centroids" << endl;
			
			pair <int, int> z = findleaf(cent[0], cent[1]);
			printf("%d %d\n", z.first + 1, z.second + 1);
			printf("%d %d\n", z.first + 1, cent[1] + 1);
		}
	}
	return 0;
}