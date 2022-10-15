#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <functional>
#include <set>
#include <numeric>
#include <unordered_set>
#include <cassert>

using namespace std;

// t1 t2 .. t26
// c1 c2 .. c26
// f1 f2 .. f26

// cost = f1 * min(c1/f1, t1) + min(c2, t2*f2) + ... + min(c26, t26*f26)

const int MAX = 1000000001;

struct Node {
	long long total_length[26];
	long long count[26]; // number of times you pay should fine in i-th zone
	long long mcount[26]; // number of times you pay should fine in i-th zone
	unordered_set<int> counts_incomparable;
	Node(){
		for (int i=0;i<26;++i) count[i] = 0;
		for (int i=0;i<26;++i) mcount[i] = 0;
		for (int i=0;i<26;++i) total_length[i] = 0;
	}

	void calculate_counts(long long T){
		long long rm = 0, msk = 0;
		for (int i=25;i>=0;--i){
			if (rm >= total_length[i]){
				count[i] = 0;
				mcount[i] = total_length[i] > 0;
			} else {	
				count[i] = 1 + (total_length[i] - rm - 1) / T;// 1 at rm and (total_length-rm) / T at each rm
				mcount[i] = 1 + (total_length[i] - 1) / T;
			}
			count[i] = min(count[i], MAX + 0ll);
			mcount[i] = min(mcount[i], MAX + 0ll);
			rm = (rm + T - total_length[i]%T) % T;
			if (mcount[i] > count[i]) msk |= (1 << i);
		}
		counts_incomparable.insert(msk);
	}

	long long min_fun(int mz);
};

vector<Node> nodes;


long long cost[26], fine[26];

long long Node::min_fun(int mz){
	auto f = [&](int i, long long cnt) -> long long {
		return min(cost[i], fine[i] * cnt);
	};
	long long ans = 0;
	for (int i=0;i<mz;++i){
		ans += f(i, mcount[i]);
	}
	long long prod[26];
	for (int msk: counts_incomparable){
		long long sm = 0;
		for (int j=0;j<mz;++j){
			sm += f(j, mcount[j] - !!((1<<j) & msk));
		}
		ans = min(ans, sm);
	}
	return ans;
}


void solve(int test_ind){
	for (int i=0;i<26;++i) cost[i] = 0;
	for (int i=0;i<26;++i) fine[i] = 0;

	int n;
	cin >> n;
	vector<vector<pair<int, long long> > > g(n);
	for (int i=1;i<n;++i){
		int u, v;
		long long t;
		scanf("%d%d%lld", &u, &v, &t);
		u--;v--;
		g[u].emplace_back(v, t);
		g[v].emplace_back(u, t);
	}

	int k;
	cin >> k;
	string z1;
	cin >> z1;

	vector<int> z(n);
	for (int i=0;i<n;++i) z[i] = z1[i] - 'A';

	for (int i=0;i<k;++i) scanf("%lld", &cost[i]);
	for (int i=0;i<k;++i) scanf("%lld", &fine[i]);

	long long T;
	scanf("%lld", &T);

	nodes = vector<Node>(n);

	function<void(int, int, long long)> dfs = [&](int v, int p, long long t) {
		if (p != -1){
			for (int i=0;i<=z[v];++i) nodes[v].total_length[i] = nodes[p].total_length[i];
		}
		nodes[v].total_length[z[v]] += t;
		nodes[v].calculate_counts(T);
		for (auto &e: g[v]){
			if (e.first == p) continue;
			dfs(e.first, v, e.second);
			if (z[v] == z[e.first]) {
				for(int msk: nodes[e.first].counts_incomparable) nodes[v].counts_incomparable.insert(msk);
			}
		}
		assert(nodes[v].counts_incomparable.size() < 27);
	};

	dfs(0, -1, 0ll);
	int q;
	cin >> q;
	for (int i=0;i<q;++i){
		int qi;
		scanf("%d ", &qi);
		if (qi == 3){
			int u;
			scanf("%d", &u);
			u--;
			printf("%lld\n", nodes[u].min_fun(z[u]));
		} else {
			char zone;
			int val;
			scanf("%c%d", &zone, &val);
			int ind = zone - 'A';
			if (qi == 2){
				fine[ind] = val;
			} else {
				cost[ind] = val;
			}
		}
	}
}

int main(){
	int t=1;
	//cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}