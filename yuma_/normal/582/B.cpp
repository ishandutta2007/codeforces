#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
template<class T>
using Table = vector<vector<T>>;

int memo[100][100];

int main() {
	int N, T; cin >> N >> T;
	vector<int>nums;
	for (int i = 0; i < N; ++i) {
		int a; cin >> a;
		nums.push_back(a);
	}
	vector<int>times(301);
	for (auto n : nums) {
		times[n]++;
	}
	const int max_time = *max_element(times.begin(), times.end());
	vector<int>used = nums;
	sort(used.begin(), used.end());
	used.erase(unique(used.begin(), used.end()), used.end());
	map<int, int>compress;
	int now = 0;
	for (auto u : used) {
		compress[u] = now;
		now++;
	}
	for (int i = 0; i < nums.size(); ++i) {
		nums[i] = compress[nums[i]];
	}
	for (int i = 0; i < 100; ++i) {
		for (int j = 0; j < 100; ++j) {
			memo[i][j] = -1;
		}
	}
	for (int from = 0; from < now; ++from) {
		vector<int>dp(now, -100);
		dp[from] = 0;
		for (int i = 0; i < N; ++i) {
			vector<int>newdp(dp);
			for (int j = 0; j <= nums[i]; ++j) {
				newdp[nums[i]] = max(newdp[nums[i]], dp[j] + 1);
			}
			dp = newdp;
		}

		for (int to = from; to < now; ++to) {
			memo[from][to] = dp[to];
		}
	}

	vector<int>aa(now, int(-1e8));
	aa[0] = 0;
	for (int t = 0; t < min(N, T); ++t) {
		vector<int>newnums(now, int(-1e8));
		for (int i = 0; i < now; ++i) {
			for (int j = i; j < now; ++j) {
				newnums[j] = max(newnums[j], aa[i] + memo[i][j]);
			}
		}
		aa = newnums;
	}
	int ans = *max_element(aa.begin(), aa.end());
	ans += (T - min(T, N))*max_time;
	cout << ans << endl;
	

	return 0;
}