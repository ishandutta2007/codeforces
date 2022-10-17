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
const int M=444;
int mod,n;
LL dp[M][M],pw[M];
LL fast(LL x,LL p){
	LL ret=1;
	for (;p;p>>=1,x=x*x%mod) if (p&1) ret=ret*x%mod;
	return ret;
}
LL fac[M],inv[M];
int main(){
	cin>>n>>mod;
	pw[0]=1,fac[0]=1;
	F(i,1,n) pw[i]=pw[i-1]*2%mod,fac[i]=fac[i-1]*i%mod;
	F(i,0,n) inv[i]=fast(fac[i],mod-2);
	dp[0][0]=1;
	F(i,1,n){// i ge
		F(j,1,n){// sum=j
			F(k,1,j){
				dp[i][j]=(dp[i][j]+dp[i-1][j-k]*pw[k-1]%mod*inv[k])%mod;
			}
		}
//		cout<<dp[1][3]<<"   dp \n";
	}
	LL ans=0;
	F(i,1,n){
//		cout<<dp[i][n-i+1]<<"    hh\n";
		ans=(ans+dp[i][n-i+1]*fac[n-i+1])%mod;
	}
	cout<<ans<<"\n";
	return 0;
}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/