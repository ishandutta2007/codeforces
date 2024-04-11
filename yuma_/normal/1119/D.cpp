#include "bits/stdc++.h"
#pragma GCC optimize("Ofast")
//for CodeForces
#pragma GCC target("avx,avx2")
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
const ld eps = 1e-9;

bool check(vector<int>v, long long int h) {
	for (int i = v.size() - 1; i >= 0; i -= 2) {
		h-=v[i];
	}
	return h>=0;
}
using ll=long long ;
int main() {
//\n
	int N;cin>>N;
	vector<ll>v(N);
	for(int i=0;i<N;++i)scanf("%lld",&v[i]);
	sort(v.begin(),v.end());
	vector<ll>difs(N+1);
	for (int i = 0; i < N - 1; ++i) {
		difs[i+1]=v[i+1]-v[i];
	}
	difs[N]=3e18;
	sort(difs.begin(),difs.end());

	vector<ll>sums(N+1);
	sums[0]=0;
	for (int i = 0; i < N; ++i) {
		sums[i+1]=sums[i]+(difs[i+1]-difs[i])*(N-i);
		//cout<<difs[i+1]<<endl;
		//cout<<sums[i+1]<<endl;
	}
	int Q;cin>>Q;
	while (Q--) {
		ll l,r;scanf("%lld %lld",&l,&r);
		auto it=prev(lower_bound(difs.begin(),difs.end(),r-l+1));
		int place=it-difs.begin();
		auto jt=sums.begin()+place;

		ll ans=*jt+((r-l+1)-*it)*ll(N-place);
		printf("%lld ",ans);
	}
	cout<<endl;

	return 0;
}