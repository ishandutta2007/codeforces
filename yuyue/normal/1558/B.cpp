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
const int M=4e6+10;
LL dp[M],d[M],p[M];
int mod;
void red(LL &x){
	x=(x>=mod ? x-mod : x);
}
int n;
int main(){
	n=read(); mod=read();
	dp[1]=1;
	for (int j=2;j<=n;j++){
		int l=1*j,r=l+j;
		red(d[l]+=dp[1]);
		if (r<=n) red(d[r]+=mod-dp[1]);
	}
		
	LL sm=1;
	F(i,2,n){
		p[i]=(p[i-1]+d[i])%mod;
		dp[i]=(sm+p[i])%mod;
		for (int j=2;j<=n/i;j++){
			int l=i*j,r=l+j;
			red(d[l]+=dp[i]);
			
			if (r<=n) red(d[r]+=mod-dp[i]);
		}
		sm=(sm+dp[i])%mod;
	}
	cout<<dp[n]<<"\n";
	return 0;
}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/