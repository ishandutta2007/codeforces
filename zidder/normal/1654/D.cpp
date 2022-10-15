#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <functional>

using namespace std;

const int MOD = 998244353;

long long binpow(long long a, long long p){
	return p==0?1:binpow(a*a%MOD, p/2) * (p&1?a:1) % MOD;
}

long long bininv(long long a){
	return binpow(a, MOD-2);
}

const int N = 200005;
int prv[N];

void solve(int test_ind){
	int n;
	cin >> n;
	vector<vector<pair<int, pair<int, int> > > > g(n);
	for (int i=1;i<n;++i){
		int u, v, x, y;
		scanf("%d%d%d%d", &u, &v, &x, &y);
		u--;v--;
		g[u].emplace_back(v, make_pair(y, x));
		g[v].emplace_back(u, make_pair(x, y));
	}

	vector<int> val(n);

	map<int, long long> mp, minmp;

	auto addd = [&](int vl, int sign){
		while (vl > 1) {
			int p = prv[vl];
			mp[p] += sign;
			minmp[p] = min(minmp[p], mp[p]);
			vl /= p;
		}
	};

	function<void(int, int)> dfs = [&](int v, int p){
		for (auto &pr: g[v]){
			if (pr.first == p) continue;
			addd(pr.second.first, 1);
			addd(pr.second.second, -1);
			val[pr.first] = ((pr.second.first * bininv(pr.second.second) % MOD) * val[v]) % MOD;
			dfs(pr.first, v);
			addd(pr.second.second, 1);
			addd(pr.second.first, -1);
		}
	};


	val[0] = 1;
	dfs(0, -1);

	long long sm = 0;
	for (int i: val){
		sm = (sm + i) % MOD;
	}

	for (auto &p: minmp) {
		sm = (sm * binpow(p.first, (-p.second))) % MOD;
	}

	cout << sm % MOD << endl;
}

int main(){
	for (int i=0;i<N;++i) prv[i] = 0;
	for (long long i=2;i<N;++i){
		if (prv[i] == 0){
			for (long long j=i;j<N;j+=i){
				prv[j] = i;
			}
		}
	}

	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}