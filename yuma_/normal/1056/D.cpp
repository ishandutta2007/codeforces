#include "bits/stdc++.h"

#pragma warning(disable:4996)
using namespace std;
using ld = long double;

int dfs(vector<int>&nums, const vector<vector<int>>&edges, int now, int from) {
	int ch_sum=0;
	for (auto e : edges[now]) {
		if (e != from) {
			ch_sum+=dfs(nums,edges,e,now);

		}
	}
	if(ch_sum==0)ch_sum=1;
	nums[ch_sum]++;
	return ch_sum;
}

int main() {
	int N;cin>>N;
	vector<vector<int>>edges(N);
	for (int i = 0; i < N - 1; ++i) {
		int a;scanf("%d",&a);
		a--;
		edges[i+1].push_back(a);
		edges[a].push_back(i+1);
	}
	vector<int>nums(N+1);
	dfs(nums,edges,0,-1);

	int sum=0;
	vector<int>anss(N);
	int k=0;
	for (int i = 0; i < N; ++i) {
		while (!nums[k]) {
			k++;
		}
		nums[k]--;
		anss[i]=k;
	}
	for (int i = 0; i < N; ++i) {
		printf("%d",anss[i]);
		if(i==N-1)cout<<endl;
		else printf(" ");
	}


	return 0;
}