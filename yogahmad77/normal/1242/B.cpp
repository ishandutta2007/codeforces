#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define reset(a,b) memset(a,b,sizeof a);
#define ALL(x) x.begin(),x.end()
 
template <typename T>
void cetak(T t){cout << t << ')' << endl;}
template <typename T, typename... V>
void cetak(T t, V... v) {cout << t; if (sizeof...(v)) cerr << ", "; cetak(v...);}
 
#define debug(x...) cout<< '(' << #x << ") = ("; cetak(x) 
#define sz(x) (int)(x.size())
#define lt(x) (int)(x.length())

const int MOD = 1e9 + 7;
const int mx = 1e5 + 10;

int n, m, u, v, sudah[mx];
vector<int> g[mx], G[mx], tambah[mx];
vector<int> isi;
void dfs(int now){
	if(sudah[now]) return;
	isi.pb(now);
	sudah[now] = 1;
	for(int i : G[now]) dfs(i);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	srand(time(NULL));
	cin >> n >> m;
	for(int i = 1; i <= m; i++){
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}
	vector<int> ve(n);
	iota(ALL(ve), 1);
	for(int i = 1; i <= n; i++) sort(ALL(g[i]));
	random_shuffle(ALL(ve));
	int idx = 0;
	for(int i : ve){
		if(sudah[i]) continue;
		sudah[i] = 1;
		for(int j = 1; j <= n; j++){
			if(i == j) continue;
			int in = lower_bound(ALL(g[i]), j) - g[i].begin();
			if(in == sz(g[i]) || g[i][in] != j){
				G[i].pb(j);
				G[j].pb(i);
				sudah[j] = 1;
			}
		}
	}
	int jaw = 0;
	reset(sudah, 0);
	for(int i = 1; i <= n; i++){
		if(!sudah[i]){
			isi.clear();
			dfs(i);
			jaw += 1;
			if(1LL * sz(isi) * n <= 10000000){
				for(int i : isi){
					for(int j = 1; j <= n; j++){
						if(i == j) continue;
						int in = lower_bound(ALL(g[i]), j) - g[i].begin();
						if(in == sz(g[i]) || g[i][in] != j){
							tambah[i].pb(j);
							tambah[j].pb(i);
						}
					}
				}
			}
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j : tambah[i]){
			G[i].pb(j);
		}
	}
	reset(sudah, 0);
	jaw = 0;
	for(int i = 1; i <= n; i++){
		if(!sudah[i]){
			isi.clear();
			dfs(i);
			jaw += 1;
		}
	}
	cout << jaw - 1 << endl;
}