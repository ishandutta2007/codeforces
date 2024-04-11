#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = 2e5 + 5;

int col[maxn];

int n;
vector<int> G[maxn];

void dfs(int u,int fa){
	int a = col[u];
	int b = col[fa];
	int now = 0;
	for(int i = 0;i < G[u].size();i++){
		int v = G[u][i];
		if(v == fa) continue;
		now++;
		while(now == a || now == b) now++;
		col[v] = now;
		dfs(v,u);
	}
}



int main(){
	while(cin >> n){
		for(int i = 1;i <= n;i++) G[i].clear();
		for(int i = 1;i < n;i++){
			int a,b;
			scanf("%d%d",&a,&b);
			G[a].push_back(b);
			G[b].push_back(a);
		}
		col[0] = 0;
		col[1] = 1;
		dfs(1,0);
		int nn = 0;
		for(int i = 1;i <= n;i++) nn = max(nn,col[i]);
		cout << nn << endl;
		for(int i = 1;i <= n;i++) printf("%d ",col[i]);
	}
	return 0;
}