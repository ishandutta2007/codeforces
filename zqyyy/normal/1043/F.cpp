#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
    int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c^48),c=getchar();
	return f?r:-r;
}
const int N=3e5+7,mod=1e9+9;
inline int qpow(int a,int b){
	int res=1;
	for(;b;b>>=1,a=1ll*a*a%mod)
		if(b&1)res=1ll*res*a%mod;
	return res;
}
int fac[N],ifac[N];
inline int C(int n,int m){
	if(m<0 || n<m)return 0;
	return 1ll*fac[n]*ifac[m]%mod*ifac[n-m]%mod;
}
int n,m,K,cnt[N],p[N],mn[N],mx[N],f[N];
int main(){
//	freopen("sor.in","r",stdin);
//	freopen("sor.out","w",stdout);
	n=read(),m=1;
	for(int i=1;i<=n;i++){
		int x=read();
		cnt[x]++,K=max(K,x);
	}
	K=max(K,m);
	for(int i=1;i<=K;i++){
		for(int j=i;j<=K;j+=i)
			p[i]+=cnt[j];
		mx[i]=p[i];
	}
	fac[0]=1;
	for(int i=1;i<=n;i++)fac[i]=1ll*fac[i-1]*i%mod;
	ifac[n]=qpow(fac[n],mod-2);
	for(int i=n;i;i--)ifac[i-1]=1ll*ifac[i]*i%mod;
	for(int j=1;j<=7;j++){
		for(int i=1;i<=K;i++)f[i]=0;
		for(int i=K;i;i--){
			f[i]=C(p[i],j);
			for(int k=i+i;k<=K;k+=i)
				f[i]=(f[i]+mod-f[k])%mod;
		}
		for(int i=1;i<=K;i++)
			if(f[i] && !mn[i])mn[i]=j;
	}
	for(int i=1;i<=m;i++)
		if(!mn[i])puts("-1");
		else printf("%d\n",mn[i]);
	return 0;
}