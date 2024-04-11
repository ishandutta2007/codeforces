#include<bits/stdc++.h>
#define mod 1000000007
#define maxn 5010
using namespace std;
int f[maxn][maxn],b[maxn],a[maxn],n,k,ans;
int qpow(int a,int b){
	int ans=1,tmp=a;
	for(;b;b>>=1,tmp=1ll*tmp*tmp%mod)
		if(b&1)ans=1ll*ans*tmp%mod;
	return ans;
}
int C(int x,int y){
	int ret=1;
	for(int i=x;i>=x-y+1;--i)
		ret=1ll*ret*i%mod;
	return ret;
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	f[0][0]=1;
	for(int i=1;i<=n;++i){
		f[i][0]=1;
		for(int j=1;j<=i;++j)
			f[i][j]=(f[i-1][j]+1ll*a[i]*f[i-1][j-1])%mod;
	}
	for(int i=1,z=qpow(n,mod-2),p=z;i<=n;++i,p=1ll*p*z%mod)
		b[i]=1ll*p*C(k,i)%mod;
	for(int i=1,k=1;i<=n;++i,k=mod-k)
		ans=(ans+1ll*k*b[i]%mod*f[n][n-i])%mod;
	printf("%d",ans);
}