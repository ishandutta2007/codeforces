#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int n;
ll a, b;
ll p;
ll rp;
ll pp[2001];
ll prp[2001];
const ll base=998244353;
ll power(ll a, ll b){
	if(b==0) return 1;
	ll t=power(a, b/2);
	t=(t*t)%base;
	if(b%2) t=(t*a)%base;
	return t;
}
ll f[2001][2001];
ll sc[2001];
ll e[2001][2];
int main(){
	cin>>n>>a>>b;
	p=(a*power(b, base-2))%base;
	rp=(base+1-p)%base;///greater win less 
	pp[0]=1;
	for(int i=1; i<=n; i++) pp[i]=(pp[i-1]*p)%base;
	prp[0]=1;
	for(int i=1; i<=n; i++) prp[i]=(prp[i-1]*rp)%base;
	f[0][0]=1;
	for(int i=0; i<n; i++){
		for(int j=0; j<=i; j++){
			f[i+1][j]=(f[i+1][j]+f[i][j]*pp[j])%base;
			f[i+1][j+1]=(f[i+1][j+1]+f[i][j]*prp[i-j])%base;
		}
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<i; j++){
			f[i][j]=(f[i][j]*f[j][j])%base;
			f[i][i]=(f[i][i]+base-f[i][j])%base;
		}
	}
	for(int i=2; i<=n; i++){
		{
			ll m=(base+1-f[i][i])%base;
			ll v=i*(i-1)/2;
			for(int j=1; j<i; j++) v+=(f[i][j]*(e[j][0]+e[i-j][1]))%base;
			v%=base;
			e[i][0]=(v*power(m, base-2))%base;
		}
		{
			ll m=1%base;
			ll v=0;
			for(int j=1; j<=i; j++) v+=(f[i][j]*(e[j][0]+e[i-j][1]))%base;
			v%=base;
			e[i][1]=(v*power(m, base-2))%base;
		}
	}
	cout<<e[n][0]<<'\n';
}