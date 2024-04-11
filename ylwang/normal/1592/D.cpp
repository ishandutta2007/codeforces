#include <bits/stdc++.h>

using namespace std;
const int N = 1e3 + 5;
int id[N], ind, f[N];
vector < int > e[N];
void dfs(int u, int fa) {
	id[++ind] = u, f[u] = fa; 
	for(auto v : e[u]) {
		if(v != fa) dfs(v, u);
	}
}
int ask(int x) {
	printf("? %d ", x);
	while(x) printf("%d ", id[x]), x--;
	fflush(stdout);
	int ans; scanf("%d", &ans);
	return ans;
}
int main() {
	int n; scanf("%d", &n);
	for(int i = 1; i < n; i++) {
		int u, v; scanf("%d %d", &u, &v);
		e[u].push_back(v), e[v].push_back(u);	
	}
	dfs(1, 0);
	int l = 2, r = n;
	int mx = ask(n), ans = 0;
	while(l <= r) {
		int mid = (l + r) >> 1;
		if(ask(mid) == mx) r = mid - 1, ans = mid;
		else l = mid + 1; 	
	}
	assert(ans != 0);
	printf("! %d %d\n", id[ans], f[id[ans]]);
	fflush(stdout);
	return 0;	
}