#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10,mod=998244353;
int fac[maxn],inv[maxn];
int qpow(int a,int b){
	int ans=1;
	for(;b;b>>=1,a=1ll*a*a%mod)
		if(b&1)ans=1ll*ans*a%mod;
	return ans;
}
int main(){
	int n;
	scanf("%d",&n);
	int ans=0;
	fac[0]=inv[0]=1;
	for(int i=1;i<=n;++i)fac[i]=1ll*fac[i-1]*i%mod;
	inv[n]=qpow(fac[n],mod-2);
	for(int i=n-1;i>=1;--i)inv[i]=1ll*inv[i+1]*(i+1)%mod;
	for(int i=1;i<=n;++i){
		ans=(ans+1ll*fac[n]*inv[n-i]%mod*(fac[n-i]+mod-1))%mod;
	}
	ans=(ans+fac[n])%mod;
	printf("%d",ans);
}