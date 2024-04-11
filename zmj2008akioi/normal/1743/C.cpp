#include <cstdio>
const int N=2e5+10;
int T,n,a[N],dp[N][2];char s[N];
template<typename T>T max(T x,T y){return x>y?x:y;}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d %s",&n,s+1);
		for(int i=1;i<=n;++i)scanf("%d",&a[i]);
		for(int i=1;i<=n;++i){
			if(s[i]=='0')dp[i][0]=max(dp[i-1][0],dp[i-1][1]),dp[i][1]=0;
			else dp[i][0]=dp[i-1][0]+a[i-1],dp[i][1]=max(dp[i-1][0],dp[i-1][1])+a[i];
		}
		printf("%d\n",max(dp[n][0],dp[n][1]));
	}
	return 0;
}