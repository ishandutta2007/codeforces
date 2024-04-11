#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;

int t, n, m, a, b, ui, vi;
vector <int> g[MAXN];

bool vis[MAXN];
pair <int, int> dfs(int u){
	vis[u] = true;
	
	pair <int, int> ret = make_pair(1, 0);
	for(int v : g[u]){
		if(v == a)ret.second |= 1;
		else if(v == b)ret.second |= 2;
		else if(vis[v])continue;
		else{
			pair <int, int> cret = dfs(v);
			ret.first += cret.first;
			ret.second |= cret.second;
		}
	}
	return ret;
}

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d %d %d %d", &n, &m, &a, &b);
		a--, b--;
		
		for(int i = 0; i < n; i++){
			g[i].clear();
			vis[i] = false;
		}
		
		while(m--){
			scanf("%d %d", &ui, &vi);
			ui--, vi--;
			
			g[ui].push_back(vi);
			g[vi].push_back(ui);
		}
		
		int x = 0, y = 0;
		long long res = 0;
		
		for(int i = 0; i < n; i++){
			if(vis[i] || i == a || i == b)continue;
		
			pair <int, int> ret = dfs(i);
			if(ret.second == 3)continue;
			
			if(ret.second == 1){
				res += 1LL * ret.first * y;
				x += ret.first;
			}else{
				res += 1LL * ret.first * x;
				y += ret.first;
			}
		}
		printf("%lld\n", res);
	}
	
	return 0;
}