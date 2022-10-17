#include <cstdio>
const int inf=1e9,N=5e3+10;
int T,n,m,ans,rev[N],dp[N][N];
char s[N],t[N];
inline void cmin(int &x,int y){if(x>y)x=y;}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d %d %s %s",&n,&m,s+1,t+1);
		for(int i=0;i<=n;++i)for(int j=0;j<=m;++j)dp[i][j]=-inf;
		dp[0][0]=0;
		for(int i=1;i<=n;++i)
			for(int j=0;j<=m;++j){
				if(dp[i-1][j]>=0)dp[i][j]=0;
				if(s[i]==t[j])dp[i][j]=dp[i-1][j-1]+1;
			}
		rev[n+1]=m+1;
		for(int i=n;i>=1;--i){
			rev[i]=rev[i+1];
			if(s[i]==t[rev[i]-1])--rev[i];
		}
		if(rev[1]!=1){puts("-1");continue;}
		ans=inf;
		for(int i=1;i<=n;++i)if(s[i]!=t[i]){ans=n-i+1;break;}
		if(ans==inf)ans=0;
		for(int i=2;i<=n+1;++i)
			for(int j=rev[i]-1;j<=m;++j)
				cmin(ans,n+1-dp[i-1][j]+i-1-j);
		printf("%d\n",ans);
	}
	return 0;
}