#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
const int N=2e7+7,mod=998244353;
inline int qpow(int a,int b){
	int res=1;
	for(;b;b>>=1,a=(ll)a*a%mod)
		if(b&1)res=(ll)res*a%mod;
	return res;
}
int fac[N],ifac[N];;
inline int C(int n,int m){
	if(n<m || m<0)return 0;
	return (ll)fac[n]*ifac[m]%mod*ifac[n-m]%mod;
}
inline int c(int n,int m){
	if(!m)return !n;
	return C(n+m-1,m-1);
}
inline void init_C(int n){
	fac[0]=1;
	for(int i=1;i<=n;i++)fac[i]=(ll)fac[i-1]*i%mod;
	ifac[n]=qpow(fac[n],mod-2);
	for(int i=n;i;i--)ifac[i-1]=(ll)ifac[i]*i%mod;
}
int n,m,K;
int main(){
	n=read(),m=read(),K=read();
	if(!K)printf("%d\n",qpow(n,mod-2)),exit(0);
	init_C(n+m);ll res=0;
	for(int i=0;i<=n;i++){
		if(i*K>m)break;
		int tmp=(ll)C(n,i)*c(m-i*K,n)%mod;
		i&1?res-=tmp:res+=tmp;
	}
	res=(res%mod+mod)%mod;
	int ans=qpow(n,mod-2)*(c(m,n)+mod-res)%mod*qpow(c(m-K,n),mod-2)%mod;
	printf("%d\n",ans);
	return 0;
}