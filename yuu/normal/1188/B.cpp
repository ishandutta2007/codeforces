#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll n, p, k;
map <ll, ll> m;
int main(){
	cin>>n>>p>>k;
	for(ll i=1, a; i<=n; i++){
		cin>>a;
		ll a2=(a*a)%p;
		ll a4=(a2*a2)%p;
		a4-=a*k;
		a4%=p;
		if(a4<0) a4+=p;
		m[a4]++;
	}
	ll ans=0;
	for(auto &x: m) ans+=x.second*(x.second-1)/2;
	cout<<ans<<'\n';
}