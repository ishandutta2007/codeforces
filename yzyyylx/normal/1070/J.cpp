#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long
#define INF 0x3f3f3f3f3f3f3f3f
#define N 200100
using namespace std;

ll T,m,n,K,dy,cnt[30],ans;
char str[N];
bool dp[N]={1};

int main()
{
	ll i,j,k;
	cin>>T;
	while(T--)
	{
		memset(cnt,0,sizeof(cnt));
		ans=INF;
		scanf("%lld%lld%lld%s",&m,&n,&K,str+1);
		dy=K-m-n;
		if(m>n) swap(m,n);
		for(i=1;i<=K;i++) cnt[str[i]-'A'+1]++;
		for(i=1;i<=26;i++)
		{
			for(j=1;j<=n;j++) dp[j]=0;
			for(j=1;j<=26;j++)
			{
				if(i==j) continue;
				for(k=n;k>=cnt[j];k--) dp[k]|=dp[k-cnt[j]];
			}
			for(j=min(cnt[i],n);j>=0;j--)
			{
				if(!dp[n-j]) continue;
				ans=min(ans,j*max(0ll,cnt[i]-j-dy));
			}
		}
		printf("%lld\n",ans);
	}
}