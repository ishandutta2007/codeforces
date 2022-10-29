#include<bits/stdc++.h>
#define mod 1000000007
#define maxn 200100
using namespace std;
int fac[maxn],inv[maxn],n,a[maxn],ans;
int C(int x,int y){return 1ll*fac[y]*inv[x]%mod*inv[y-x]%mod;}
int qpow(int a,int b){int ans=1,tmp=a;for(;b;b>>=1,tmp=1ll*tmp*tmp%mod)if(b&1)ans=1ll*ans*tmp%mod;return ans;}
int main(){
	scanf("%d",&n);
	fac[0]=inv[0]=1;
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]),fac[i]=1ll*i*fac[i-1]%mod;
	inv[n]=qpow(fac[n],mod-2);
	for(int i=n-1;i>=1;--i)inv[i]=1ll*inv[i+1]*(i+1)%mod;
	if(n%4==0){
		for(int i=1;i<=n;i++)
			ans=(ans+1ll*(i&1?1:-1)*C((i-1)>>1,(n>>1)-1)*a[i])%mod,ans=(ans+mod)%mod;//,printf("[%d]",(i&1?1:-1)*C((i-1)>>1,(n>>1)-1));
		printf("%d\n",ans);
	} else if(n%4==1){
		for(int i=1;i<=n;i+=2)
			ans=(ans+1ll*C(i>>1,n>>1)*a[i])%mod;
		printf("%d\n",ans);
	} else if(n%4==2){
		for(int i=1;i<=n;++i)
			ans=(ans+1ll*C((i-1)>>1,(n-1)>>1)*a[i])%mod;
		printf("%d\n",ans);
	} else {
		for(int i=2;i<=n;i+=2)
			ans=(ans+2ll*C((i-1)>>1,(n-2)>>1)*a[i])%mod;
		int lst=0;
		for(int i=1;i<=n/2;i+=2)
			ans=(ans+1ll*(C(i>>1,(n-2)>>1)-lst)*(a[i]-a[n+1-i]))%mod,ans=(ans+mod)%mod,lst=C(i>>1,(n-2)>>1);
		printf("%d\n",ans);
	}
}