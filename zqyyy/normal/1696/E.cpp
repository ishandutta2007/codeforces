#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
const int N=4e5+7,mod=1e9+7;
inline void inc(int &x,int y){x+=y-mod,x+=x>>31&mod;}
inline int qpow(int a,int b){
	int res=1;
	for(;b;b>>=1,a=(ll)a*a%mod)
		if(b&1)res=(ll)res*a%mod;
	return res;	
}
int fac[N],ifac[N];
inline int C(int n,int m){
	if(n<m || m<0)return 0;
	return (ll)fac[n]*ifac[m]%mod*ifac[n-m]%mod;
}
inline void init(int n){
	fac[0]=1;
	for(int i=1;i<=n;i++)fac[i]=(ll)fac[i-1]*i%mod;
	ifac[n]=qpow(fac[n],mod-2);
	for(int i=n;i;i--)ifac[i-1]=(ll)ifac[i]*i%mod;
}
int n;
int main(){
#ifndef ONLINE_JUDGE
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	init(4e5+2),n=read();
	int ans=0;
	for(int i=0;i<=n;i++)inc(ans,C(i+read(),i+1));
	printf("%d\n",ans);
	return 0;
}