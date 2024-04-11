#include "bits/stdc++.h"

#pragma warning(disable:4996)
using namespace std;
using ld = long double;


int main() {
	long long int N,M;cin>>N>>M;
	vector<long long int>nums(M);
	for (int i = 0; i < N%M; ++i) {
		nums[i]=1+N/M;
	}
	for (int i = N%M; i < M; ++i) {
		nums[i]=N/M;
	}
	long long int sum=0;
	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < M; ++j) {
			long long int k=(i+1)*(i+1)+(j+1)*(j+1);
			if (k%M == 0) {
				sum+=nums[i]*nums[j];
			}
		}
	}
	cout<<sum<<endl;
	return 0;
}