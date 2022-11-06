#include<stdio.h>
int dp[100002],f[100002],cnt[100002],n,m;
char c[100002];long long ans;
int main(){
	scanf("%d%d%s",&n,&m,c+1);ans=m-1;
	for(int i=1;i<=n;i++)f[i]=i==1?1:c[i]==c[i-2]?f[i-1]:i-1,cnt[i]=cnt[i-1]+(i-1&&c[i]!=c[i-1]);
	for(int i=2;i<=n;i++){
		ans+=m-1;
		ans+=(m-1)*cnt[i];
		if(i-1&&c[i]!=c[i-1])ans+=(m-1)*(i-1)-(i-f[i]);
	}printf("%lld",ans);
}