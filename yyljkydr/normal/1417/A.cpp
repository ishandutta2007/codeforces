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
		sort(a+1,a+n+1);
		int ans=0;
		for(int i=2;i<=n;i++)
			ans+=(k-a[i])/a[1];
		printf("%d\n",ans);
	}
}