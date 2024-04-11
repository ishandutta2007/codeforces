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
const int M=3e5+10;
int mod,n,k;
LL fast(LL x,LL p){
	LL ret=1;
	for (;p;p>>=1,x=x*x%mod) if (p&1) ret=ret*x%mod;
	return ret; 
}
int dp[30][M]; 
LL fac[M],inv[M];
#define lowbit(x) (x&-x)
int dfs(int x,int msk){
	if (dp[x][msk]!=-1) return dp[x][msk];
	if (x>k) return 0; 
	if (!msk){
		return dp[x][msk]=fac[n]*fac[k]%mod*inv[k-x]%mod; 
	}
	dp[x][msk]=0;
	int U=msk-lowbit(msk);
	for (int A=U;A;A=(A-1)&U) dp[x][msk]=(dp[x][msk]+inv[msk-A]*dfs(x+1,A))%mod; 
	dp[x][msk]=(dp[x][msk]+inv[msk]*dfs(x+1,0))%mod;
	return dp[x][msk]; 
}
int main(){
	n=read(); k=read(); mod=read();
	if (n&1) {
		cout<<fast(k,n)<<"\n"; 
		return 0; 
	}
	fac[0]=1; F(i,1,n) fac[i]=fac[i-1]*i%mod;
	inv[n]=fast(fac[n],mod-2);
	DF(i,n,1) inv[i-1]=inv[i]*i%mod;
	ms(dp,-1); 
	cout<<(mod+fast(k,n)-dfs(0,n))%mod<<"\n"; 
	return 0;
}