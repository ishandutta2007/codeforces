#include "bits/stdc++.h"

#pragma warning(disable:4996)
using namespace std;
using ld=long double;
using ll = long long int;


int main() {
	int N,M;cin>>N>>M;
	vector<int>vers;
	for (int i = 0; i < N; ++i) {
		int a;
		scanf("%d",&a);
		vers.push_back(a);
	}
	sort(vers.begin(),vers.end());
	vers.push_back(1e9);
	vector<int>nums(N+2);
	for (int i = 0; i < M; ++i) {
		int l,r,y;
		scanf("%d %d %d',",&l,&r,&y);
		if(l!=1)continue;
		else {
			auto rt=upper_bound(vers.begin(),vers.end(),r);
			nums[rt-vers.begin()]++;
		}
	}
	int sum=0;
	int ans=1e8;
	for (int k = N; k >= 0; --k) {
		sum+=nums[k+1];
		int nans=k+sum;
		ans=min(ans,nans);
	}
	cout<<ans<<endl;
	return 0;
}