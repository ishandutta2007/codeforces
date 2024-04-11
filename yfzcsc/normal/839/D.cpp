#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
int ans,n,a[1001000],f[1001000],mx,b[200100];
int main(){
	scanf("%d",&n),b[0]=1;
	for(int i=1;i<=n;++i)
		b[i]=2ll*b[i-1]%mod;
	for(int i=1,x;i<=n;++i)
		scanf("%d",&x),a[x]++,mx=max(mx,x);
	for(int i=1;i<=mx;++i)
		for(int j=i+i;j<=mx;j+=i)a[i]+=a[j];
	for(int i=mx;i>=2;--i){
		f[i]=1ll*b[a[i]-1]*a[i]%mod;
		for(int j=i+i;j<=mx;j+=i)f[i]=(f[i]-f[j])%mod;
		ans=(ans+1ll*f[i]*i)%mod;
	}
	printf("%d",(ans+mod)%mod);
}