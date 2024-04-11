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
	vector<vector<int> > g(n);
	for (int i=1;i<n;++i) {
		int u, v;
		scanf("%d%d",&u ,&v);
		u--;v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	if (n == 1) {
		cout << 0 << endl;
		return;
	}
	function<int(int, int, int)> dfs = [&](int v, int p, int d) -> int{
		if (g[v].size() - (p != -1) < 2) {
			return d + g[v].size() - (p != -1);
		}
		int mn = n;
		for (int i: g[v]) if (i == p) continue; else {
			mn = min(dfs(i, v, d+2), mn);
		}
		return mn;
	};
	cout << n - dfs(0, -1, 1) << endl;;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}