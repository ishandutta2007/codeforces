#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll base=1000000007;
ll x, n;
vector <ll> primes(ll x){
	vector <ll> ans;
	for(ll i=2; i*i<=x; i++){
		if(x%i==0){
			ans.push_back(i);
			while(x%i==0) x/=i;
		}
	}
	if(x>1) ans.push_back(x);
	return ans;
}
ll power(ll a, ll b){
	if(b==0) return 1;
	ll t=power(a, b/2);
	t=(t*t)%base;
	if(b%2) t=(t*a)%base;
	return t;
}
ll calc(ll a, ll n){
	ll p=a;
	ll q=a*a;
	ll ans=1;
	while(p<=n){
		ans=ans*power(p%base, (n/p-n/q)%(base-1))%base;
		if((double(q))*a>2e18){
			p=q;
			q=2e18;
		}
		else{
			p=q;
			q*=a;
		}
	}
	return ans;
}
int main(){
	cin>>x>>n;
	auto p=primes(x);
	ll ans=1;
	for(auto q: p) ans=(ans*calc(q, n))%base;
	cout<<ans<<'\n';
}