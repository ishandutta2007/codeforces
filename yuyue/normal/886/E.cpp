#include<bits/stdc++.h>
#define LL long long 
using namespace std;
int n,k; 
const int mod=1e9+7,M=1e6+10;
LL fast(LL x,LL p){
	LL ret=1;
	for (;p;p>>=1,x=x*x%mod) if (p&1) ret=ret*x%mod;
	return ret;
}
LL fac[M],inv[M],f[M],s[M]; 
int main(){
	cin>>n>>k; fac[0]=1; 
	for (int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
	inv[n]=fast(fac[n],mod-2);
	for (int i=n;i>=1;i--) inv[i-1]=inv[i]*i%mod;
	f[0]=1; s[0]=1; 
	for (int i=1;i<=n;i++){
		int o=max(i-k,0);
		f[i]=fac[i-1]*(s[i-1]-(o ? s[o-1] : 0)+mod)%mod;
		s[i]=s[i-1]+f[i]*inv[i]; s[i]%=mod; 
//		cout<<f[i]<<" "<<i<<"   gg\n";
	}
	LL ans=0;
	for (int i=1;i<=n;i++){
		ans=(ans+f[i-1]*fac[n-1]%mod*inv[i-1])%mod;
	}
	cout<<(fac[n]-ans+mod)%mod<<"\n"; 
	return 0;
}