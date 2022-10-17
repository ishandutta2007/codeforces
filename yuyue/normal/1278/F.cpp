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
LL fast(LL x,LL p){
	LL ret=1;
	for (;p;p>>=1,x=x*x%mod) if (p&1) ret=ret*x%mod;
	return ret; 
}
int S[M][M];
LL fac[M],inv[M];  
int n,m,k; 
int main(){
	n=read(); m=read(); k=read();
	fac[0]=1; F(i,1,k) fac[i]=fac[i-1]*i%mod;
	inv[k]=fast(fac[k],mod-2);
	DF(i,k,1) inv[i-1]=inv[i]*i%mod;
	F(i,1,k){
		S[i][1]=1;
		F(j,2,i){
			S[i][j]=(S[i-1][j-1]+1ll*j*S[i-1][j])%mod; 
		}
	}
	LL ans=0;
	LL comb=1;
	F(i,0,min(n,k)){
		ans=(ans+1ll*S[k][i]*fast(m,n-i)%mod*comb)%mod; 
		comb=comb*(n-i)%mod;
	}
	cout<<ans*fast(fast(m,mod-2),n)%mod<<"\n"; 
	return 0;
}