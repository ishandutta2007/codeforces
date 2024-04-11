#include<bits/stdc++.h>
#define ll long long
#define N 110
using namespace std;
 
ll T,n,m,ans,num[N],cnt[N];
 
int main()
{
	ll i,j;
	cin>>T;
	while(T--)
	{
		ans=0;
		memset(cnt,0,sizeof(cnt));
		scanf("%lld%lld",&n,&m);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&num[i]);
			for(j=0;j<m;j++) if((1 << j)&num[i]) cnt[j]++;
		}
		for(i=0;i<m;i++)
		{
			if(cnt[i]>n/2) ans|=(1 << i);
		}
		printf("%lld\n",ans);
	}
}