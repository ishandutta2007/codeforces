#include<bits/stdc++.h>
using namespace std;

const int N=122;

int T,n,l,r,k;

int a[N];

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d%d",&n,&l,&r,&k);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		int ans=0;
		for(int i=1;i<=n;i++)
			if(k>=a[i]&&a[i]>=l&&a[i]<=r)
				k-=a[i],ans++;
		printf("%d\n",ans);
	}
}