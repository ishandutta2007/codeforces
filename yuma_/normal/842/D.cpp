#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
const int T=19;
int solve(int x, set<int>&nums) {
	int ans=0;
	int now=0;
	for (int i = T; i >= 0; --i) {
		if(x&(1<<i))now^=(1<<i);
		auto l=nums.lower_bound(now);
		auto r=nums.lower_bound(now+(1<<i));
		if (l == r) {
			ans+=(1<<i);
			now^=(1<<i);
		}
	}
	return ans;
}

int main() {	
	int N,Q;cin>>N>>Q;
	set<int>nums;
	vector<int>used(1e6);
	for (int i = 0; i < N; ++i) {
		int a;cin>>a;
		used[a]=true;
	}
	for (int i = 0; i < (1 << T); ++i) {
		if(!used[i])nums.emplace(i);
	}
	int num=0;
	while (Q--) {
		int a;cin>>a;
		num^=a;
		cout<<solve(num,nums)<<endl;
	}
	return 0;
}