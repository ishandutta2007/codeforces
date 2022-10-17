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
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		long long ans=-1e18;
		for(int i=n;i>=max(1,n-250);i--)
			for(int j=i-1;j>=max(1,n-250);j--)
				ans=max(ans,1ll*i*j-k*(a[i]|a[j]));
		printf("%lld\n",ans);
	}
}