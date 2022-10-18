#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

int n, m, ai, bi;
vector <int> g[MAXN];
set <int> S;

void dfs(int u){
	S.erase(u);
	
	int j = 0, d = 0;
	while(true){
		set <int> :: iterator nxt = S.lower_bound(d);
		if(nxt == S.end())break;
		
		while(j < (int)g[u].size() && g[u][j] < (*nxt))j++;
		
		if(j < (int)g[u].size() && g[u][j] == (*nxt)){
			d = (*nxt) + 1;
		}else{
			dfs(*nxt);
		}
	}
}

int main(){
	scanf("%d %d", &n, &m);
	while(m--){
		scanf("%d %d", &ai, &bi);
		ai--, bi--;
		
		g[ai].push_back(bi);
		g[bi].push_back(ai);
	}
	
	for(int i = 0; i < n; i++){
		S.insert(i);
		sort(g[i].begin(), g[i].end());
	}
	
	int cnt = 0;
	for(int i = 0; i < n; i++)if(S.count(i)){
		cnt++;
		dfs(i);
	}
	printf("%d\n", cnt - 1);
	
	return 0;
}