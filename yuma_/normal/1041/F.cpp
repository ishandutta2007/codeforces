#include "bits/stdc++.h"

#pragma warning(disable:4996)
using namespace std;
using ld =long double;


int main() {
	int N,dummy;cin>>N>>dummy;
	vector<long long int>v;
	for (int i = 0; i < N; ++i) {
		int a;cin>>a;
		v.push_back(a);
	}
	int M;cin>>M>>dummy;
	vector<long long int>w;
	for (int i = 0; i < M; ++i) {
		int a;cin>>a;
		w.push_back(a);
	}

	int answer=0;
	for (long long int k = 1; k <= 1ll<<31; k *=2) {
		map<long long int,int>nums;
		for (auto x : v) {
			nums[x%(k*2)]++;
		}
		for (auto y : w) {
			nums[(y+k)%(k*2)]++;
		}
		for(auto m:nums){
			answer=max(answer,m.second);
		}
	}
	{
		map<long long int,int>nums;
		for (auto x : v) {
			nums[x]++;
		}
		for (auto y : w) {
			nums[y]++;
		}
		for (auto m : nums) {
			answer=max(answer,m.second);
		}
	}
	cout<<answer<<endl;
 	return 0;
}