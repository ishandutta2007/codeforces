#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int T,n;

int a[N];

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		long long ans=0;
		for(int i=1;i<n;i++)
			ans=max(ans,1ll*max(a[i],a[i+1])*min(a[i],a[i+1]));
		printf("%lld\n",ans);
	}
}