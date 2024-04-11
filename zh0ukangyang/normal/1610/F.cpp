#include<bits/stdc++.h>
#define ll long long
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define vi vector < int > 
#define sz(a) ((int) a.size()) 
using namespace std;
const int N = 1e6 + 7;
int n, m;
int ehd[2][N], ev[N], enx[N], eid = 1;
void eadd (int u, int v, int w) {
	w -= 1;
	++eid, enx[eid] = ehd[w][u], ev[eid] = v, ehd[w][u] = eid; 
}
int road[N], tp;
bool vis[N], use[N];
void dfs (int x, int w) {
	use[x] = true;
	for (int &i = ehd[w][x], o; i; i = enx[i]) 
		if(!vis[i >> 1]) 
			o = i, vis[i >> 1] = true, dfs(ev[i], w), road[++tp] = o;
	for (int &i = ehd[w ^ 1][x], o; i; i = enx[i]) 
		if(!vis[i >> 1]) 
			o = i, vis[i >> 1] = true, dfs(ev[i], w ^ 1), road[++tp] = o;
}
int deg[N][3];
int su[N], sv[N], sw[N];
int op[N];
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	L(i, 1, m) {
		cin >> su[i] >> sv[i] >> sw[i];
		eadd (su[i], sv[i], sw[i]);
		eadd (sv[i], su[i], sw[i]);
		deg[su[i]][sw[i]] += 1;
		deg[sv[i]][sw[i]] += 1;
	}
	int all = 0;
	L(i, 1, n) if(deg[i][1] & 1) all += 1; 
	L(i, 1, n) if((deg[i][1] + deg[i][2]) & 1) eadd (0, i, 1), eadd (i, 0, 1);
	L(i, 0, n) if(!use[i]) dfs (i, 0);
	L(i, 1, tp) op[road[i] >> 1] = (road[i] & 1) + 1;
	cout << all << '\n';
	L(i, 1, m) cout << op[i];
	return 0;
}