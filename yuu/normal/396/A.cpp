#include <bits/stdc++.h>
using namespace std;
int n, a;
map <int, int> m;
using ll=long long;
ll f[50001];
ll r[50001];
const ll base=1000000007;
ll power(ll a, ll b){
	if(b==0) return 1;
	ll t=power(a, b/2);
	t=(t*t)%base;
	if(b%2) t=(t*a)%base;
	return t;
}
ll C(int n, int k){
	return ((f[n]*r[k])%base*r[n-k])%base;
}
ll candy(ll n, ll k){
	return C(n+k-1, k-1);
}
int main(){
	f[0]=1;
	for(int i=1; i<=50000; i++) f[i]=(f[i-1]*i)%base;
	r[50000]=power(f[50000], base-2);
	for(int i=50000; i>=1; i--) r[i-1]=(r[i]*i)%base;
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>a;
		for(int j=2; j*j<=a; j++){
			while(a%j==0){
				m[j]++;
				a/=j;
			}
		}
		if(a>1) m[a]++;
	}
	ll ans=1;
	for(auto x: m) ans=(ans*candy(x.second, n))%base;
	cout<<ans<<'\n';
}