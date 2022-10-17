#include<bits/stdc++.h>
#define LL long long
#define SZ(x) (int)x.size()-1
#define F(i,a,b) for (int i=a;i<=b;++i)
#define DF(i,a,b) for (int i=a;i>=b;--i)
#define pb push_back
#define ms(a,b) memset(a,b,sizeof a)
using namespace std;
int read(){
    char ch=getchar(); int w=1,c=0;
    for (;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
    for (;isdigit(ch);ch=getchar()) c=(c<<3)+(c<<1)+(ch^48);
    return w*c;
}
const int mod=998244353,M=2020;
LL dp[M][M<<1];
int a[M],h[M];
int n,k;
int main(){
	n=read(); k=read();
	F(i,1,n) h[i]=i+1,a[i]=read();
	h[n]=1;
	dp[0][n]=1;
	F(i,1,n){
		F(j,0,2*n){
			int u=a[i],v=a[h[i]];
			if (u==v){
				dp[i][j]=dp[i-1][j]*k%mod;
			}
			else {
				if (j) dp[i][j]=dp[i-1][j-1];
				dp[i][j]=(dp[i][j]+dp[i-1][j+1]+dp[i-1][j]*(k-2))%mod;
			}
		}
	}
	LL ans=0;
	F(i,n+1,2*n){
		ans+=dp[n][i]; ans%=mod;
	}
	cout<<ans<<"\n";
    return 0;
}