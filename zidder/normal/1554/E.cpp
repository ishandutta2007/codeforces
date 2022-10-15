#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <functional>
using namespace std;

const int MOD = 998244353;

void solve(int test_ind){
	int n;
	cin >> n;
	vector<vector<int> > g(n);
	for (int i=1;i<n;++i){
		int u, v;
		scanf("%d%d", &u, &v);
		u--;v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	vector<int> par(n, -1);

	function<void(int, int)> dfs = [&](int v, int p){
		par[v] = p;
		for (int u: g[v]) {
			if (u == p) continue;
			dfs(u, v);
		}
	};

	dfs(0, -1);

	vector<int> dpth(n);
	vector<int> c(n);
	vector<int> q;
	for (int i=0;i<n;++i) c[i] = g[i].size() - (par[i] != -1);
	for (int i=0;i<n;++i) if (c[i] == 0) {q.push_back(i); dpth[i] = 0;}

	int qind = 0;
	vector<vector<int> > d(n);
	while (qind < q.size()){
		int v = q[qind++];
		d[dpth[v]].push_back(v);
		if (par[v] == -1) continue;
		if ((--c[par[v]]) == 0){
			q.push_back(par[v]);
			dpth[par[v]] = dpth[v] + 1;
		}
	}
	if (q.size() != n) throw "error";

	vector<int> ans(n+1);

	for (int i=2;i<=n;++i){
		if ((n-1)%i){
			ans[i] = 0;
			continue;
		}
		// i divides n-1
		for (int j=0;j<n;++j) c[j] = 0;
		bool ok = true;
		for (int j=0;j<n;++j) {
			for (int k: d[j]){
				if (c[k] % i == 0) {
					if (par[k] != -1) c[par[k]]++;
				} else {
					if (par[k] == -1) {
						ok = false;
						break;
					}
					c[k]++;
					if (c[k] % i) {
						ok = false;
						break;
					}
				}
			}
			if (!ok) break;
		}
		ans[i] = ok;
	}
	for (int i=2;i<=n;++i){
		if (ans[i] == 0) continue;
		for (int j=2;j<=n/i;++j){
			if (ans[j * i]) {ans[i] = 0; break;}
		}
	}

	int total = 1;
	for (int i=1;i<n;++i) total = (total * 2ll) % MOD;
	ans[1] = total % MOD;
	for (int i=2;i<=n;++i){
		ans[1] = (ans[1] + MOD - ans[i]) % MOD;
	}
	for (int i=1;i<=n;++i){
		printf("%d ", ans[i]);
	}
	cout << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}