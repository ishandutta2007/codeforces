#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <functional>

using namespace std;

void solve(int test_ind){
	int n;
	cin >> n;
	vector<int> c(n);
	for (int i=0;i<n;++i) scanf("%d", &c[i]);
	vector<vector<int> > g(n);
	for (int i=1;i<n;++i){
		int u, v;
		scanf("%d%d", &u, &v);
		u--;v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	vector<int> ans(n, 1);

	int ind;
	for (int i=0;i<n;++i){
		if (c[i]) ind = i;
	}

	bool found = false;

	function<void(int, int)> dfs2 = [&](int v, int p){
		ans[v] = 1;
		for (int u: g[v]){
			if (u == p) continue;
			dfs2(u, v);
		}
	};

	vector<int> deg(n, 0);

	function<void(int, int, int)> dfs = [&](int v, int p, int cnt) -> void{
		cnt += c[v];
		if (c[v] == 0){
			ans[v] = 0;
		}
		if (cnt == 2){
			found = true;
			return;
		}
		deg[v] += c[v];
		int c1 = 0;
		for (int u: g[v]){
			if (c[u]) {
				c1++;
			}
			if (u == p) continue;
			dfs(u, v, cnt);
			deg[v] += deg[u];
			if (found) return;
		}
		if (ind == v){
			for (int u: g[v]){
				if(deg[v] != deg[u] + 1)
					dfs2(u, v);
			}
		}

		if (c1 > 1) found = true;
		else if (c1){
			if (p != ind){
				if (deg[v] > 1) found = true;
				else {
					ans[v] = 1;
					for (int u: g[v]){
						if(u==p) continue;
						dfs2(u, v);
					}
				}
			} else {
				if (c[v]){
					found = true;
				}
				else if (deg[v]) {
					int c2 = 0;
					for (int u: g[v]){
						if (u == p) continue;
						if (deg[u]) c2++;
					}
					if (c2 > 1) found = true;
					else {
						ans[v] = 1;
						for (int u: g[v]){
							if(u==p) continue;
							if(deg[u] == 0) dfs2(u, v);
						}
					}
				}
			}
		}
	};

	dfs(ind, -1, -1);

	if (found){
		ans = vector<int>(n, 1);
	}

	for (int i: ans){
		cout << i << " ";
	}
	cout << endl;
}

int main(){
	int t=1;
	//cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}