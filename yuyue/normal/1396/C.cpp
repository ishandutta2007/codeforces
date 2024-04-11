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
const int M=1e6+10;
LL dp[M][2],suf[M];
int a[M],n,x,y,z,d;
int main(){
	n=read(); x=read(); y=read(); z=read(); d=read();
	F(i,1,n) a[i]=read();
	ms(dp,63);
	int ki=min(x,min(y,z));
	dp[0][0]=-d; LL ans=dp[0][1];
	DF(i,n,1){
		LL mre=min(1ll*y,1ll*x*(a[i]+1))+ki,gan=1ll*x*a[i]+z;
		if (i==n) suf[n]=min(gan,mre+2*d);
		else suf[i]=suf[i+1]+min(mre,gan);
	}
	F(i,1,n){
		LL re=2ll*i*d,mre=min(1ll*y,1ll*x*(a[i]+1)),gan=1ll*x*a[i]+z;
		dp[i][0]=min(dp[i-1][0]+gan+d,dp[i-1][1]+d+re+min(gan,mre+ki));
		dp[i][1]=min(dp[i-1][0]-re+mre+ki+d,dp[i-1][1]+gan+d);
//		if (i==1) dp[i][0]-=d,dp[i][1]-=d;
//		cout<<dp[i-1][0]+gan+d<<"   trans 1 \n";
//		cout<<dp[i-1][0]-re<<" "<<mre+ki<<" "<<d<<"   trans 2\n";
//		cout<<dp[i][0]<<" "<<dp[i][1]<<"   hh \n";
		if (i<n)
		ans=min(ans,dp[i-1][0]+mre+ki+d+suf[i+1]+2ll*(n-i)*d);
//		cout<<suf[i+1]<<" "<<dp[i-1][0]+mre+ki+d<<" "<<2ll*(n-i)*d<<"   hg\n";
//		cout<<ans<<"   hola \n";
	}
	cout<<min(ans,dp[n][0])<<"\n";
	return 0;
}