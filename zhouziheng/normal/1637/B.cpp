#include<cstdio>

using namespace std;

int a[200];

int main()
{
	int T=0;scanf("%d",&T);
	while(T--)
	{
		int n=0;scanf("%d",&n);for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		long long ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
			{
				ans+=j-i+1;for(int k=i;k<=j;k++)if(!a[k])ans++;
			}
		}
		printf("%lld\n",ans);
	}
}