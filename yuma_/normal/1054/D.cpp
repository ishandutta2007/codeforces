#include "bits/stdc++.h"

#pragma warning(disable:4996)
using namespace std;

int main() {
	long long int N,K;cin>>N>>K;
	map<int,long long int>mp;
	int sum=0;
	mp[0]=1;
	for (int i = 0; i < N; ++i) {
		int a;scanf("%d",&a);
		sum^=a;
		if ((sum&(1 << (K - 1))) != 0) {
			sum^=((1<<K)-1);
		}
		mp[sum]++;
	}
	long long int answer=N*(N+1)/2;
	for (auto m : mp) {
		long long int num=m.second;
		long long int al=num/2;
		long long int ar=(num+1)/2;
		answer-=(al)*(al-1)/2;
		answer-=(ar)*(ar-1)/2;
	}
	cout<<answer<<endl;
	return 0;
}