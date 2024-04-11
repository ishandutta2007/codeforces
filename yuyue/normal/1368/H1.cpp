#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
//#define mp make_pair
using namespace std;
//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
inline int read(){
	char ch=getchar(); int w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=1e5+10;
int n,m,dp[M][2];
char L[M],R[M],U[M],D[M];
int calc(){
	dp[1][0]=dp[1][1]=0;
	F(i,1,n) dp[1][0]+=(L[i]=='R'),dp[1][1]+=(L[i]=='B');
	F(i,1,m){
		int c0=(U[i]=='R')+(D[i]=='R');
		int c1=(U[i]=='B')+(D[i]=='B');
		if (i==1){
			dp[i][0]+=c0; dp[i][1]+=c1;
			continue;
		}
		dp[i][0]=min(dp[i-1][0],dp[i-1][1]+n)+c0;
		dp[i][1]=min(dp[i-1][1],dp[i-1][0]+n)+c1;
	}
	F(i,1,n) dp[m][0]+=(R[i]=='R'),dp[m][1]+=(R[i]=='B');
	return min(dp[m][0],dp[m][1]);
} 
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	n=read(); m=read(); int q=read();
	scanf("%s%s%s%s",L+1,R+1,U+1,D+1);
	int ans=calc();
	swap(n,m); swap(L,U); swap(R,D);
	ans=min(ans,calc());
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