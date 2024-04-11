#include<bits/stdc++.h>
#define maxn 2001000
using namespace std;
int n,m,a,q,mod,A[maxn],fac[maxn],inv[maxn],b[maxn];
int getphi(){
	int ans=1;
	A[0]=1;
	for(int x=1;x<=q;++x){
		ans=1ll*ans*a%q;
		A[x]=ans;
		if(ans==1)return x;
	}
}
int C(int x,int y){
	if(x<0||x>y)return 0;
	if(x<mod&&y<mod)return 1ll*fac[y]*inv[x]%mod*inv[y-x]%mod;
	else return 1ll*C(x%mod,y%mod)*C(x/mod,y/mod)%mod;
}
int qpow(int a,int b,int p){
	int ans=1,tmp=a;
	for(;b;b>>=1,tmp=1ll*tmp*tmp%p)
		if(b&1)ans=1ll*ans*tmp%p;
	return ans;
}
int main(){
	scanf("%d%d%d%d",&n,&m,&a,&q);
	mod=getphi(),fac[0]=inv[0]=1;
	for(int i=1;i<mod;++i)fac[i]=1ll*fac[i-1]*i%mod;
	inv[mod-1]=qpow(fac[mod-1],mod-2,mod);
	for(int i=mod-2;i>=1;--i)inv[i]=1ll*inv[i+1]*(i+1)%mod;
	int ans=0;
	for(int i=1;i<=n;++i){
		ans=(ans+C(i-1,m))%mod;
		b[n-i+1]=A[ans];
	}
	for(int i=1;i<=n;++i)printf("%d ",b[i]);
}