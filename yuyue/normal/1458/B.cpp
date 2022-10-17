#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
using namespace std;
inline LL read(){
	char ch=getchar(); LL w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=102;
int dp[M][M][M*M],a[M],b[M],n;
int main(){
	n=read(); 
	F(i,1,n){
		b[i]=read();
		a[i]=read();
	}
	int sum=0;
	ms(dp,~1); 
	dp[0][0][0]=0;
	F(i,1,n){
		sum+=a[i];
		F(j,0,n){
			F(k,0,sum){
				dp[i][j][k]=dp[i-1][j][k];
				if (k>=a[i] && j){
					dp[i][j][k]=max(dp[i-1][j-1][k-a[i]]+b[i],dp[i][j][k]);
				}
			}
		}
	}
	F(i,1,n){
		double mx=0;
		F(j,0,sum){
//			if (i==1){
//				if (dp[n][i][j]){
//					cout<<j<<" "<<dp[n][i][j]<<"   gg\n";
//				}
//			}
			mx=max(mx,min((double)(sum+j)/2.0,(double)dp[n][i][j]));
		}
		cout<<fixed<<setprecision(10)<<mx<<" ";
	}
	return 0;
}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/