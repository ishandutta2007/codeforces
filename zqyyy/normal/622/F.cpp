#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
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
int s_p,m,num,pr[N],pw[N];
inline void init(int n){
	fac[0]=1;
	for(int i=1;i<=n;i++)fac[i]=1ll*fac[i-1]*i%mod;
	ifac[n]=qpow(fac[n],mod-2);
	for(int i=n;i;i--)ifac[i-1]=1ll*ifac[i]*i%mod;
	pw[1]=1;
	for(int i=2;i<=n;i++){
		if(!pw[i])pr[++s_p]=i,pw[i]=qpow(i,m);
		for(int j=1;j<=s_p && i*pr[j]<=n;j++){
			pw[i*pr[j]]=1ll*pw[i]*pw[pr[j]]%mod;
			if(i%pr[j]==0)break;
		}
	}
    for(int i=1;i<=n;i++)
        (pw[i]+=pw[i-1])%=mod;
}
int n,p[N];
inline int calc(ll x){
    if(x<=num)return pw[x];
	p[0]=1;
	for(int i=1;i<=num;i++)
		p[i]=p[i-1]*(x-i)%mod;
	pr[num+1]=1;
	for(int i=num;i;i--)
		pr[i]=pr[i+1]*(x-i)%mod;
	ll ans=0;
	for(int i=1;i<=num;i++){
		int tmp=1ll*pw[i]*p[i-1]%mod*pr[i+1]%mod*ifac[i-1]%mod*ifac[m+2-i]%mod;
		if((num-i)&1)ans-=tmp;
		else ans+=tmp;
	}
	return (ans%mod+mod)%mod;
}
int main(){
	n=read(),m=read(),init(num=m+2);
	printf("%d\n",calc(n));
	return 0;
}