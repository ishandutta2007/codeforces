#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int dp[1<<20],n,im[20][20],ans=0,T,cnt[1<<20],sum,pr;
char a[100005],b[100005];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		ans=0;
		scanf("%d",&n);memset(im,0,sizeof(im));
		scanf("%s%s",a+1,b+1);
		for(int i=1;i<=n;i++)
		{
			if(a[i]==b[i])continue;
			if(a[i]>b[i])
			{
				printf("-1\n");
				goto tag;
			}
			im['t'-a[i]]['t'-b[i]]=1;
		}
		for(int i=19;i>0;i--)
		{
			pr=i;
			for(int j=i-1;j>=0;j--)
			{
				if(im[i][j]==1)
				{
					pr=j;
					break;
				}
			}
			if(pr==i)continue;
			ans++;
			for(int j=0;j<i;j++)if(im[i][j]==1)im[pr][j]=1;
		}
		printf("%d\n",ans);
		tag:;
	}
	return 0;
}