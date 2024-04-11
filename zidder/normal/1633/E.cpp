#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <functional>

using namespace std;

map<int, pair<pair<int, long long>, long long> > mp;

pair<pair<int, long long>, long long> calc(int x, vector<vector<pair<int, long long> > >& g1){
	if (mp.count(x)) return mp[x];
	auto g = g1;
	set<int> l;
	set<pair<long long, pair<long long, int> > > s;
	pair<pair<int, long long>, long long> ans = {{0, 0}, 0};
	auto add = [&](int v, long long e){
		if (e != -1){
			ans.first.first += (e <= x);
			ans.first.second += e;
			ans.second += abs(e - x);
		}
		// cout << "inserting: " << v << " " << e << endl;
		l.insert(v);
		for (auto p: g[v]){
			if (l.find(p.first) == l.end()){
				s.emplace(abs(p.second - x), make_pair(p.second, p.first));
				// cout << "emplace: " << p.second << " " << p.first << endl;
			} else {
				// cout << "erase: " << p.second << " " << p.first << endl;
				s.erase(make_pair(abs(p.second - x), make_pair(p.second, v)));
			}
		}
	};
	add(0, -1);
	while (!s.empty()){
		auto p = *s.begin();
		add(p.second.second, p.second.first);
	}
	return mp[x] = ans;
}


void solve(int test_ind){
	int n, m;
	cin >> n >> m;
	vector<vector<pair<int, long long> > > g(n);
	for (int i=0;i<m;++i){
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		u--;v--;
		g[u].emplace_back(v, w);
		g[v].emplace_back(u, w);
	}

	function<void(int, int)> precalc = [&](int l, int h){
		if (calc(l, g).first == calc(h, g).first) return;
		int m = (l + h) / 2;
		precalc(l, m);
		precalc(m + 1, h);
	};
	precalc(0, 1e8);

	int p, k, a, b, c;
	cin >> p >> k >> a >> b >> c;
	vector<int> q(p);
	for (int i=0;i<p;++i) scanf("%d", &q[i]);

	long long ans = 0;
	auto get_ans = [&](int qi) {
		auto it = mp.upper_bound(qi);
		--it;
		// cout << qi << endl;
		// cout << it->first << " " << it->second.first.first << " " << it->second.first.second << " " << it->second.second << endl;
		// cout << (it->second.second + (it->second.first.first * 2 - (n - 1)) * (qi - it->first)) << endl << endl;
		ans ^= (it->second.second + (it->second.first.first * 2 - (n - 1)) * (qi - it->first));
	};

	long long lq = 0;
	for (int i=0;i<k;++i){
		if (i < p){
			lq = q[i];
		} else {
			lq = (lq * a + b) % c;
		}
		get_ans(lq);
	}

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