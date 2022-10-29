#include<bits/stdc++.h>
#include<tr1/unordered_map>
using namespace std;
typedef long long ll;
typedef long double ldb;
int T;
ll ai,bi,s,w,p,tp;
inline ll mul(ll a,ll b,ll c){
	a%=c,b%=c;
	ll t=a*b-(ll)((ldb)a*b/c+0.5)*c;
	if(t<0)return t+c;
	return t;
}
ll qpow(ll a,ll b,ll mod){
	ll ans=1;
	for(;b;b>>=1,a=mul(a,a,mod))
		if(b&1)ans=mul(ans,a,mod);
	return ans;
} 
ll phi(ll x){
	if(x==1)return x;
	return x/5*4;
}
int main(){
	scanf("%d",&T);
	while(T--){
//		ai=1999999999ll;
		scanf("%lld",&ai),
		tp=0,bi=ai,s=1,w=1,p=1;
		if(ai%10==0)bi=ai=ai*10+8;
		while(bi)bi/=10,s<<=1,p*=10;
		while((s-ai*w%s)%s>=w)s<<=1,w*=(s<<1)>w?10:1;
		ai=ai*w+(s-ai*w%s)%s,p*=w;
		ll d=__gcd(p,ai),xd=0;
		p/=d,ai/=d;
		while(d>1)d>>=1,xd++;
		ll z=0;
		for(ll mod=5;mod<=p;mod*=5)
			for(int j=0;j<=4;++j)if(qpow(2,z+j*phi(mod/5),mod)==ai%mod){
				z+=j*phi(mod/5);
				break;
			}
		printf("%lld\n",z+xd);
	}
}