#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

struct edge{
	int v, l, index;
	edge(){}
	edge(int v, int l, int index): v(v), l(l), index(index){}
};

int n, q, ai, bi, l[MAXN], rj, wj;
vector <edge> g[MAXN];

int sz[MAXN];
double x[MAXN];

double dfs(int u, int parent = -1){
	double r = 0.0;
	sz[u] = 1;
	
	for(edge e : g[u]){
		if(e.v == parent)continue;
		
		r += dfs(e.v, u);
		int s = sz[e.v];
		
		x[e.index] = 2.0;
		x[e.index] -= 2.0 * s * (s - 1) * (s - 2) / (1.0 * n * (n - 1) * (n - 2));
		x[e.index] -= 2.0 * (n - s) * (n - s - 1) * (n - s - 2) / (1.0 * n * (n - 1) * (n - 2));
		
		r += x[e.index] * e.l;
		
		sz[u] += s;
	}
	
	return r;
}

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n - 1; i++){
		scanf("%d %d %d", &ai, &bi, &l[i]);
		ai--, bi--;
		
		g[ai].push_back(edge(bi, l[i], i));
		g[bi].push_back(edge(ai, l[i], i));
	}
	
	double r = dfs(0);
	
	scanf("%d", &q);
	while(q--){
		scanf("%d %d", &rj, &wj);
		rj--;
		
		r += x[rj] * (wj - l[rj]);
		l[rj] = wj;
		
		printf("%.10f\n", r);
	}
	
	return 0;
}