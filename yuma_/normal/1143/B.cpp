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
	string st;cin>>st;
	ll ans=0;
	ll sum=1;
	for (int i = 0; i < st.size(); ++i) {
		int n=st[i]-'0';
		if(n==0)break;
		else {
			ll nans=sum*(n-1);
			if(i==0&&n==1)nans=1;
			for(int j=i+1;j<st.size();++j)nans*=9;
			ans=max(ans,nans);
			sum*=n;
		}
	}
	ans=max(ans,sum);
	cout<<ans<<endl;
	return 0;
}