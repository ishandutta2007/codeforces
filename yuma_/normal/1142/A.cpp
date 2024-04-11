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
using ll=long long ;
ll gcd(ll a, ll b) {
	if(a>b)return gcd(b,a);
	else {
		if(b%a)return gcd(b%a,a);
		else {
			return a;
		}
	}
}
int main() {
//\ncin>>N;
	ll N,K;cin>>N>>K;
	ll a,b;cin>>a>>b;

	pair<ll,ll>answer(1e15,0);
	for (int x = 0; x < 2; ++x) {
		ll s=x?a:K-a;
		for (ll y = 0; y < N; ++y) {
			for (int z = 0; z < 2; ++z) {
				ll t=y*K+(z?b:K-b);

				ll len=abs(s-t);
				ll atime=-1;
				if(len==0)atime=1;
				else {
					atime=N*K/gcd(N*K,len);
				}
				answer.first=min(answer.first,atime);
				answer.second=max(answer.second,atime);
			}
		}
	}
	cout<<answer.first<<" "<<answer.second<<endl;
	return 0;
}