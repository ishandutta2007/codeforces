#include <cstdio>
#include <cstring>
int n,l,k,ans=2147483647,d[510],a[510],dp[510][510];
inline int min(int x,int y){return x<y?x:y;}
int main(){
	scanf("%d %d %d",&n,&l,&k);
	memset(dp,0x3f,sizeof(dp));
	for(register int i=1;i<=n;++i)scanf("%d",&d[i]);
	for(register int i=1;i<=n;++i)scanf("%d",&a[i]);
	dp[1][0]=0,d[n+1]=l;
	for(register int i=1;i<=n;++i){
		for(register int j=0;j<=k;++j){
			for(register int p=0;j+p<=k&&i+p+1<=n+1;++p){
				dp[i+p+1][j+p]=min(dp[i+p+1][j+p],dp[i][j]+(d[i+p+1]-d[i])*a[i]);
			}
		}
	}
	for(register int i=0;i<=k;++i)ans=min(ans,dp[n+1][i]);
	printf("%d",ans);
	return 0;
}