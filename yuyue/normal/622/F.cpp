#include<bits/stdc++.h>
#define LL long long
#define SZ(x) (int)x.size()-1
#define F(i,a,b) for (int i=a;i<=b;++i)
#define DF(i,a,b) for (int i=a;i>=b;--i)
#define pb push_back
#define ms(a,b) memset(a,b,sizeof a)
using namespace std;
int read(){
    char ch=getchar(); int w=1,c=0;
    for (;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
    for (;isdigit(ch);ch=getchar()) c=(c<<3)+(c<<1)+(ch^48);
    return w*c;
}
const int mod=1e9+7,M=1e6+10;
LL fast(LL x,LL p){
	LL ret=1;
	for (;p;p>>=1,x=x*x%mod) if (p&1) ret=ret*x%mod;
	return ret;
} 
int n,k;
LL f[M],pr[M],sf[M],Y[M],inv[M]; 
int main(){
	n=read(); k=read();
	f[0]=1;
	F(i,1,k+1) Y[i]=(Y[i-1]+fast(i,k))%mod,f[i]=f[i-1]*i%mod;
	inv[k+1]=fast(f[k+1],mod-2); 
	DF(i,k+1,1) inv[i-1]=inv[i]*i%mod;
	sf[k+3]=pr[0]=1;
	F(i,1,k+2) pr[i]=pr[i-1]*(n-i+1)%mod;
	DF(i,k+2,1) sf[i]=sf[i+1]*(n-i+1)%mod;
	LL ans=0;
	F(i,0,k+1){
		if (n<=k+1) {
			if (i==n) ans=(ans+Y[i])%mod;
		}
		else {
			LL o=Y[i]*pr[i]%mod*sf[i+2]%mod*inv[i]%mod*inv[k+1-i]%mod;
			if ((k+1-i)&1) ans=(ans+mod-o)%mod;
			else ans=(ans+o)%mod;
		}
	} 
	cout<<ans<<"\n";
    return 0;
}