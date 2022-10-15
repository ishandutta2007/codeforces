#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
const int N=1e6+7,mod=1e9+7;
inline void add(int &x,int y){x+=y;if(x>=mod)x-=mod;}
inline int qpow(int a,int b){
	int res=1;
	for(;b;b>>=1,a=1ll*a*a%mod)
		if(b&1)res=1ll*res*a%mod;
	return res;
}
int n,m,K,fac[N],ifac[N];
inline int C(int n,int m){
	if(n<m || m<0)return 0;
	return 1ll*fac[n]*ifac[m]%mod*ifac[n-m]%mod;
}
inline void work(){
	n=read(),m=read(),K=read(),fac[0]=1;
	for(int i=1;i<=n;i++)fac[i]=1ll*fac[i-1]*i%mod;
	ifac[n]=qpow(fac[n],mod-2);
	for(int i=n;i;i--)ifac[i-1]=1ll*ifac[i]*i%mod;
	int ans=0;n-=m;
	if(!n)ans=m;
	else if(m){
		int inv=qpow(qpow(2,n+m-1),mod-2);
		for(int i=1;i<=m;i++){
			add(ans,1ll*i*inv%mod*C(n+m-i-1,n-1)%mod);
			inv=(inv<<1)%mod;
		}
	}
	ans=1ll*ans*K%mod;
	printf("%d\n",ans);
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	int test=read();
	while(test--)work();
	return 0;
}