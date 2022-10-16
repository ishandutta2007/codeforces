#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
vector <ll> get(ll a, ll b, ll x, ll y, ll n){
	vector <ll> pa;
	pa.push_back(x);
	pa.push_back(a);
	if(b-(n-a+b)/2>=x) pa.push_back(b-(n-a+b)/2);
	if(b-(n-a+b)/2-1>=x) pa.push_back(b-(n-a+b)/2-1);
	if(a-(n-b+a)/2>=x) pa.push_back(a-(n-b+a)/2);
	if(a-(n-b+a)/2-1>=x) pa.push_back(a-(n-b+a)/2-1);
	if(a-(n-b+y)>=x) pa.push_back(a-(n-b+y));
	if(a-n>=x) pa.push_back(a-n);
	return pa;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	ll t, a, b, x, y, n;
	cin>>t;
	while(t--){
		cin>>a>>b>>x>>y>>n;
		ll ans=1e18;
		auto pa=get(a, b, x, y, n);
		auto pb=get(b, a, y, x, n);
		for(auto f: pa) if(f<=a) for(auto g: pb) if(g<=b){
			if(a-f+b-g<=n) ans=min(ans, f*g);
		}
		cout<<ans<<'\n';
	}
}