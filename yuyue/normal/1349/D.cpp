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
const int mod=998244353,M=3e5+10; 
LL fast(LL x,LL p){
	LL ret=1;
	for (;p;p>>=1,x=x*x%mod) if (p&1) ret=ret*x%mod; 
	return ret;
}
int n,a[M];
LL f[M];
int main(){
	n=read();
	int m=0;
	F(i,1,n) a[i]=read(),m+=a[i];
	f[0]=n-1;
	F(i,1,m-1){
		f[i]=(1ll*m*(n-1)+1ll*i*(n-1)%mod*f[i-1])%mod; 
		f[i]=f[i]*fast(m-i,mod-2)%mod;
	}
	DF(i,m-1,0) f[i]=(f[i]+f[i+1])%mod;
	LL ans=mod-1ll*(n-1)*f[0]%mod;
	ans%=mod;
	F(i,1,n) ans=(ans+f[a[i]])%mod;
	cout<<ans*fast(n,mod-2)%mod<<"\n";
	return 0;
}