// https://codeforces.com/problemset/problem/600/E

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <functional>
using namespace std;

void solve(int test_ind){
	int n;
	scanf("%d", &n);
	vector<int> c(n);
	for (int i=0;i<n;++i){
		scanf("%d", &c[i]);
	}

	vector<vector<int> > g(n);

	for (int i=1;i<n;++i){
		int u, v;
		scanf("%d%d", &u, &v);
		--u;
		--v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	vector<long long> ans(n);
	map<int, int> mp2;

	function<pair<long long, int>(int, int)> dfs = [&](int v, int p) -> pair<long long, int> {
		map<int, int> mp;
		long long a = 0;
		int cnt = 0;

		auto upd = [&](const int &k, const int &val){
			if (cnt == val) a += k;
			else if (cnt < val){
				cnt = val;
				a = k;
			}
		};

		for (int &u: g[v]){
			if (u == p) continue;
			auto &&res = dfs(u, v);
			if (mp2.size() > mp.size()) {
				swap(mp, mp2);
				swap(a, res.first);
				swap(cnt, res.second);
			}
			for (auto &p: mp2) {
				// cout << cnt << " " << a << endl;
				// cout << v << " " << p.first << " " << p.second << endl;
				upd(p.first, mp[p.first] += p.second);
			}
		}
		upd(c[v], ++mp[c[v]]);
		ans[v] = a;
		swap(mp, mp2);
		return make_pair(a, cnt);
	};

	dfs(0, -1);

	for (long long &x: ans) printf("%lld ", x);
	printf("\n");
}

int main(){
	int t=1;
	//cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}