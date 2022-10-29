#include<bits/stdc++.h>
#define maxn 1001000
#define mod 998244353
using namespace std;
typedef long long ll;
int C[maxn],inv[maxn],pw3[maxn],n;
int qpow(ll a,ll b){
	int ans=1,tmp=a;
	for(;b;b>>=1,a=1ll*a*a%mod)
		if(b&1)ans=1ll*ans*a%mod;
	return ans;
}
int main(){
	scanf("%d",&n);
	pw3[0]=1;
	for(int i=1;i<=n;++i)pw3[i]=1ll*pw3[i-1]*3ll%mod;
	inv[1]=1;
	for(int i=2;i<=n;++i)inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
	for(int i=0,c=1;i<=n;++i)
		C[i]=c,c=1ll*(n-i)*inv[i+1]%mod*c%mod;
	int ans=0;
	int nw3=qpow(3,1ll*(n-1)*n+1);
	int f3=qpow(3,mod-1-(n-1));
	for(int i=1;i<=n;++i)
		ans=(ans+1ll*C[i]*nw3*(i&1?1:-1))%mod,nw3=1ll*nw3*f3%mod;
	ans=2ll*ans%mod;
	int sum=0;
//	printf("[%d]",ans);
	for(int i=1;i<=n;++i){
		int fac=0;
//		for(int j=1;j<=n;++j)
//			fac=(fac+1ll*(j&1?-1:1)*C[j]*qpow(pw3[n-i],n-j))%mod;
		fac=qpow(pw3[n-i]-1,n)-qpow(pw3[n-i],n);
		fac=1ll*fac*C[i]*(i&1?-1:1)%mod;
		sum=(sum-fac)%mod;
	}
	ans=(ans%mod+mod*5ll+3ll*sum%mod)%mod;
	printf("%d",ans);
}