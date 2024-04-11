#include "bits/stdc++.h"
using namespace std;
#define f first
#define s second
#define pb push_back
#define reset(a,b) memset(a,b,sizeof a);
#define ALL(x) x.begin(),x.end()
 
template <typename T>
void cetak(T t){cout << t << ')' << endl;}
template <typename T, typename... V>
void cetak(T t, V... v) {cout << t; if (sizeof...(v)) cout << ", "; cetak(v...);}
 
#define debug(x...) cout << '(' << #x << ") = ("; cetak(x) 
#define sz(x) (int)(x.size())
#define lt(x) (int)(x.length())

const int MOD = 1e9 + 7;
const int mx = 2e5 + 10;
set<int> g[mx];
int sudah[mx], val[mx];
void dfs(int now, int X, int v){
	sudah[now] = 1;
	val[now] += v;
	for(int i : g[now]){
		if(sudah[i] || i == X) continue;
		dfs(i, X, v);
	}
}

void solve(){
	int n, m, a, b;
	cin >> n >> m >> a >> b;
	for(int i = 1; i <= n; i++) g[i].clear();
	for(int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		g[u].insert(v);
		g[v].insert(u);
	}
	for(int i = 1; i <= n; i++) val[i] = sudah[i] = 0;
	dfs(a, b, 1);
	for(int i = 1; i <= n; i++) sudah[i] = 0;
	dfs(b, a, 2);
	int satu = 0, dua = 0;
	for(int i = 1; i <= n; i++){
		if(i == a || i == b) continue;
		if(val[i] == 1) satu += 1;
		if(val[i] == 2) dua += 1;
		// debug(i, val[i]);
	}
	// debug(satu, dua);
	cout << 1LL * satu * dua << '\n';
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}