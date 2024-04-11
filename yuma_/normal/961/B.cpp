#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;



int main() {
	int N,K;cin>>N>>K;
	vector<long long int>as(N);
	vector<int>wakes(N);
	for (int i = 0; i < N; ++i) {
		cin>>as[i];
	}
	for (int i = 0; i < N; ++i) {
		cin>>wakes[i];
	}

	long long int ans=0;
	for (int i = 0; i < N; ++i) {
		if (wakes[i]) {
			ans+=as[i];
			as[i]=0;
		}
	}
	vector<long long int>sums(N+1);
	for (int i = 0; i < N; ++i) {
		sums[i+1]=sums[i]+as[i];
	}

	long long int nplus=0;
	for (int i = 0; i <= N - K; ++i) {
		nplus = max(nplus,sums[i + K] - sums[i]);
		
	}

	cout<<ans+nplus<<endl;
	return 0;
}