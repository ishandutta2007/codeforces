#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
const int N=2505,M=1e5+7,mod=1e9+7;
inline int qpow(int a,int b){
	int res=1;
	for(;b;b>>=1,a=1ll*a*a%mod)
		if(b&1)res=1ll*res*a%mod;
	return res;
}
int n,sum,a[N],f[M];
int main(){
	n=read();int mx=0;
	for(int i=1;i<=n;i++)a[i]=read(),sum+=a[i],mx=max(mx,a[i]);
	f[1]=1ll*(sum-1)*(sum-1)%mod*qpow(sum,mod-2)%mod,f[2]=((f[1]<<1)-1)%mod;
	for(int i=3;i<=mx;i++)f[i]=(((f[i-1]<<1)%mod-f[i-2]+mod)%mod-1ll*(sum-1)*qpow(sum-i+1,mod-2)%mod+mod)%mod;
	long long ans=0;
	for(int i=1;i<=n;i++)ans+=f[a[i]];
	return cout<<ans%mod,0;
}