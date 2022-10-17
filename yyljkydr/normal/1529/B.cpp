#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int T,n,k;

int a[N];

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		int mn=0x7fffffff;
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]>0)
				break;
			if(i>=2&&a[i]-a[i-1]<mn)
				mn=a[i]-a[i-1];
			ans++;
		}
		for(int i=1;i<=n;i++)
			if(a[i]>0&&a[i]<=mn)
			{
				ans++;
				break;
			}
		printf("%d\n",ans);
	}
}