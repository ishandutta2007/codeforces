#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
const int N=15,mod=1e9+7;
inline int qpow(int a,int b){
	int res=1;
	for(;b;b>>=1,a=1ll*a*a%mod)
		if(b&1)res=1ll*res*a%mod;
	return res;
}
int n,S,a[N];
int f[1<<N],g[1<<N],pw[1<<N][N];
int main(){
	n=read(),S=(1<<n)-1;
	for(int i=1;i<=n;i++)a[i]=read();
	for(int s=0;s<=S;s++){
		pw[s][1]=1;
		for(int i=1;i<=n;i++)
			if(s>>(i-1)&1)pw[s][1]=1ll*pw[s][1]*a[i]%mod;
		pw[s][0]=1;
		for(int i=2;i<=n;i++)pw[s][i]=1ll*pw[s][i-1]*pw[s][1]%mod;
		f[s]=1;
		for(int i=1;i<=n;i++)
			if(s>>(i-1)&1)
				for(int j=i+1;j<=n;j++)
					if(s>>(j-1)&1)
						f[s]=1ll*f[s]*(a[i]+a[j])%mod;
	}
	for(int s=1;s<=S;s++){
		g[s]=f[s];
		for(int t=(s-1)&s;t;t=(t-1)&s)
			g[s]=(g[s]+mod-1ll*g[t]*f[t]%mod*f[s^t]%mod*pw[t][__builtin_popcount(s^t)]%mod)%mod;
		g[s]=1ll*g[s]*qpow(f[s],mod-2)%mod;
	}
	int ans=0;
	for(int s=1;s<=S;s++)
		ans=(ans+1ll*g[s]*__builtin_popcount(s)%mod*f[s]%mod*f[S^s]%mod*pw[s][__builtin_popcount(s^S)])%mod;
	ans=1ll*ans*qpow(f[S],mod-2)%mod;
	printf("%d\n",ans);
	return 0;
}