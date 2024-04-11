#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))r=(r<<1)+(r<<3)+(ch^48),ch=getchar();
	return f?r:-r;
}
const int N=1e6+7,mod=1e9+7;
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
int n,k,f[N],s[N];
int main(){
	n=read(),k=read(),fac[0]=1;
	for(int i=1;i<=n;i++)fac[i]=1ll*fac[i-1]*i%mod;
	ifac[n]=qpow(fac[n],mod-2);
	for(int i=n;i;i--)ifac[i-1]=1ll*ifac[i]*i%mod;
	f[0]=s[0]=1;
	for(int i=1;i<=n;i++){
		f[i]=1ll*fac[i-1]*(s[i-1]+(i-k-1>=0?mod-s[i-k-1]:0))%mod;
		s[i]=(s[i-1]+1ll*f[i]*ifac[i]%mod)%mod;
	}
	int ans=fac[n];
	for(int i=1;i<=n;i++)
		ans=(ans+mod-1ll*C(n-1,i-1)*fac[n-i]%mod*f[i-1]%mod)%mod;
	printf("%d\n",ans);
	return 0;	
}