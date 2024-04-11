#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_set>
#include <set>

using namespace std;

void solve(int test_ind){
	int n, m;
	cin >> n >> m;
	vector<vector<pair<int, int> > > mp(n+1);
	auto f = [&](int a, int b){
		int c = 0;
		while (a % b == 0)
			{a/= b;c++;}
		return c;
	};
	vector<int> g(n + 1);
	for (int i=2;i<=n;++i){
		if (mp[i].size() == 0){
			g[i] = 1;
			for (int j=2;i*j<=n;++j){
				mp[i*j].emplace_back(i, f(i*j, i));
			}
		} else {
			g[i] = 0;
			for (auto &p: mp[i]){
				g[i] = __gcd(p.second, g[i]);
			}
		}
	}
	// return;
	long long c = 1, cnt = 0;
	vector<int> cache(22);
	auto get_ans = [&](int gi){
		// a ** g[i] = i
		if (cache[gi] != 0) return cache[gi];
		vector<bool> exclude(m+1, true);
		for (int j=1;j<gi;++j){
			int g1 = __gcd(gi, j);
			int g2 = gi / g1;
			for (int k=g2;k<=m;k+=g2){
				exclude[k * j / gi] = false;
			}
		}
		int c1 = 0;
		for (int j=1;j<=m;++j) c1+= exclude[j];
		return cache[gi] = c1;
	};
	for (int i=2;i<=n;++i){
		c += get_ans(g[i]);
	}
	cout << c << endl;
}

int main(){
	int t=1;
	//cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}