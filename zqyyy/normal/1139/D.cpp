#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
    int f=1,r=0;char c=getchar();
    while(!isdigit(c))f^=c=='-',c=getchar();
    while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
    return f?r:-r;
}
const int N=1e5+7,mod=1e9+7;
inline int qpow(int a,int b){
	int res=1;
	for(;b;b>>=1,a=1ll*a*a%mod)
		if(b&1)res=1ll*res*a%mod;
	return res;	
}
int n,m,pr[N],v[N],mu[N];
inline void init(int n){
	mu[1]=1;
	for(int i=2;i<=n;i++){
		if(!v[i])v[i]=i,pr[++m]=i,mu[i]=-1;
		for(int j=1;j<=m && 1ll*i*pr[j]<=n;j++){
			v[i*pr[j]]=pr[j];
			if(i%pr[j]==0)break;
			mu[i*pr[j]]=-mu[i];
		}
	}
}
int main(){
	n=read(),init(n);
	int ans=1;
	for(int i=2;i<=n;i++)
		if(mu[i])ans=(ans+mod-1ll*mu[i]*(n/i)*qpow(n-n/i,mod-2)%mod)%mod;
	printf("%d\n",ans);
	return 0;
}