#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
ll n, s;
ll sum(ll s){
	ll res=0;
	while(s>0){
		res+=s%10;
		s/=10;
	}
	return res;
}
void solve(){
	cin>>n>>s;
	ll ans=0;
	ll diff=1;
	while(sum(n)>s){
		while(n%10==0){
			n/=10;
			diff*=10;
		}
		n++;
		ans+=diff;
	}
	cout<<ans<<'\n';
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int t;
	cin>>t;
	while(t--) solve();
}