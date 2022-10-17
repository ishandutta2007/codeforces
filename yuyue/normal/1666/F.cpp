#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
//#define mp make_pair
//#define OO(x) fixed<<setprecision(x)
using namespace std;
//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
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
LL fac[M],inv[M],iv[M];
void init(int n){
	fac[0]=1;
	F(i,1,n) fac[i]=fac[i-1]*i%mod;
	inv[n]=fast(fac[n],mod-2);
	DF(i,n,1) inv[i-1]=inv[i]*i%mod;
	iv[1]=1;
	F(i,2,n) iv[i]=(mod-mod/i)*iv[mod%i]%mod;
}
LL C(int x,int y){
	if (y<0 || x<y) return 0;
	return fac[x]*inv[y]%mod*inv[x-y]%mod;
}
int n;
int dp[M][M],num[M],a[M];
int s[M][M];
void work(){
	n=read();
	F(i,1,n) num[i]=0;
	F(i,1,n) a[i]=read(),num[a[i]]++;
	F(i,1,n) num[i]+=num[i-1];
	dp[0][0]=1;
	F(i,1,n) F(j,0,n) s[i][j]=0;
	LL ans=0,coe=1;
	F(i,1,n){
		F(j,0,n) dp[i][j]=0;
		int o=num[i]-num[i-1];
		dp[i][1]=num[i-1]*o%mod;
		F(j,1,i){
			dp[i][j]=(dp[i][j]+1ll*s[i-1][j-1]*o)%mod;
//			cerr<<i<<" "<<j<<" "<<dp[i][j]<<"\n";
//			cerr<<(k ? num[k-1]-(2*(j-1)) : num[i-1])<<" "<<i<<" "<<k<<" "<<j<<"\n";
//			dp[i][j]=(dp[i][j]+1ll*dp[k][j-1]*)%mod*o : num[i-1]))%mod;
		}
		F(j,0,i) s[i][j]=(s[i-1][j]+1ll*dp[i][j]*max(0,num[i-1]-(2*(j)-1)))%mod;
		coe=coe*inv[o]%mod;
		ans=(ans+dp[i][n/2])%mod;
	}
	cout<<ans*coe%mod<<"\n";
}
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int T=read(); init(5005);
	while (T--) work();
	return 0;
}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
4
1 1 2 2
*/