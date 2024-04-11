#include<bits/stdc++.h>
using namespace std;

const int N=1e6+1e3+7;

int n,k,a[N],T;

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n*k;i++)
			scanf("%d",&a[i]);
		int l=1,r=n*k;
		long long ans=0;
		for(int i=1;i<=k;i++)
		{
			int d=(n+1)>>1;
			r-=n-d+1;
			ans+=a[r+1];
		}
		printf("%lld\n",ans);
	}
}