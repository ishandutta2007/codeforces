#include<bits/stdc++.h>
#define ll long long
#define N 100100
using namespace std;

ll T,n,a,b,ans,num[N],cnt[2];

int main()
{
	ll i,j,p,q,res;
	cin>>T;
	while(T--)
	{
		cnt[0]=cnt[1]=0;
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&num[i]);
			num[i]&=1;
			cnt[num[i]]++;
		}
		if(max(cnt[0],cnt[1])>(n+1)/2)
		{
			puts("-1");
			continue;
		}
		if(cnt[0]==cnt[1])
		{
			p=q=res=0;
			for(i=1;i<=n;i++)
			{
				if(num[i]) q++;
				else p++;
				if(i&1) res+=abs(p-(i+1)/2);
				else res+=abs(p-i/2);
			}
			ans=res,p=q=res=0;
			for(i=1;i<=n;i++)
			{
				if(num[i]) q++;
				else p++;
				res+=abs(p-i/2);
			}
			ans=min(ans,res);
			printf("%lld\n",ans);
		}
		else if(cnt[0]>cnt[1])
		{
			p=q=ans=0;
			for(i=1;i<=n;i++)
			{
				if(num[i]) q++;
				else p++;
				ans+=abs(p-(i+1)/2);
			}
			printf("%lld\n",ans);
		}
		else
		{
			p=q=ans=0;
			for(i=1;i<=n;i++)
			{
				if(num[i]) q++;
				else p++;
				ans+=abs(p-i/2);
			}
			printf("%lld\n",ans);
		}
	}
}