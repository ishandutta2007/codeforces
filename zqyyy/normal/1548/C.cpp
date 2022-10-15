#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
const int N=3e6+7,mod=1e9+7;
inline int qpow(int a,int b){
	int res=1;
	for(;b;b>>=1,a=1ll*a*a%mod)
		if(b&1)res=1ll*res*a%mod;
	return res;
}
int fac[N],ifac[N];
inline int C(int n,int m){
	if(n<m || m<0)return 0;
	return 1ll*fac[n]*ifac[m]%mod*ifac[n-m]%mod;
}
int n,Q,f[N];
int main(){
	n=read(),Q=read(),fac[0]=1;
	for(int i=1;i<=3*n+3;i++)fac[i]=1ll*fac[i-1]*i%mod;
	ifac[3*n+3]=qpow(fac[3*n+3],mod-2);
	for(int i=3*n+3;i;i--)ifac[i-1]=1ll*ifac[i]*i%mod;
	for(int i=3*n;i;i--)f[i]=(C(3*n+3,i+3)+mod-(f[i+1]+f[i+2])*3ll%mod)%mod;
	while(Q--)printf("%d\n",f[read()]);
	return 0;
}