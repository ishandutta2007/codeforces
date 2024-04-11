#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2005;

int n, pi, c[MAXN], ans[MAXN];
vector <int> g[MAXN], h[MAXN];

bool calc(int u){
	for(int v : g[u]){
		if(!calc(v))return false;
		
		for(int x : h[v])
			h[u].push_back(x);
		h[v].clear();
	}
	
	if((int)h[u].size() < c[u])return false;
	else{
		h[u].insert(h[u].begin() + c[u], u);
		return true;
	}
}

int main(){
	scanf("%d", &n);
	
	int r = -1;
	for(int i = 0; i < n; i++){
		scanf("%d %d", &pi, &c[i]);
		
		if(pi > 0)g[pi - 1].push_back(i);
		else r = i;
	}
	
	if(!calc(r)){
		printf("NO\n");
		return 0;
	}
	
	for(int i = 0; i < n; i++)
		ans[h[r][i]] = i + 1;
	
	printf("YES\n");
	for(int i = 0; i < n; i++){
		if(i > 0)printf(" ");
		printf("%d", ans[i]);
	}
	printf("\n");
	
	return 0;
}