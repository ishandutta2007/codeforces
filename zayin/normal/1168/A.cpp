#include<bits/stdc++.h>
#define maxn 300050
using namespace std;
typedef long long LL;

int n,m,a[maxn];

int dp[maxn];

void init()	{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;++i)
		scanf("%d",a+i);
}

bool judge(int x)	{
	for (int i=1;i<=n;++i)	{
		if (a[i]+x>=m)	{
			int u=a[i],d=(a[i]+x)%m;
			if (dp[i-1]<=d)
				dp[i]=dp[i-1];
			else
				dp[i]=max(u,dp[i-1]);
		} else	{
			if (a[i]+x<dp[i-1])	return 0;
			dp[i]=max(a[i],dp[i-1]);
		}
	}
}

void solve()	{
	int l=0,r=m-1;
	while (l<r)	{
		int mid=(l+r)>>1;
		if (judge(mid))
			r=mid;
		else
			l=mid+1;
	}
	printf("%d\n",l);
}

int main()	{
	init();
	solve();
	return 0;
}