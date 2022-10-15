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
	vector<pair<int, int> > edges;
	for (int i=1;i<n;++i){
		int u, v;
		scanf("%d%d", &u, &v);
		u--;v--;
		edges.emplace_back(min(u, v), max(u, v));
	}

	vector<int> cnt(n);
	for (int i=0;i<n-1;++i){
		cnt[edges[i].first]++;
		cnt[edges[i].second]++;
	}
	for (int i=0;i<n;++i){
		if (cnt[i] > 2){
			cout << -1 << endl;
			return;
		}
	}
	map<pair<int, int>, int> mp;
	vector<vector<int> > g(n);
	for (int i=0;i<n-1;++i){
		g[edges[i].first].push_back(edges[i].second);
		g[edges[i].second].push_back(edges[i].first);
	}

	function<void(int, int, bool)> dfs = [&](int v, int p, bool odd=false){
		for (int u: g[v]){
			if (u == p) continue;
			mp[{min(v, u), max(v, u)}] = odd?11:2;
			dfs(u, v, !odd);
		}
	};

	for (int i=0;i<n;++i){
		if (cnt[i] == 1) {
			dfs(i, -1, false);
			break;
		}
	}

	for (pair<int, int> &p: edges){
		printf("%d ", mp[p]);
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