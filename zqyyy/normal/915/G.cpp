#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))r=(r<<1)+(r<<3)+(ch&15),ch=getchar();
	return f?r:-r;
}
const int N=2e6+7,mod=1e9+7;
inline int qpow(int a,int b){
	int res=1;
	for(;b;b>>=1,a=1ll*a*a%mod)
		if(b&1)res=1ll*res*a%mod;
	return res;
}
int s_p,pr[N],mu[N],v[N];
inline void init(int n){
	mu[1]=1;
	for(int i=2;i<=n;i++){
		if(!v[i])mu[i]=-1,pr[++s_p]=i,v[i]=i;
		for(int j=1;j<=s_p && i*pr[j]<=n;j++){
			v[i*pr[j]]=1;
			if(i%pr[j]==0){mu[i*pr[j]]=0;break;}
			mu[i*pr[j]]=-mu[i];
		}
	}
}
int n,K,pw[N],f[N];
int main(){
	n=read(),K=read(),init(K);
	for(int i=1;i<=K;i++)pw[i]=qpow(i,n);
	for(int d=1;d<=K;d++)
		for(int i=d;i<=K;i+=d)
			f[i]=(0ll+f[i]+mod+mu[d]*(pw[i/d]-pw[(i-1)/d]))%mod;
	int ans=0;
	for(int i=1;i<=K;i++)f[i]=(f[i-1]+f[i])%mod,ans=(ans+(f[i]^i))%mod;
	printf("%d\n",ans);
	return 0;
}