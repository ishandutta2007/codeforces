#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
#define uint unsigned int
using namespace std;
const int N = 5e5 + 7;
int n, m, xu[N], xv[N];
bool ok[N];
int f[N]; 
int find(int x) {
	return f[x] == x ? x : f[x] = find(f[x]);
}

int fa[N], dfn[N], en[N], idt, dep[N], tag[N], up[N][20];
vi e[N];
void dfs(int x) {
	dfn[x] = ++idt;
	for(const int &v : e[x]) if(v != fa[x]) 
		up[v][0] = x, dep[v] = dep[x] + 1, fa[v] = x, dfs(v);
	en[x] = idt;
}
int lca(int u, int v) {
	if(dep[u] < dep[v]) swap(u, v);
	int t = dep[u] - dep[v];
	R(i, 19, 0) if(t >> i & 1) u = up[u][i];
	if(u == v) return u;
	R(i, 19, 0) if(up[u][i] != up[v][i]) u = up[u][i], v = up[v][i];
	return up[u][0];
}
int UP(int u, int k) {
	R(i, 19, 0) if(k >> i & 1) u = up[u][i];
	return u;
}

void DFS(int x) {
	for(const int &v : e[x]) if(v != fa[x]) {
		tag[v] += tag[x], DFS(v); 
	}
}

void link(int u, int v) {
	if(dfn[u] > dfn[v]) swap(u, v);
//	cout << u << " and " << v << endl;
	if(dfn[u] <= dfn[v] && dfn[v] <= en[u]) {
		tag[UP(v, dep[v] - dep[u] - 1)] += 1;
		tag[v] -= 1;
	} else {
		tag[1] += 1;
		tag[u] -= 1;
		tag[v] -= 1;
	} 
}

int main () {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	L(i, 1, n) f[i] = i;
	L(i, 1, m) {
		cin >> xu[i] >> xv[i];
		int tu = find(xu[i]), tv = find(xv[i]);
		if(tu != tv) 
			f[tu] = tv, ok[i] = true, e[xu[i]].emplace_back(xv[i]), e[xv[i]].emplace_back(xu[i]);
	}
	dfs(1); 
	L(i, 1, 19) L(j, 1, n) up[j][i] = up[up[j][i - 1]][i - 1];
	
	L(i, 1, m) {
		if(!ok[i]) {
			link(xu[i], xv[i]);
		}
	}
	
	DFS(1);
	L(i, 1, n) 
		if(!tag[i]) 
			cout << 1;
		else 
			cout << 0;
	return 0;
}