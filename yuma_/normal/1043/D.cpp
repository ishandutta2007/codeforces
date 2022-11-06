#include "bits/stdc++.h"
#pragma GCC optimize("Ofast")

#pragma GCC target("avx,avx2")
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ll=long long ;
#define Whats(x) //cout<<#x<<" is "<<(x)<<endl


int main() {
	int N,M;cin>>N>>M;
	vector<map<int,int>>nums(N);
	vector<int>f_v;
	for (int i = 0; i < M; ++i) {
		vector<int>v(N);
		for (int j = 0; j < N; ++j) {
			scanf("%d",&v[j]);
			v[j]--;
		}
		for (int j = 0; j < N - 1; ++j) {
			nums[v[j]][v[j+1]]++;
		}
		if(!i)f_v=v;
	}
	vector<int>tos(N,-1);
	for (int i = 0; i < N; ++i) {
		for (auto m : nums[i]) {
			if(m.second==M)tos[i]=m.first;
		}
	}
	ll answer=0;
	ll sum=0;
	for (auto x : f_v) {
		sum++;
		if (tos[x] != -1) {
		}
		else {
			answer+=sum*(sum+1)/2;
			sum=0;
		}
	}
	cout<<answer<<endl;
	return 0;
}