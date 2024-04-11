#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 14, M = 7; 
int a[N][N], vis[N], n, m, u[N], v[N], K;

ll pw[N], fac[N], ans;
map < ll, int > cnted;
int f[1 << M][M]; 
bool chk() {
	
//	cerr << "chk " << endl; 
//	for(int i = 0; i < m; i++) {
//		cerr << u[i] << ' ' << v[i] << endl; 	
//	}
	memset(f, 0, sizeof(f)); 
	for(int i = 0; i < m; i++) f[1 << i][i] = 1; 
	for(int st = 1; st < 1 << m; st++) {
		for(int i = 0; i < m; i++) if(f[st][i]) {
			for(int j = 0; j < m; j++) if(i != j && !(st >> j & 1)) {
				if(a[u[i]][u[j]] && a[v[i]][v[j]] || a[u[i]][v[j]] && a[v[i]][u[j]]) 
					f[st | (1 << j)][j] = 1;
			}
		}
	}
	
	for(int i = 0; i < m; i++) { 
		if(f[(1 << m) - 1][i] && a[u[i]][v[i]]) return 1; 
	}
	return 0;
}
void dfs2(int s, int cnt, ll st) {
	if(s == n / 2) {
		if(!cnted[st]) {
			cnted[st] = 1; 
			if(K >= cnt) ans += fac[K] / fac[K - cnt];
//			cerr << st << ' ' << cnt << endl; 
		}
		return;
	}
	for(int i = 0; i < cnt; i++) dfs2(s + 1, cnt, st + (pw[u[s]] + pw[v[s]]) * i);
	dfs2(s + 1, cnt + 1, st + (pw[u[s]] + pw[v[s]]) * cnt);
}
void dfs1(int s) {
	if(s == n / 2) {
		if(!chk()) return; 
//		cerr << "?" << endl; 
		dfs2(0, 0, 0); 
		return ; 	
	}
	int x = s + 1; while(vis[x]) x++; 
	for(int i = 1; i <= n; i++) {
		if(x != i && !vis[i]) {
			vis[i] = vis[x] = 1; 
			u[s] = i, v[s] = x;  
			dfs1(s + 1); 
			vis[i] = vis[x] = 0; 
		}
	}
}
int main() {
	scanf("%d %d %d", &n, &m, &K);
	pw[0] = fac[0] = 1; 
	for(int i = 1; i <= max(n, K); i++) pw[i] = pw[i - 1] * 6ll, fac[i] = fac[i - 1] * i; 
	for(int i = 1; i <= m; i++) {
		int u, v; scanf("%d %d", &u, &v);
		a[u][v] = a[v][u] = 1; 	
	} m = n / 2;
	dfs1(0), cout << ans << endl;  
	return 0;	
}