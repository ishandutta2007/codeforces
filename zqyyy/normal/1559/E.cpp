#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c^48),c=getchar();
	return f?r:-r;
}
const int N=57,M=1e5+7,mod=998244353;
int n,m,k,l[N],r[N],mu[M],pr[M],v[M];
inline void init(int n){
	mu[1]=1;
	for(int i=2;i<=n;i++){
		if(!v[i])v[i]=i,mu[i]=-1,pr[++m]=i;
		for(int j=1;j<=m && 1ll*i*pr[j]<=n;j++){
			v[i*pr[j]]=pr[j];
			if(i%pr[j])mu[i*pr[j]]=-mu[i];
			else{mu[i*pr[j]]=0;break;}
		}
	}
}
int f[M],g[M];
inline int solve(int d){
	for(int i=0;i<=k/d;i++)f[i]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=k/d;j++)g[j]=0;
		int L=(l[i]+d-1)/d,R=r[i]/d;
		for(int j=k/d;j>=L;j--)g[j]=(f[j-L]+mod-(j-R-1>=0?f[j-R-1]:0))%mod;
		f[0]=g[0];
		for(int j=1;j<=k/d;j++)f[j]=(f[j-1]+g[j])%mod;
	}
	return f[k/d];
}
int main(){
	n=read(),k=read(),init(k);
	for(int i=1;i<=n;i++)l[i]=read(),r[i]=read();
	int ans=0;
	for(int d=1;d<=k;d++){
		if(!mu[d])continue;
		ans=(0ll+ans+mod+mu[d]*solve(d))%mod;
	}
	return cout<<ans,0;
}