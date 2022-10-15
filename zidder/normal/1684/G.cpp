#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <functional>

using namespace std;

void solve(int test_ind){
	// a <= m/3
	// 3a, 2a -> t.append(a) , a, 2a -> a 0
	// a >= m/2 => -1
	// m/2 > a > m/3
	// b, a+b where b > a, then b, a, b = a+x
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for (int &i: a) scanf("%d", &i);
	// a div x => a + x, 2a + x
	// x => 2x 3x for remaining

	vector<int> big;
	vector<int> small;
	for (int i: a){
		if (i * 3ll <= m) small.push_back(i);
		else big.push_back(i);
	}

	vector<set<int> > bigg(big.size());
	vector<set<int> > smallg(small.size());
	set<pair<int, int> > ans;
	int l = big.size();
	vector<bool> visited(small.size(), false);
	for (int i=0;i<big.size();++i) {
		for (int j=0;j<small.size();++j){
			if (big[i] * 2ll + small[j] <= m && big[i] % small[j] == 0) bigg[i].insert(j);
		}
	}

	vector<bool> vis(n);
	function<vector<int>(int)> dfs = [&](int v) -> vector<int> {
		if (vis[v]) return {};
		vis[v] = true;
		if (v >= l) {
			if (!visited[v-l]) {
				visited[v-l] = true;
				return {v-l};
			}
			// small v-l
			for (int b: smallg[v-l]){
				vector<int> res = dfs(b);
				if (res.empty()) continue;
				res.push_back(v-l);
				return res;
			}
		} else {
			// big
			for (int s: bigg[v]){
				vector<int> res = dfs(s + l);
				if (res.empty()) continue;
				res.push_back(v);
				return res;
			}
		}
		return {};
	};

	for (int i=0;i<l;++i) {
		auto v = dfs(i);
		if (v.empty()) {
			cout << -1 << endl;
			return;
		}
		for (int i=0;i<n;++i) vis[i] = false;
		reverse(v.begin(), v.end());
		// big small big small
		for (int i=2;i<v.size();i+=2){
			ans.erase(make_pair(v[i], v[i-1]));
			smallg[v[i-1]].erase(v[i]);
			bigg[v[i]].insert(v[i-1]);
		}
		for (int i=0;i<v.size();i+=2){
			ans.emplace(v[i], v[i+1]);
			smallg[v[i+1]].insert(v[i]);
			bigg[v[i]].erase(v[i+1]);
		}
	}

	// big -> small matching
	vector<pair<int, int> > res;
	for (auto &p: ans) {
		int b = big[p.first];
		int s = small[p.second];
		res.emplace_back(2 * b + s, b + s);
	}
	for (int i=0;i<small.size();++i){
		if (visited[i]) continue;
		res.emplace_back(3 * small[i], 2 * small[i]);
	}
	cout << res.size() << endl;
	for (auto &p: res) cout << p.first << " " << p.second << endl;
}

int main(){
	int t=1;
	//cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}