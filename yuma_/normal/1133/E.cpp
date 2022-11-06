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
		if(comes[e])continue;
		else {
			comes[e]=true;
			answers.emplace_back(now,e);
			dfs(e,edges,comes,answers);
		}
	}
}
const int SZ=5000;
int dp[SZ+1][SZ+1];
signed main() {
	for (int i = 0; i <= SZ; ++i) {
		for (int j = 0; j <= SZ; ++j) {
			dp[i][j]=-1e9;
		}
	}
	int N,M;cin>>N>>M;
	vector<int>as(N);
	for(int i=0;i<N;++i)cin>>as[i];
	sort(as.begin(),as.end());
	vector<int>nums(N);
	for (int i = 0; i < N; ++i) {
		nums[i]=1;
		for (int j = i+1; j < N; ++j) {
			if(as[j]<=as[i]+5)nums[i]++;
		}
	}
	dp[0][0]=0;
	for (int i = 0; i < N; ++i) {
		for (int x = 0; x <= M; ++x) {
			dp[i+1][x]=max(dp[i+1][x],dp[i][x]);
			dp[i+nums[i]][x+1]=max(dp[i+nums[i]][x+1],dp[i][x]+nums[i]);
		}
	}
	int answer=0;
	for (int x = 0; x <= M; ++x) {
		answer=max(answer,dp[N][x]);
	}
	cout<<answer<<endl;
	return 0;
}