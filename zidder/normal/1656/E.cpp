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
	for (int i=1;i<n;++i){
		int u, v;
		scanf("%d%d", &u, &v);
		u--;
		v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	vector<bool> left(n);

	function<void(int, int, bool)> dfs = [&](int v, int p, bool is_left){
		left[v] = is_left;
		for (int u: g[v]) {
			if (u == p) continue;
			dfs(u, v, !is_left);
		}
	};

	dfs(0, -1, true);
	for (int i=0;i<n;++i){
		int d = g[i].size();
		if (left[i]) d *= -1;
		printf("%d ", d);
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