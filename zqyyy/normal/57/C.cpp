#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))r=(r<<1)+(r<<3)+(ch^48),ch=getchar();
	return f?r:-r;
}
const int N=2e5+7,mod=1e9+7;
inline int qpow(int a,int b){
	int res=1;
	for(;b;b>>=1,a=1ll*a*a%mod)
		if(b&1)res=1ll*res*a%mod;
	return res;
}
int n,fac[N],ifac[N];
inline int C(int n,int m){
	return 1ll*fac[n]*ifac[m]%mod*ifac[n-m]%mod;
}
int main(){
	n=read(),fac[0]=1;
	for(int i=1;i<=n+n;i++)fac[i]=1ll*fac[i-1]*i%mod;
	ifac[n+n]=qpow(fac[n+n],mod-2);
	for(int i=n+n;i;i--)ifac[i-1]=1ll*ifac[i]*i%mod;
	printf("%d\n",(2*C(n+n-1,n)%mod-n+mod)%mod);
	return 0;
}