#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
int qpow(int a,int b){
	int ans=1;
	for(;b;b>>=1,a=1ll*a*a%mod)
		if(b&1)ans=1ll*ans*a%mod;
	return ans;
}
ll n,k;
int P[100][100],f[100],g[100],inv[110];
int cal(ll p,int cnt){
	p%=mod;
	ll fac=1,sum=0;
	for(int j=0;j<=cnt;++j,fac=fac*p%mod)
		sum=(sum+1ll*P[cnt][j]*fac)%mod;
	return sum;
}
int main(){
	scanf("%lld%lld",&n,&k);
	int M=60;
	for(int i=1;i<=100;++i)inv[i]=qpow(i,mod-2);
	for(int i=0;i<=M;++i){
		memset(f,0,sizeof(f));
		f[i]=1;
		for(int j=1;j<=k;++j){
			memset(g,0,sizeof(g));
			for(int k=0;k<=M;++k)
				g[k]=(g[k]+1ll*f[k]*inv[k+1])%mod;
			for(int k=M;k>=0;--k)g[k]=(g[k+1]+g[k])%mod;
			for(int k=0;k<=M;++k)f[k]=g[k];
		}
		for(int j=0;j<=i;++j)P[i][j]=f[j];
	}
	int ans=1;
	for(ll i=2;i*i<=n;i++)if(n%i==0){
		int cnt=0;
		while(n%i==0)n/=i,cnt++;
		ans=1ll*ans*cal(i,cnt)%mod;
	}
	if(n>1)ans=1ll*ans*cal(n,1)%mod;
	ans=(ans%mod+mod)%mod;
	printf("%d",ans);
}