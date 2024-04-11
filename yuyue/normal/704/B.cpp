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
const int M=5050;
int x[M],a[M],b[M],c[M],d[M];
LL dp[M][M];
int n,s,e;
int main(){
	n=read(); s=read(); e=read(); 
	F(i,1,n) x[i]=read();
	F(i,1,n) a[i]=read();
	F(i,1,n) b[i]=read();
	F(i,1,n) c[i]=read();
	F(i,1,n) d[i]=read();
	ms(dp,1); dp[0][0]=0;
	int base=0;
	F(i,1,n){
		F(j,base,i){
			if (i==s){
				dp[i][j+1]=min(dp[i][j+1],dp[i-1][j]+d[i]-x[i]);
				if (j) dp[i][j]=min(dp[i][j],dp[i-1][j]+c[i]+x[i]);
				continue;
			}
			if (i==e){
				dp[i][j+1]=min(dp[i][j+1],dp[i-1][j]+b[i]-x[i]);
				if (j) dp[i][j]=min(dp[i][j],dp[i-1][j]+a[i]+x[i]);
				continue;
			}
			if (j>(i>s)) dp[i][j]=min(dp[i][j],dp[i-1][j]+b[i]+c[i]);
			if (j>(i>e)) dp[i][j]=min(dp[i][j],dp[i-1][j]+a[i]+d[i]);
			dp[i][j+1]=min(dp[i][j+1],dp[i-1][j]+b[i]+d[i]-2*x[i]);
			if (j>=2) dp[i][j-1]=min(dp[i][j-1],dp[i-1][j]+a[i]+c[i]+2*x[i]);
		}
		if (i==s || i==e) base++;
	}
	cout<<dp[n][1]<<"\n";
	return 0;
}