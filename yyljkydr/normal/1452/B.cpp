#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int T,n,a[N];

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		long long sum=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]),sum+=a[i];
		sort(a+1,a+n+1,greater<int>());
		long long ans=max(1ll*a[1]*(n-1),(sum+n-2)/(n-1)*(n-1))-sum;
		printf("%lld\n",ans);
	}
}