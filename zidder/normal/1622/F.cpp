#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cstring>
#include <random>
#include <chrono>

using namespace std;

int prv[1000001];
long long vals[1000001];
mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<long long> dist(0, (1ll<<60));

long long rand_int() {
	return dist(gen);
}

void solve(int test_ind){
	// 2 * 5 * 7 * m^2 = 8!
	// 1 2 4 5 6 7 8
	fill(prv, prv + 1000001, -1);
	fill(vals, vals + 1000001, 0ll);
	auto eratosfen = [&](int n){
		for (int i = 2; i <= n; ++i)
			if (prv[i] == -1)
				for (long long j = i * 1ll * i; j <= n; j += i){
					prv[j] = i;
				}
	};

	int n;
	cin >> n;

	if (n < 4) {
		cout << "1" << endl << "1" << endl;
		return;
	}

	eratosfen(n);
	
	for (int i=2;i<=n;++i){
		if (prv[i] == -1){
			vals[i] = rand_int();
		} else {
			vals[i] = vals[prv[i]] ^ vals[i / prv[i]];
		}
	}

	for (int i=3;i<=n;++i){
		(vals[i] ^= vals[i-1]);
	}

	auto exclusions = [&](){
		vector<int> exclude;
		exclude.push_back(n/2);
		if (n%2){
			exclude.push_back(n);
		}
		if (n%4==2 || n%4==3){
			exclude.push_back(2);
		}

		long long v = 0;
		for (int e: exclude) v ^= vals[e];
		if (v == 0) return vector<int>{};
		map<long long, int> m;
		vector<int> two;
		for (int i=1;i<=n;++i){
			if (vals[i] == v){
				return vector<int>{i};
			}
			if (two.empty()){
				if (m.find(vals[i]) != m.end()){
					two = {i, m[vals[i]]};
				}
				m[vals[i]^v] = i;
			}
		}
		if (!two.empty()) return two;
		return exclude;
	};
	set<int> ans;
	for (int i=1;i<=n;++i) ans.insert(i);
	for (int e: exclusions()) ans.erase(e);

	cout << ans.size() << endl;
	for (int i: ans) cout << i << " ";
	cout << endl;
}

int main(){
	int t=1;
	//cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}