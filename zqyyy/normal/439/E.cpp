#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c^48),c=getchar();
	return f?r:-r;
}
const int N=1e5+7,mod=1e9+7;
inline int qpow(int a,int b){
	int res=1;
	for(;b;b>>=1,a=1ll*a*a%mod)
		if(b&1)res=1ll*res*a%mod;
	return res;
}
int fac[N],ifac[N];
inline int C(int n,int m){
	if(m<0 || n<m)return 0;
	return 1ll*fac[n]*ifac[m]%mod*ifac[n-m]%mod;
}
int s_p,pr[N],v[N],mu[N];
inline void init(int n){
	mu[1]=1;
	for(int i=2;i<=n;i++){
		if(!v[i])v[i]=i,pr[++s_p]=i,mu[i]=-1;
		for(int j=1;j<=s_p && i*pr[j]<=n;j++){
			v[i*pr[j]]=pr[j];
			if(i%pr[j]==0){mu[i*pr[j]]=0;break;}
			mu[i*pr[j]]=-mu[i];
		}
	}
	fac[0]=1;
	for(int i=1;i<=n;i++)fac[i]=1ll*fac[i-1]*i%mod;
	ifac[n]=qpow(fac[n],mod-2);
	for(int i=n;i;i--)ifac[i-1]=1ll*ifac[i]*i%mod;
}
int n,m,Q;
int main(){
	init(1e5),Q=read();
	while(Q--){
		n=read(),m=read();int ans=0;
		for(int i=1;i*i<=n;i++)
			if(n%i==0){
				ans=(ans+mu[i]*C(n/i-1,m-1))%mod;
				if(i*i!=n)ans=(ans+mu[n/i]*C(i-1,m-1))%mod;
			}
		ans=(ans+mod)%mod;
		printf("%d\n",ans);
	}
	return 0;
}