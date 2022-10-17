#include <cstdio>
const int N=3e5+10;
int T,n,ans,a[N],dp[N];
void cmax(int &x,int y){if(x<y)x=y;}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n),ans=0;
		for(int i=0;i<n;++i)scanf("%d",&a[i]);
		for(int i=0;i<n;++i){
			dp[i]=1;
			for(int j=i-1;i-j<300&&~j;--j)if((a[j]^i)<(a[i]^j))cmax(dp[i],dp[j]+1);
			cmax(ans,dp[i]);
		}
		printf("%d\n",ans);
	}
	return 0;
}