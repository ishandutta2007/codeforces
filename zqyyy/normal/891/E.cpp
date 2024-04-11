#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int f=1,r=0;char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))r=(r<<3)+(r<<1)+(ch^48),ch=getchar();
	return f?r:-r;	
}
const int N=5005,mod=1e9+7;
inline int qpow(int a,int b){
	int res=1;
	for(;b;b>>=1,a=1ll*a*a%mod)
		if(b&1)res=1ll*res*a%mod;
	return res;	
}
int n,K,a[N],f[N];
int main(){
	n=read(),K=read();
	for(int i=1;i<=n;i++)a[i]=read();
	f[0]=1;
	for(int i=1;i<=n;i++){
		for(int j=i;j;j--)f[j]=(1ll*f[j]*a[i]-f[j-1]+mod)%mod;
		f[0]=1ll*f[0]*a[i]%mod;
	}
	int ans=0,tmp=1,inv=qpow(n,mod-2);
	for(int i=0;i<=n;i++){
		ans=(ans+1ll*f[i]*tmp)%mod;
		tmp=1ll*tmp*(K-i)%mod*inv%mod;	
	}
	return cout<<(f[0]-ans+mod)%mod,0;
}