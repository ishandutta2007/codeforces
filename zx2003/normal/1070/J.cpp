#include<cstdio>
int n,m,k,dp[200001],p[27],t;
long long ans,f;
char s[200011];
int main()
{
	scanf("%d",&t);
	for(int iii=1;iii<=t;iii++)
	{
	scanf("%d%d%d",&n,&m,&k);
	scanf("%s",s+1);
	ans=1ll*n*m;
	for(int i=0;i<=25;i++)p[i]=0;
	for(int i=1;i<=k;i++)p[s[i]-'A']++;
	for(int i=0;i<=25;i++)if(p[i]>0)
	{
		for(int j=1;j<=k;j++)dp[j]=0;
		dp[0]=dp[p[(i==0)]]=true;
		int hh=(i==0);
		hh++;
		for(int j=hh;j<=25;j++)if(j!=i)
		{
			for(int ii=k-p[j];ii>=0;ii--)if(dp[ii]>0)dp[ii+p[j]]=true;
		}
		for(int j=0;j<=k;j++)if((j<=n)&&(j+p[i]>=n)&&(dp[j]))
		{
			f=1ll*(n-j)*(m-k+p[i]+j);
			if(ans>f)ans=f;
		}
	}
	if(ans<0)ans=0;
	printf("%I64d\n",ans);
	}
}