#include <cstdio>
#include <cmath>
int n,p,now;
long long sum,dp[200010];
int main(){
	scanf("%d %d",&n,&p);
	dp[n]=1;
	for(register int i=n;i>1;--i){
		dp[i]+=sum,dp[i]%=p,sum+=dp[i],sum%=p;
		for(register int j=n;j>1;--j){
			now=i/j;
			if(i/(j-1)==now){
				int nxt=(int)ceil((double)i/(now+1));
				dp[now]=(dp[now]+dp[i]*(j-nxt))%p;;
				j=nxt+1;
			}
			else dp[now]=(dp[now]+dp[i])%p;
		}
	}
	dp[1]+=sum;
	printf("%lld",dp[1]%p);
	return 0;
}