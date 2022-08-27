#include <bits/stdc++.h>
#define N 256101
#define M 426835
using namespace std;

typedef long long ll;
typedef pair <int, int> pr;

int n, e, beg, end;
int u, v, i, dir;
int to[M], first[N], next[M];
int p[N], cx[N], dep[N];
int cnt = 0;
ll ans = 0;
pr step[N];

void addedge(int u, int v){
	to[++e] = v; next[e] = first[u]; first[u] = e;
	to[++e] = u; next[e] = first[v]; first[v] = e;
}

void dfs_diameter(int x){
	int i, y;
	if(dep[x] > dep[end]) end = x;
	for(i = first[x]; i; i = next[i])
		if((y = to[i]) != p[x]){
			p[y] = x; dep[y] = dep[x] + 1;
			dfs_diameter(y);
		}
}

void remove(int x, int d){
	int i, y;
	for(i = first[x]; i; i = next[i])
		if((y = to[i]) != p[x] && y != cx[x])
			remove(y, d + 1);
	if(cx[x]) return;
	step[++cnt] = (dir == 1 ? pr(beg, x) : pr(end, x));
	ans += d;
}

int main(){
	scanf("%d", &n);
	for(i = 1; i < n; ++i){
		scanf("%d%d", &u, &v);
		addedge(u, v);
	}
	dep[end = 1] = 0; dfs_diameter(1);
	dep[beg = end] = 0; p[end] = 0; dfs_diameter(beg);
	dir = 1;
	cx[end] = n + 1;
	for(v = end; v; cx[p[v]] = v, v = p[v]){
		if(dep[v] << 1 < dep[end]) dir = 2;
		remove(v, dir == 1 ? dep[v] : dep[end] - dep[v]);
	}
	for(v = end; p[v]; v = p[v]){
		step[++cnt] = pr(beg, v);
		ans += dep[v];
	}
	printf("%I64d\n", ans);
	for(i = 1; i <= cnt; ++i)
		printf("%d %d %d\n", step[i].first, step[i].second, step[i].second);
	return 0;	
}