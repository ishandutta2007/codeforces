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
	vector<int> p(n);
	for (int i=1;i<n;++i) scanf("%d", &p[i]);
	for (int &i: p) --i;
	vector<vector<int> > g(n);
	for (int i=1;i<n;++i) g[p[i]].push_back(i);
	vector<pair<int, int> > lr(n);
	for (int i=0;i<n;++i) scanf("%d%d", &lr[i].first, &lr[i].second);
	const int INF = 1000000000;
	int ans = 0;
	function<void(int)> dfs = [&](int v) {
		long long r1 = 0;
		for (int u: g[v]) {
			dfs(u);
			r1 += lr[u].second;
		}
		if (lr[v].first > r1) {
			ans++;
		}
		else if (r1 < lr[v].second) {
			lr[v].second = r1;
		}
	};

	dfs(0);
	cout << ans << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}