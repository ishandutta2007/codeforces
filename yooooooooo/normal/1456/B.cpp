#include<cstdio>
#include<algorithm>
using namespace std;
int n,a[100005],sum[100005];
const int inf=1e9;
int main()
{
	scanf("%d",&n);
	if(n>100)
	{
		printf("1\n");
		return 0;
	}
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),sum[i]=sum[i-1]^a[i];
	int ans=inf;
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			for(int k=j+1;k<=n+1;k++)
			{
				if((sum[j-1]^sum[i-1])>(sum[k-1]^sum[j-1]))ans=min(ans,j-i-1+k-j-1);
			}
		}
	}
	if(ans==inf)printf("-1\n");
	else printf("%d\n",ans);
	return 0;
}