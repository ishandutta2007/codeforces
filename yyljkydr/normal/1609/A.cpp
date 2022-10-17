#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int T;

int n,a[N];

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		long long pw=1;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			while(a[i]%2==0)
				pw=pw*2,a[i]=a[i]/2;
		}
		sort(a+1,a+n+1);
		long long ans=0;
		for(int i=1;i<n;i++)
			ans+=a[i];
		ans+=a[n]*pw;
		printf("%lld\n",ans);
	}
}