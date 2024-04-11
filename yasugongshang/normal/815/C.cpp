#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9 + 7;
int d[5001][5001][2];
int a[5001];
int b[5001];
vector <int> g[5001];
int pr[5001];
int sub[5001];
int n, s;

void dfs (int v) {
	sub[v] = 1;
	for (auto to : g[v]) {
		dfs (to);
		sub[v] += sub[to];	
	}                
	d[v][0][0] = 0; 
	d[v][1][0] = a[v];
	d[v][1][1] = a[v] - b[v];
	for (auto to : g[v]) {            			
		for (int j = sub[v] - 1;j >= 0;j --) {
			if (min (d[v][j][0], d[v][j][1]) == inf) continue;
			for (int k = 1;k <= sub[to] && j + k <= sub[v];k ++) {
				d[v][j + k][0] = min (d[v][j + k][0], d[v][j][0] + d[to][k][0]);
				d[v][j + k][1] = min (d[v][j + k][1], d[v][j][1] + min (d[to][k][1], d[to][k][0]));
			}
		}
	}
}

 main () {
 	ios_base::sync_with_stdio (0);
 	cin.tie (0), cout.tie (0);
    cin >> n >> s;
    for (int i = 1;i <= n;i ++) {
    	cin >> a[i] >> b[i];
    	if (i > 1) cin >> pr[i];
    	g[pr[i]].push_back (i);
	}
	for (int i = 0;i <= n;i ++) {
		for (int j = 0;j <= n;j ++) {
			d[i][j][0] = inf;
			d[i][j][1] = inf;     	
		}
	}
	dfs (1);                   
	for (int i = n;i >= 0;i --) {
		if (min (d[1][i][1], d[1][i][0]) <= s) {
			cout << i;
			break;
		}
	}
	return 0;
}