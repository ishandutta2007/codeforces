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
const int M=2020,mod=998244353;
LL f[M][M],pw[M],g[M],dp[M],ipw[M];
LL fast(LL x,LL p){
	LL ret=1;
	for (;p;p>>=1,x=x*x%mod) if (p&1) ret=ret*x%mod;
	return ret;
}
int main(){
	int A,B,n;
	n=read(); A=read(); B=read();
	LL prob=fast(B,mod-2)*A%mod;
	f[0][0]=1;
	pw[0]=ipw[0]=1;
	F(i,1,n) pw[i]=pw[i-1]*prob%mod;
	F(i,1,n) ipw[i]=ipw[i-1]*(mod+1-prob)%mod;
	g[0]=1;
	F(i,1,n){
		F(j,0,i){
			f[i][j]=f[i-1][j]*ipw[j]%mod;
			if (j) f[i][j]=(f[i][j]+f[i-1][j-1]*pw[i-j])%mod;
		}
		g[i]=1;
		F(j,1,i-1) g[i]=(g[i]+1ll*(mod-g[j])*f[i][j])%mod;
	}
//	cout<<f[3][1]*8%mod<<" "<<g[3]*8%mod<<" ?? \n";
	F(i,1,n){
		LL coes=mod+1-g[i],coeb=1ll*(i-1)*i/2;
		F(j,1,i-1){
			coeb=(coeb+g[j]*f[i][j]%mod*(dp[j]+dp[i-j]+mod-(i-j)*(i-j-1)/2))%mod;
		}
//		cerr<<coeb*8%mod<<"  nmd \n";
		dp[i]=fast(coes,mod-2)*coeb%mod;
//		cerr<<dp[i]<<"  dp ? \n";
	}
	cout<<dp[n]%mod<<"\n";	
	return 0;
}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
f 3,1 = 3/4  
f 3,2 = 3/4
f 2,1 = 1

.** 1/4
*.* 1/4
**. 1/4

g1=1
g2=0
g3=1/4

15/4
*/