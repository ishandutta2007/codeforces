#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
using namespace std;
inline int read(){
	char ch=getchar(); int w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=5050,mod=998244353;
int dp[M];
int n,a[M];
LL fast(LL x,LL p){
	LL ret=1;
	for (;p;p>>=1,x=x*x%mod) if (p&1) ret=ret*x%mod;
	return ret;
}
LL fac[M],inv[M];
void init(){
	fac[0]=1;
	F(i,1,n) fac[i]=fac[i-1]*i%mod;
	inv[n]=fast(fac[n],mod-2);
	DF(i,n,1) inv[i-1]=inv[i]*i%mod;
}
LL pre[M]; 
int lim[M];
int main(){
	n=read(); init();
	F(i,1,n) a[i]=read();
	sort(a+1,a+n+1);
	int pos=0;
	F(i,1,n){
		while (2*a[pos+1]<=a[i]) pos++;
		lim[i]=pos;
	}
	dp[0]=1;
	pre[0]=dp[0]*fac[n-1]%mod;
	F(i,1,n){
		dp[i]=pre[lim[i]]*inv[n-1-lim[i]]%mod;
		if (i^n) pre[i]=(pre[i-1]+dp[i]*fac[n-2-lim[i]])%mod;
	}
	if (lim[n]!=n-1) cout<<0<<"\n";
	else cout<<dp[n]<<'\n';
	return 0; 
}