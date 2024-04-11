#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;

long long int gcd(long long int l, long long int r) {
	assert(l > 0 && r > 0);
	if (l > r)return gcd(r, l);
	else {
		const long long int num = r%l;
		if (num) {
			return gcd(l, num);
		}
		else {
			return l;
		}
	}
}
void solve(const int now, const int from, const vector<vector<int>>&edges, 
	const vector<int>&nums, vector<long long int>&anss,vector<long long int>kouhos,long long int n_num
) {
	if (from == -1) {
		anss[now]=nums[now];
		kouhos = vector<long long int>{ nums[now] };
		n_num=nums[now];
	}
	else {
		vector<long long int>nextkouhos;
		for (auto kouho : kouhos) {
			nextkouhos.emplace_back(gcd(kouho,nums[now]));
		}
		nextkouhos.emplace_back(n_num);
		if (from == 0) {
			nextkouhos.push_back(nums[now]);
		}
		sort(nextkouhos.begin(),nextkouhos.end());
		nextkouhos.erase(unique(nextkouhos.begin(),nextkouhos.end()),nextkouhos.end());
		
		n_num=gcd(n_num,nums[now]);
		kouhos=nextkouhos;
		anss[now]=kouhos.back();
	}
	for (auto e : edges[now]) {
		if(e==from)continue;
		else {
			solve(e,now,edges,nums,anss,kouhos,n_num);
		}
	}
}

int main() {	
	int N;cin>>N;
	vector<int>nums(N);
	vector<vector<int>>edges(N);
	for(int i=0;i<N;++i)cin>>nums[i];
	for (int i = 0; i < N - 1; ++i) {
		int a,b;cin>>a>>b;
		a--;b--;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	vector<long long int>anss(N);
	vector<long long int>kouhos{};
	solve(0,-1,edges,nums,anss,kouhos,1);
	for (int i = 0; i < anss.size(); ++i) {
		cout<<anss[i];
		if(i==anss.size()-1)cout<<endl;
		else cout<<" ";
	}
	return 0;
}