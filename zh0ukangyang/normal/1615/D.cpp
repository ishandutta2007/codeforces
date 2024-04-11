#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 1e6 + 7, inf = 1e9;
int n, m, fa[N], r[N];
vector < pair < int, int > > e[N], re[N];
void merge (int x, int y, int o) {
//	cout << x << ' ' << y << ' ' << o << '\n';
	re[x].push_back({y, o});
	re[y].push_back({x, o}); 
}
void dfs (int x) {
	for (auto t : e[x]) {
		int v = t.first, w = t.second;
		if(fa[x] != v) {
			if(w != -1) {
				int bt = __builtin_popcount(w);
				merge (x, v, bt & 1);
			}
			fa[v] = x, dfs (v);
		}
	} 
}
void opt (int x) {
	for (auto t : e[x]) {
		int v = t.first, w = t.second;
		if(fa[x] != v) {
			if(w == -1) {
				cout << x << ' ' << v << ' ' << (r[x] ^ r[v]) << '\n';
			} else {
				cout << x << ' ' << v << ' ' << w << '\n';
			}
			fa[v] = x, opt(v);
		}
	} 
}
bool vis[N], ok ;
void co (int x) {
	vis[x] = true;
	for (auto t : re[x]) {
		int v = t.first, w = t.second;
		if(!vis[v]) {
			r[v] = r[x] ^ w, co (v);
		}
		else if(r[v] ^ r[x] ^ w) ok = false;
	}
}
void Main () {
	cin >> n >> m; 
	L(i, 1, n) fa[i] = -1, vis[i] = false;
	ok = true;
	L(i, 1, n - 1) {
		int u, v, w;
		cin >> u >> v >> w;
		e[u].push_back({v, w});
		e[v].push_back({u, w});
	}
	L(i, 1, m) {
		int u, v, p;
		cin >> u >> v >> p;
		merge (u, v, p);
	}
	dfs (1);
	L(i, 1, n) if(!vis[i]) r[i] = 0, co (i);
	if (ok) {
		cout << "YES\n";
		opt (1);
	}
	else {
		cout << "NO\n";
	}
	L(i, 1, n) e[i].clear (), re[i].clear ();
}
int main () {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while (T--) Main (); 
	return 0;
}