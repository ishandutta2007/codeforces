#include "bits/stdc++.h"

#pragma warning(disable:4996)
using namespace std;


map<long long int, int>soinnsuu(long long int a) {
	map<long long int, int>ans;
	for(long long int i=2;i*i<=a;++i){
		if (i> a)break;
		while (a%i == 0) {
			ans[i]++;
			a /= i;
		}
	}
	if (a != 1)ans[a]++;
	return ans;
}


int main() {
	long long int N,A;cin>>N>>A;
	auto mp=soinnsuu(A);

	long long int answer=1e18;
	for (auto m : mp) {
		long long int div=m.first;
		long long int cnt=m.second;

		long long int rest=N;
		long long int sum=0;
		while (rest) {
			rest=rest/div;
			sum+=rest;
		}
		answer=min(answer,sum/cnt);
	}
	cout<<answer<<endl;
	return 0;
}