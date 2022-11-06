#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
const ld eps = 1e-9;


int main() {
	long long int N, M, K; cin >> N >> M >> K;
	long long int X, S; cin >> X >> S;
	vector<int>as(M), bs(M),cs(K),ds(K);
	vector<pair<long long int, long long int >>sp1(M), sp2(K+1);
	for (int i = 0; i < M; ++i) {
		cin >> sp1[i].second;
	}
	for (int i = 0; i < M; ++i) {
		cin >> sp1[i].first;
	}
	sp1.push_back(make_pair(0,X));
	sp2[0]=(make_pair(0, 0));
	for (int i = 0; i < K; ++i) {
		cin >> sp2[i+1].second;
	}
	for (int i = 0; i < K; ++i) {
		cin >> sp2[i+1].first;
	}
	long long int ans = 8e18;
	for (int i = 0; i <= M; ++i) {
		long long int nans = 0;
		long long int restp = S - sp1[i].first;
		if (restp < 0)continue;
		auto it = lower_bound(sp2.begin(), sp2.end(), make_pair(restp, static_cast<long long int>(3e18)));
		if (it != sp2.begin()) {
			nans = (N - prev(it)->second) * sp1[i].second;
			nans = max(0ll, nans);
			ans = min(ans, nans);
		}

		
	}
	cout << ans << endl;
	return 0;
}