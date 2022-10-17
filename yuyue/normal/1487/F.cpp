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
const int M=55,inf=1e9; 
char s[M];
int n,a[M],b[M];
int dp[M][M*2][5];
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	scanf("%s",s+1); n=strlen(s+1);
	reverse(s+1,s+n+1);
	F(i,1,n) a[i]=s[i]-'0';
	F(i,1,n) b[i]=a[i+1]-a[i];
	ms(dp,60);
	dp[n+1][M-2][0]=2*(n+1);
	dp[n+1][M-1][1]=(n+1);
	dp[n+1][M][2]=0;
	dp[n+1][M+1][3]=(n+1);
	dp[n+1][M+2][4]=2*(n+1);
	int ans=inf;
	DF(i,n+1,2){
		F(j,M-n,M+n){
			F(o,-2,2){
				if (dp[i][j][o+2]>inf) continue;
				int tmp=dp[i][j][o+2];
				if (i>2){
					dp[i-1][j-2][0]=min(dp[i-1][j-2][0],tmp+abs(b[i-1]+o*10+2)*(i-1));
					dp[i-1][j-1][1]=min(dp[i-1][j-1][1],tmp+abs(b[i-1]+o*10+1)*(i-1));
					dp[i-1][j][2]=min(dp[i-1][j][2],tmp+abs(b[i-1]+o*10)*(i-1));
					dp[i-1][j+1][3]=min(dp[i-1][j+1][3],tmp+abs(b[i-1]+o*10-1)*(i-1));
					dp[i-1][j+2][4]=min(dp[i-1][j+2][4],tmp+abs(b[i-1]+o*10-2)*(i-1));
				}
				else{
					ans=min(ans,tmp+abs(b[1]+o*10+j-M));
				}
			}
		}
	}
	
	cout<<ans<<"\n";
	return 0;
}

/*

*/