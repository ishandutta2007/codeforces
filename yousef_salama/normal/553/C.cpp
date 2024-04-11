#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
const int MOD = 1000000007;

int n, m, ai, bi, ci;
vector < pair <int, int> > G[MAXN];

int color[MAXN];
bool dfs(int u){
	for(pair <int, int> e : G[u]){
		if(color[e.first] == -1){
			color[e.first] = color[u] ^ e.second;
			if(!dfs(e.first))return false;
		}else if(color[e.first] != (color[u] ^ e.second))return false;
	}
	return true;
}
int main(){
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++){
		scanf("%d %d %d", &ai, &bi, &ci);
		ai--, bi--;

		G[ai].push_back({bi, ci ^ 1});
		G[bi].push_back({ai, ci ^ 1});
	}

	memset(color, -1, sizeof color);

	int r = 1, f = 1;
	for(int i = 0; i < n; i++)if(color[i] == -1){
		color[i] = 0;

		if(!dfs(i)){
			r = 0;
			break;
		}else{
			if(f == 1)r = 1, f = 0;
			else r = (r * 2) % MOD;
		}
	}
	printf("%d\n", r);

	return 0;
}