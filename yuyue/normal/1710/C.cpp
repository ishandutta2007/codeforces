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
const int M=2e5+10;
const int mod=998244353;
char s[M];
int n,dp[M][8][2][2];
void red(int &x){
	x=(x>=mod ? x-mod :x);
}
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	scanf("%s",s+1);
	n=strlen(s+1);
	int t0=0,t1=1;
	F(i,1,n){
		int o=s[i]-'0';
		dp[i][0][0][0]+=6ll*(t0)%mod;
		if (o) dp[i][1][0][0]+=3ll*(t1)%mod,dp[i][6][0][0]+=3ll*(t1)%mod;
		if (o) t0=(t0*2ll+t1)%mod,t1=t1;
		else t0=(t0*2)%mod;
		//000
		F(l,0,7) F(j,0,1) F(k,0,1)
		red(dp[i][l*(!o)][j][k]+=dp[i-1][l][j][k]);
		//111
		F(l,0,7) F(j,0,1) F(k,0,1)
		if (o||!l)red(dp[i][l][j][k]+=dp[i-1][l][j][k]);
		
		//110
		F(j,0,7) F(k,0,1) F(l,0,1){
			if (o || !(j&1)){
				red(dp[i][(o ? j&1 : j)][k][l]+=dp[i-1][j][k][l]);
			}
			if (o || !(j&6)){
				red(dp[i][(o ? j&6 : j)][k][l]+=dp[i-1][j][k][l]);
			}
		}
		//101 011
		F(j,0,7) F(k,0,1) F(l,0,1){
			{
				if (o || !(j&2)) red(dp[i][(o ? j&2 : j)][1][l]+=dp[i-1][j][k][l]);
				if (o || !(j&5)) red(dp[i][(o ? j&5 : j)][1][l]+=dp[i-1][j][k][l]);
				if (o || !(j&3)) red(dp[i][(o ? j&3 : j)][k][1]+=dp[i-1][j][k][l]);
				if (o || !(j&4)) red(dp[i][(o ? j&4 : j)][k][1]+=dp[i-1][j][k][l]);
			}
		}
//		F(j,0,7) F(k,0,1) F(l,0,1){
//			cout<<dp[i][j][k][l]<<" "<<i<<" "<<j<<" "<<k<<" "<<l<<"  dp\n";
//		}
	}
	LL ans=0;
	F(j,0,7) ans=(ans+dp[n][j][1][1])%mod;
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