#include <bits/stdc++.h>
using namespace std;
int n;
using ll=long long;
const ll base=1000000007;
ll power(ll a, ll b){
	if(b==0) return 1;
	ll t=power(a, b/2);
	(t*=t)%=base;
	if(b%2) (t*=a)%=base;
	return t;
}
ll f[2000003];
ll r[2000003];
ll p[2000003];
ll C(int n, int k){
	return ((f[n]*r[k])%base*r[n-k])%base;
}
int main(){
	cin>>n;
	p[0]=1;
	for(int i=1; i<=2000002; i++) p[i]=(p[i-1]*2)%base;
	f[0]=1;
	for(int i=1; i<=2000002; i++) f[i]=(f[i-1]*i)%base;
	r[2000002]=power(f[2000002], base-2);
	for(int i=2000002; i>=1; i--) r[i-1]=(r[i]*i)%base;
	ll ans=0;
	for(int i=0; i<=n; i++)	(ans+=p[i])%=base;
	long long lowsum=0;
	long long highsum=0;
	for(int i=0; i<=n; i++) (highsum+=C(n+1, i))%=base;
	for(int i=0; i<=0; i++) (lowsum+=C(n+1, i))%=base;
	for(int i=n+1; i<=n+n; i++){
		(ans+=highsum-lowsum)%=base;
		((highsum*=2)-=C(i, n))%=base;
		((lowsum*=2)+=C(i, i-n))%=base;
	}
	(ans+=base)%=base;
	cout<<ans<<'\n';
}