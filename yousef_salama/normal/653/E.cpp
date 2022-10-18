#include <bits/stdc++.h>
using namespace std;

const int MAXN = 300005;

int n, m, k, ai, bi;
set <int> G[MAXN];

set <int> vis;
bool marked[MAXN];

void dfs(int u){
	vis.erase(u);
	marked[u] = true;

	int st = -1;
	while(true){
		auto d = vis.upper_bound(st);

		if(d == vis.end())break;
		if(G[u].count(*d)){
			st = *d;
			continue;
		}
		dfs(*d);
	}
}
int main(){
	scanf("%d %d %d", &n, &m, &k);
	for(int i = 0; i < m; i++){
		scanf("%d %d", &ai, &bi);
		ai--, bi--;

		G[ai].insert(bi);
		G[bi].insert(ai);
	}

	bool ok = ((n - 1) - (int)G[0].size() >= k);

	if(ok){
		for(int i = 0; i < n; i++)
			vis.insert(i);
		dfs(0);

		if(!vis.empty())printf("impossible\n");
		else{
			for(int i = 1; i < n; i++)
				vis.insert(i);

			int c = 0;
			for(int i = 1; i < n; i++)if(vis.count(i)){
				dfs(i);
				c++;
			}

			if(c > k)printf("impossible\n");
			else printf("possible\n");
		}

	}else printf("impossible\n");

	return 0;
}