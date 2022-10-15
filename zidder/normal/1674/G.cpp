#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <functional>

using namespace std;

void solve(int test_ind){
	int n, m;
	cin >> n >> m;
	vector<set<int> > gin(n), gout(n);
	for (int i=0;i<m;++i){
		int u, v;
		scanf("%d%d", &u, &v);
		u--;v--;
		gout[u].insert(v);
		gin[v].insert(u);
	}
	set<int> out, inn;
	vector<pair<int, int> > q;
	for (int i=0;i<n;++i){
		out.insert(i);
		inn.insert(i);
		if (gin[i].size() == 1) {
			inn.erase(i);
			q.emplace_back(i, 1);
		}
		if (gout[i].size() == 1) {
			out.erase(i);
			q.emplace_back(i, 2);
		}
	}
	for (int i=0;i<q.size();++i){
		if (q[i].second == 1) {
			int u = q[i].first;
			if (gin[u].empty()) continue;
			int v = *gin[u].begin();
			// cout << v << " " << u << endl;
			gin[u].clear();
			gout[v].erase(u);
		} else {
			int u = q[i].first;
			if (gout[u].empty()) continue;
			int v = *gout[u].begin();
			// cout << u << " " << v << endl;
			gout[u].clear();
			gin[v].erase(u);
		}
	}

	vector<int> d(n, -1);

	function<void(int)> dfs = [&](int v) {
		if (d[v] != -1) return;
		d[v] = 1;
		for (int u: gout[v]) {
			dfs(u);
			d[v] = max(d[v], d[u]+1);
		}
	};

	for (int i=0;i<n;++i){
		dfs(i);
	}
	int ans = 0;
	for (int i: d) ans = max(ans, i);
	cout << ans << endl;
}

int main(){
	int t=1;
	//cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}