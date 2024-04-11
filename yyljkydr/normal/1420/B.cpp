#include<bits/stdc++.h>
using namespace std;

const int N=5e5+1e3+7;

int T,n,a[N],cnt[31];

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(int i=0;i<30;i++)
			cnt[i]=0;
		for(int i=1;i<=n;i++)
			for(int j=29;j>=0;j--)
				if(a[i]&(1<<j))
				{
					cnt[j]++;
					break;
				}
		long long ans=0;
		for(int j=0;j<30;j++)
			ans+=1ll*cnt[j]*(cnt[j]-1)/2;
		printf("%lld\n",ans);
	}
}