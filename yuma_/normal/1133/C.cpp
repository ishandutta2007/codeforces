#include "bits/stdc++.h"
#pragma GCC optimize("Ofast")

#pragma GCC target("avx,avx2")
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;




struct UnionFind {
	vector<int> data;
	UnionFind(int size) : data(size, -1) { }
	bool unionSet(int x, int y) {
		x = root(x); y = root(y);
		if (x != y) {
			if (data[y] < data[x]) swap(x, y);
			data[x] += data[y]; data[y] = x;
		}
		return x != y;
	}
	int root(int x) {
		return data[x] < 0 ? x : data[x] = root(data[x]);
	}
	int size(int x) {
		return -data[root(x)];
	}
};

void dfs(int now, const vector<vector<int>>&edges, vector<int>&comes, vector<pair<int, int>>&answers) {

	for (auto e : edges[now]) {
		if (comes[e])continue;
		else {
			comes[e] = true;
			answers.emplace_back(now, e);
			dfs(e, edges, comes, answers);
		}
	}
}
const int SZ = 5000;
int dp[SZ + 1][SZ + 1];
signed main() {
	for (int i = 0; i <= SZ; ++i) {
		for (int j = 0; j <= SZ; ++j) {
			dp[i][j] = -1e9;
		}
	}
	int N; cin >> N;
	vector<int>as(N);
	for (int i = 0; i<N; ++i)cin >> as[i];
	sort(as.begin(), as.end());
	vector<int>nums(N);
	for (int i = 0; i < N; ++i) {
		auto it=upper_bound(as.begin(),as.end(),as[i]+5);
		nums[i]=(it-as.begin())-i;
	}
	as = nums;
	cout << *max_element(as.begin(), as.end()) << endl;
	return 0;
}