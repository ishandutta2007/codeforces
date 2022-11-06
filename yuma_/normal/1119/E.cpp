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
	ll answer=0;
	ll num=0;
	for (int i = 0; i < N; ++i) {
		ll use=min(num,v[i]/2);
		answer+=use;
		v[i]-=use*2;
		num-=use;
		answer+=v[i]/3;
		v[i]-=v[i]/3*3;
		num+=v[i];
	}
	cout<<answer<<endl;
	return 0;
}